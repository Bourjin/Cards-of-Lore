/* FileName: board.cpp
   Summary: Implementation for the game board
   Author: Chris Sebring
   Date: 05/20/2023
*/

#include "board.h"
#include <cstdlib>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
using namespace chrono;
using namespace this_thread;

Board::Board()
{
    p1_health = 25;
    p1_mana = 0;
    p1_max_mana = 0;
    p1_deck_count = 0;
    p2_health = 25;
    p2_mana = 0;
    p2_max_mana = 0;
    p2_deck_count = 0;
    log_mode = false;
    p2_hand.setPlayer(2);
    aura = false;
}
void Board::gameplay(CardDB CDB, ExCardDB EXCDB)
{
  int turnNum = 0; //rand()%2;
  system("clear");
  fieldCard.setCardName("empty");
  do
  {
    if(turnNum == 0)
    { 
      if (p1_max_mana < 6)
        change_max_mana(1,1);
      change_mana(1,0);
      draw_card(p1_deck,p1_hand);
      update_board();
      player_turn(CDB);
    }
    if(turnNum == 1)
    {
      if (p2_max_mana < 6)
        change_max_mana(2,1);
      change_mana(2,0);
      draw_card(p2_deck,p2_hand);
      update_board();
      ai_turn(CDB);
    }
    if(turnNum == 0)
      turnNum = 1;
    else if(turnNum == 1)
      turnNum = 0;
    update_board();
  }while(turnNum > -1);
}
void Board::deck_copy(Deck caseDeck, bool me)
{
  vector<Card> caseVec;
  vector<Card> deckVec;
  CardNode* currPtr = caseDeck.getDeckHead();
  CardNode* prevPtr = nullptr;
  int randNum;

  // Creates case deck vector
  while(currPtr != NULL)
  {
    caseVec.push_back(currPtr->getCard());
    currPtr = currPtr->getNextCard();
  }

  // Creates random deck vector
  for(int i = 25; i > 1; i--)
  {
    randNum = rand()%i;
    deckVec.push_back(caseVec[randNum]);
    caseVec.erase(caseVec.begin()+randNum);
  }
  deckVec.push_back(caseVec[0]);

  // Creates new deck list
  for(int i = 0; i < 25; i++)
  {
    currPtr = new CardNode(deckVec[i]);
    if(i == 0)
    {
      prevPtr = currPtr;
      if (me)
        p1_deck.setDeckHead(currPtr);
      else
        p2_deck.setDeckHead(currPtr);
    }
    else
    {
      prevPtr->setNextCard(currPtr);
      currPtr->setPrevCard(prevPtr);
      prevPtr = currPtr;     
    }
  }
}
BoardDeck Board::getDeck(int player)
{
  if(player == 1)
    return p1_deck;
  return p2_deck;
}

void Board::player_turn(const CardDB& CDB)
{
  int action;
  int handNum;
  int fieldNum,fieldNum2;
  char leftRight;
  int player;
  int atk;
  string phrase;
  CardNode* p1_cursor;
  CardNode* p2_cursor;
  bool valid;
  
  do
  {
    cout << "\t\t\t\t\t\t\t\t\tAction: ";
    cin >> action;
    if(action < 0 || action > 3)
      cout << "\n ** Invalid Action **\n\n";
    else if(action == 1 && p1_hand.size() == 0)
    {
      cout << "\n ** Hand is Empty **\n\n";
      action = 0;
    }
    switch(action)
    {
      case 1: update_board();
              cout << "\n - Play A Card From Your Hand -\n\n";
              do
              {
                p1_cursor = p1_hand.getHeadPtr();
                cout << "Card: ";
                cin >> handNum;
                if (handNum == 0)
                {
                  action = 0;
                  break;
                }
                if (action != 0)
                {
                  for (int i = 1; i < handNum; i++)
                    p1_cursor = p1_cursor->getNextCard();
                  /*if (p1_cursor->getCard().getCardCost() > p1_mana)
                  {
                    cout << "\n ** Not enough mana **\n\n";
                    handNum = -218;
                  }*/
                }
              }while(handNum == -218);
              if (action != 0)
              {
                if(p1_field.size() != 0)
                {
                  cout << "\nLeft or Right ('l' or 'r'): ";
                  cin >> leftRight;
                }
                else
                  leftRight = 'l';
                p1_cursor = p1_hand.getHeadPtr();
                for(int i = 1; i < handNum; i++)
                  p1_cursor = p1_cursor->getNextCard();
                p1_mana = p1_mana - p1_cursor->getCard().getCardCost();
                phrase = "P1 Plays ";
                phrase += p1_cursor->getCard().getCardName();
                log(phrase);
                add_field(CDB,1,leftRight,p1_cursor->getCard());
                remove_hand(1,p1_cursor);
              }
              if(aura)
              {
                if(leftRight == 'l')
                  aura_check(CDB,p1_field[0]);
                else
                  aura_check(CDB,p1_field[p1_field.size()-1]);
              }
              break;
      case 2: update_board();
              cout << "\n - Attack With A Minion - \n\n";
              valid = false;
              do
              {
                cout << "Your Minion: ";
                cin >> fieldNum;
                if(fieldNum < 1 || fieldNum > p1_field.size())
                  cout << " ** Minion Doesn't Exsist **\n\n";
                else
                  valid = true;
              }while(!valid);
              valid = false;
              fieldNum--;
              log("P1 Attacks"); phrase = " ";
              phrase += p1_field[fieldNum].getCardName();
              phrase += " -> ";
              cout << "Attacking\n"
                      "1 Self\n"
                      "2 Enemy\n\n";
              do
              {
                cout << "Attack Who: ";
                cin >> player;
                if(player < 1 || player > 2)
                  cout << "** Invalid Player **\n\n";
                else
                  valid = true;
              }while(!valid);
              valid = false;
              if(player == 1)
              {
                do
                {
                  cout << "Attacks Self: ";
                  cin >> fieldNum2;
                  if(fieldNum2 < 0 || fieldNum2 > p1_field.size())
                    cout << " ** Character Doesn't Exsist **\n\n";
                  else
                    valid = true;
                }while(!valid);
                valid = false;
                fieldNum2--;
                if(fieldNum == -1)
                {
                  p1_health -= p1_field[fieldNum].getCardAtk();
                  phrase += "themself";
                }
                else
                {
                  if(p1_field[fieldNum].getCardAtk() != 0)
                  {
                    atk = -1 * p1_field[fieldNum].getCardAtk();
                    p1_field[fieldNum2].changeCardHth(atk);
                    if(p1_field[fieldNum2].getCardHth() > 0)
                      CDB_effects(CDB,1,false,p1_field[fieldNum2].getCardNum(),fieldNum2);
                  }
                  phrase += p1_field[fieldNum2].getCardName();
                  log(phrase);
                  phrase = " for ";
                  phrase += to_string(p1_field[fieldNum].getCardAtk());
                  phrase += " damage";
                  log(phrase);
                  if(p1_field[fieldNum2].getCardAtk() > 0)
                  {
                    atk = -1 * p1_field[fieldNum2].getCardAtk();
                    p1_field[fieldNum].changeCardHth(atk);
                    if(p1_field[fieldNum].getCardHth() > 0)
                      CDB_effects(CDB,1,false,p1_field[fieldNum].getCardNum(),fieldNum);
                  }
                  if(p1_field[fieldNum2].getCardHth() <= 0)
                    remove_field(CDB,1,fieldNum2+1);
                  if(p1_field[fieldNum].getCardHth() <= 0)
                    remove_field(CDB,1,fieldNum+1);
                }
              }
              else
              {
                do
                {
                  cout << "Attacks Enemy: ";
                  cin >> fieldNum2;
                  if(fieldNum2 < 0 || fieldNum2 > p2_field.size())
                    cout << " ** Enemy Doesn't Exist **\n\n";
                  else
                    valid = true;
                }while(!valid);
                valid = false;
                fieldNum2--;
                if(fieldNum2 == -1)
                {
                  p2_health -= p1_field[fieldNum].getCardAtk();
                  phrase += "P2";
                }
                else
                {
                  atk = -1 * p1_field[fieldNum].getCardAtk();
                  p2_field[fieldNum2].changeCardHth(atk);
                  if(p2_field[fieldNum2].getCardHth() <= 0)
                    remove_field(CDB,2,fieldNum2+1);
                  atk = -1 * p2_field[fieldNum2].getCardAtk();
                  p1_field[fieldNum].changeCardHth(atk);
                  if(p1_field[fieldNum].getCardHth() <= 0)
                    remove_field(CDB,1,fieldNum+1);
                  phrase += p2_field[fieldNum2].getCardName();
                }
              }
              break;
      case 3: break;
      case 4: draw_card(p1_deck,p1_hand);
              break;
      case 5: cout << " -- Kill A Minion --\n\n";
              cout << "Card: ";
              cin >> fieldNum;
              remove_field(CDB,1,fieldNum);
              break;
      default: break;
    }
    update_board();
  }while(action != 3);
  log("= P1 ENDS TURN =");
  return;
}
void Board::ai_turn(const CardDB& CDB)
{
  int here;
  do
  {
    //log("AI Action 1");
    cout << "AI Starts Turn\n";
    cout << "P2 Hand Size: " << p2_hand.size() << endl;
    cin >> here;
    update_board();
    cout << "Updates Board\n";
    sleep_for(seconds(2));
    log("CPU Action 1");
    update_board();
    sleep_for(seconds(2));
    log("CPU Action 2");
    update_board();
    sleep_for(seconds(2));
    log("CPU Action 3");
    update_board();
    sleep_for(seconds(2));
  }while(1==2);
  log("= P2 ENDS TURN =");
  return;
}

void Board::draw_card(BoardDeck& deck, Hand& hand)
{
  CardNode* tempPtr;
  string phrase;
  for(int i = 0; i < deck.getDrawCount(); i++)
  {
    tempPtr = deck.getDeckHead();
    deck.setDeckHead(deck.getDeckHead()->getNextCard());
    tempPtr->setNextCard(nullptr);
    if(hand.getPlayer() == 1)
      phrase = "P1 Draws";
    else
      phrase = "P2 Draws";
    log(phrase);
    if(!add_hand(hand,tempPtr))
    {
      phrase = "- ";
      phrase += tempPtr->getCard().getCardName();
      phrase += " was discarded";
      log(phrase);
    }
    deck.changeCardAmt('-');
  }
}
bool Board::add_hand(Hand& hand, CardNode* cardNode)
{
  if(hand.size() == HANDSIZE)
    return false;
  if(hand.size() == 0)
    hand.setHeadPtr(cardNode);
  else
  {
    CardNode* tempPtr = hand.getHeadPtr();
    while(tempPtr->getNextCard() != nullptr)
    {
      tempPtr = tempPtr->getNextCard();
    }
    tempPtr->setNextCard(cardNode);
    cardNode->setPrevCard(tempPtr);
  }
  hand.changeCardAmt('+');
  cout << "Hand Count: " << hand.size() << endl;
  return true;
}
bool Board::remove_hand(int player, CardNode* rmvCursor)
{
  if(player == 1)
  {
    if(p1_hand.size() == 0)
      return false;
    if(p1_hand.size() == 1)
      p1_hand.setHeadPtr(nullptr);
    else
    {
      if(rmvCursor == p1_hand.getHeadPtr())
      {
        p1_hand.setHeadPtr(rmvCursor->getNextCard());
        p1_hand.getHeadPtr()->setPrevCard(nullptr);
      }
      else if(rmvCursor->getNextCard() == nullptr)
        rmvCursor->getPrevCard()->setNextCard(nullptr);
      else
      {
        rmvCursor->getPrevCard()->setNextCard(rmvCursor->getNextCard());
        rmvCursor->getNextCard()->setPrevCard(rmvCursor->getPrevCard());
      }
    }
    p1_hand.changeCardAmt('-');
  }
  else
  {
    if(p2_hand.size() == 0)
      return false;
  }
  return true;
}
void Board::print_hand(int p)
{
  if (p == 1)
  {
    for(int i = 0; i < 13; i++)
    {
      switch(i)
      {
        case 0: print_line_hand(p,0,51);
                break;
        case 1: print_line_hand(p,52,21);
                break;
        case 2: print_line_hand(p,74,51);
                break;
        case 3: print_line_hand(p,126,21);
                break;
        case 4: print_line_hand(p,148,21);
                break;
        case 5: print_line_hand(p,170,21);
                break;
        case 6: print_line_hand(p,192,21);
                break;
        case 7: print_line_hand(p,214,21);
                break;
        case 8: print_line_hand(p,236,51);
                break;
        case 9: print_line_hand(p,288,21);
                break;
        case 10: print_line_hand(p,310,37);
                 break;
        case 11: print_line_hand(p,348,25);
                 break;
        case 12: print_line_hand(p,374,51);
                 break;
        default: cout << "** board.cpp/ print_p1_hand() default **\n\n";
      }
      cout << endl;
    }
  }
  if (p == 2)
  {
    for(int i = 0; i < 13; i++)
    {
      switch(i)
      {
        case 0: print_line_hand(p,0,51);
                break;
        case 1: print_line_hand(p,52,21);
                break;
        case 2: print_line_hand(p,74,21);
                break;
        case 3: print_line_hand(p,96,21);
                break;
        case 4: print_line_hand(p,118,21);
                break;
        case 5: print_line_hand(p,140,21);
                break;
        case 6: print_line_hand(p,162,21);
                break;
        case 7: print_line_hand(p,184,21);
                break;
        case 8: print_line_hand(p,206,21);
                break;
        case 9: print_line_hand(p,228,21);
                break;
        case 10: print_line_hand(p,250,21);
                 break;
        case 11: print_line_hand(p,272,21);
                 break;
        case 12: print_line_hand(p,294,51);
                 break;
        default: cout << "** board.cpp/ print_p2_hand() default **\n\n";
      }
      cout << endl;
    }
  }
  cout << endl;
}
void Board::print_line_hand(int p, int start, int end)
{
  int s;
  if(p == 1)
  {
    if(p1_hand.size() == 0)
    {
      print_spaces(97);
      return;
    }
    CardNode* cursor = p1_hand.getHeadPtr();
    if(p1_hand.size() == 1)
    {
      print_spaces(53);
      cout << cursor->getCard().getCardDisp().substr(start,end);
    }
    else if(p1_hand.size() == 2)
    {
      print_spaces(43);
      cout << cursor->getCard().getCardDisp().substr(start,end);
      cout << "   ";
      cursor = cursor->getNextCard();
      cout << cursor->getCard().getCardDisp().substr(start,end);
    }
    else if(p1_hand.size() == 3)
    {
      print_spaces(33);
      cout << cursor->getCard().getCardDisp().substr(start,end);
      cout << "   ";
      cursor = cursor->getNextCard();
      cout << cursor->getCard().getCardDisp().substr(start,end);
      cout << "   ";
      cursor = cursor->getNextCard();
      cout << cursor->getCard().getCardDisp().substr(start,end);
    }
    else if(p1_hand.size() == 4)
    {
      print_spaces(23);
      for(int i = 0; i < 4; i++)
      {
        cout << cursor->getCard().getCardDisp().substr(start,end);
        cursor = cursor->getNextCard();
        cout << "   ";
      }
    }
    else
    {
      print_spaces(13);
      for(int i = 0; i < 5; i++)
      {
        cout << cursor->getCard().getCardDisp().substr(start,end);
        cursor = cursor->getNextCard();
        if(i < 4)
          cout << "   ";
      }
    }
  }
  else
  {
    if(p2_hand.size() == 0)
      print_spaces(97);
    else if(p2_hand.size() == 1)
    {
      print_spaces(50);
      cout << cardBack().substr(start,end);
      print_spaces(50);
    }
    else if(p2_hand.size() == 2)
    {
      print_spaces(30);
      cout << cardBack().substr(start,end);
      cout << "   ";
      cout << cardBack().substr(start,end);
      print_spaces(30);
    }
    else if(p2_hand.size() == 3)
    {
      print_spaces(20);
      cout << cardBack().substr(start,end);
      cout << "   ";
      cout << cardBack().substr(start,end);
      cout << "   ";
      cout << cardBack().substr(start,end);
      print_spaces(20);
    }
    else if(p2_hand.size() == 4)
    {
      print_spaces(9);
      for(int i = 0; i < 4; i++)
      {
        cout << cardBack().substr(start,end);
        cout << "   ";
      }
      print_spaces(6);
    }
    else
    {
      for(int i = 0; i < 5; i++)
      {
        cout << cardBack().substr(start,end);
        if(i < 4)
          cout << "   ";
      }
    }
  }
}

void Board::print_mid_board()
{
  int actSpace;
  bool isFieldCard = true;
  
  if(fieldCard.getCardName() == "empty")
    isFieldCard = false;
  for(int i = 0; i < 13; i++)
  {
    cout << "\t\t║    ";
    switch(i)
    {
      case 0: cout << "╓─────────────────────────────────╖     ";
              if(isFieldCard)
                cout << fieldCard.getCardDisp().substr(0,51);
              else
                print_spaces(17);
              cout << "     ╓─────────────────────────────────╖";
              break;
      case 1: cout << "║           Board Info            ║     ";
              if(isFieldCard)
                cout << fieldCard.getCardDisp().substr(52,21);
              else
                print_spaces(17);
              cout << "     ║             Actions             ║";
              break;
      case 2: cout << "║  ─────────────────────────────  ║     ";
              if(isFieldCard)
                cout << fieldCard.getCardDisp().substr(74,51);
              else
                print_spaces(17);
              cout << "     ║  ─────────────────────────────  ║";
              break;
      case 3: cout << "║       You      |    Opponent    ║     ";
              if(isFieldCard)
                cout << fieldCard.getCardDisp().substr(126,21);
              else
                print_spaces(17);
              cout << "     ║  ";
              if(board_log.size() > 0)
              {
                actSpace = 31 - board_log[0].size();
                cout << board_log[0];
                print_spaces(actSpace);
              }
              else
                print_spaces(31);
              cout << "║";
              break;
      case 4: cout << "║                |                ║     ";
              if(isFieldCard)
                cout << fieldCard.getCardDisp().substr(148,21);
              else
                print_spaces(17);
              cout << "     ║  ";
              if(board_log.size() > 1)
              {
                actSpace = 31 - board_log[1].size();
                cout << board_log[1];
                print_spaces(actSpace);
              }
              else
                print_spaces(31);
              cout << "║";
              break;
      case 5: cout << "║   Deck:   ";
              if (p1_deck.getCardAmt() < 10)
                cout << " ";
              cout << p1_deck.getCardAmt() << "   |   Deck:   ";
              if(p2_deck.getCardAmt() < 10)
                cout << " ";
              cout << p2_deck.getCardAmt() << "   ║     ";
              if(isFieldCard)
                cout << fieldCard.getCardDisp().substr(170,21);
              else
                print_spaces(17);
              cout << "     ║  ";
              if(board_log.size() > 2)
              {
                actSpace = 31 - board_log[2].size();
                cout << board_log[2];
                print_spaces(actSpace);
              }
              else
                print_spaces(31);
              cout << "║";
              break;
      case 6: cout << "║                |                ║     ";
              if(isFieldCard)
                cout << fieldCard.getCardDisp().substr(192,21);
              else
                print_spaces(17);
              cout << "     ║  ";
              if(board_log.size() > 3)
              {
                actSpace = 31 - board_log[3].size();
                cout << board_log[3];
                print_spaces(actSpace);
              }
              else
                print_spaces(31);
              cout << "║";
              break;
      case 7: cout << "║   Health: ";
              if(p1_health < 10)
                cout << " ";
              cout << p1_health << "   |   Health: ";
              if(p2_health < 10)
                cout << " ";
              cout << p2_health << "   ║     ";
              if(isFieldCard)
                cout << fieldCard.getCardDisp().substr(214,21);
              else
                print_spaces(17);
              cout << "     ║  ";
              if(board_log.size() > 4)
              {
                actSpace = 31 - board_log[4].size();
                cout << board_log[4];
                print_spaces(actSpace);
              }
              else
                print_spaces(31);
              cout << "║";
              break;
      case 8: cout << "║                |                ║     ";
              if(isFieldCard)
                cout << fieldCard.getCardDisp().substr(236,51);
              else
                print_spaces(17);
              cout << "     ║  ";
              if(board_log.size() > 5)
              {
                actSpace = 31 - board_log[5].size();
                cout << board_log[5];
                print_spaces(actSpace);
              }
              else
                print_spaces(31);
              cout << "║";
              break;
      case 9: cout << "║   Mana:  ";
              cout << p1_mana << "/" << p1_max_mana << "   |   Mana:  ";
              cout << p2_mana << "/" << p2_max_mana << "   ║     ";
              if(isFieldCard)
                cout << fieldCard.getCardDisp().substr(288,21);
              else
                print_spaces(17);
              cout << "     ║  ";
              if(board_log.size() > 6)
              {
                actSpace = 31 - board_log[6].size();
                cout << board_log[6];
                print_spaces(actSpace);
              }
              else
                print_spaces(31);
              cout << "║";
              break;
      case 10: cout << "║  ─────────────────────────────  ║     ";
               if(isFieldCard)
                 cout << fieldCard.getCardDisp().substr(310,37);
               else
                 print_spaces(17);
               cout << "     ║  ";
               if(board_log.size() > 7)
               {
                 actSpace = 31 - board_log[7].size();
                cout << board_log[7];
                 print_spaces(actSpace);
               }
               else
                 print_spaces(31);
               cout << "║";
               break;
      case 11: cout << "║                                 ║     ";
               if(isFieldCard)
                 cout << fieldCard.getCardDisp().substr(348,25);
               else
                 print_spaces(17);
               cout << "     ║  ";
               if(board_log.size() > 8)
               {
                 actSpace = 31 - board_log[8].size();
                 cout << board_log[8];
                 print_spaces(actSpace);
               }
               else
                 print_spaces(31);
               cout << "║";
               break;
      case 12: cout << "╙─────────────────────────────────╜     ";
               if(isFieldCard)
                 cout << fieldCard.getCardDisp().substr(374,51);
               else
                 print_spaces(17);
               cout << "     ╙─────────────────────────────────╜";
               break;
      default: cout << "board.cpp/ void print_midboard() default\n\n";
    }
    cout << "    ║\n";
  }
}
void Board::change_health(int player, int amount)
{
  if(player == 1)
    p1_health += amount;
  else
    p2_health += amount;  
}
void Board::change_mana(int player, int amount)
{
  if(player == 1)
  {
    if (amount == 0)
      p1_mana = p1_max_mana;
    else
      p1_mana += amount;
  }
  else
  {
    if (amount == 0)
      p2_mana = p2_max_mana;
    else
      p2_mana += amount;
  }
  return;
}
void Board::change_max_mana(int player, int amount)
{
  if(player == 1)
    p1_max_mana += amount;
  else
    p2_max_mana += amount;  
}
vector<Card> Board::getField(int player)
{ 
  if(player == 1)
    return p1_field;
  return p2_field;
}
void Board::add_field(const CardDB& CDB, int p, char dir, Card card)
{   
  if(p == 1)
  {
    if(card.getCardType() == "Play" || card.getCardType() == "Effect")
      CDB_effects(CDB, p, true, card.getCardNum(),0);
    if(dir == 'l')
      p1_field.insert(p1_field.begin(),card);
    else if(dir == 'r')
      p1_field.push_back(card);
  }
  else if(p == 2)
  {
    if(dir == 'l')
      p2_field.insert(p2_field.begin(),card);
    else if(dir == 'r')
      p2_field.push_back(card);
  }
}
void Board::remove_field(const CardDB& CDB, int player, int element)
{
  Card tempCard;
  string phrase;
  vector<Card>::iterator pointer;

  element--;
  if(player == 1)
    tempCard = p1_field[element];
  else
    tempCard = p2_field[element];
  CDB_effects(CDB,player,false,tempCard.getCardNum(),0);
  if(player == 1)
  {
    pointer = p1_field.begin();
    for(int i = 0; i < element; i++)
      pointer++;
    p1_field.erase(pointer);
  }
  else
  {
    pointer = p2_field.begin();
    for(int i = 0; i < element; i++)
      pointer++;
    p2_field.erase(pointer);
  }
  phrase = tempCard.getCardName();
  phrase += " was destroyed";
  log(phrase);
  return;
}
void Board::print_field(int p)
{
  for(int i = 0; i < 13; i++)
  {
    cout << "\t\t║    ";
    switch(i)
    {
      case 0: print_line(p,0,51);
              break;
      case 1: print_line(p,52,21);
              break;
      case 2: print_line(p,74,51);
              break;
      case 3: print_line(p,126,21);
              break;
      case 4: print_line(p,148,21);
              break;
      case 5: print_line(p,170,21);
              break;
      case 6: print_line(p,192,21);
              break;
      case 7: print_line(p,214,21);
              break;
      case 8: print_line(p,236,51);
              break;
      case 9: print_line(p,288,21);
              break;
      case 10: print_line(p,310,37);
               break;
      case 11: cardStatLine(p);
               break;
      case 12: print_line(p,374,51);
               break;
      default: cout << "** board.cpp/ print_field() default **\n\n";
    }
    cout << "    ║\n";
  }
}
void Board::print_line(int p, int start, int end)
{
  int s;
  if(p == 1)
  {
    if(p1_field.size() == 0)
      print_spaces(97);
    else if(p1_field.size() == 1)
    {
      print_spaces(40);
      cout << p1_field[0].getCardDisp().substr(start,end);
      print_spaces(40);
    }
    else if(p1_field.size() == 2)
    {
      print_spaces(30);
      cout << p1_field[0].getCardDisp().substr(start,end);
      cout << "   ";
      cout << p1_field[1].getCardDisp().substr(start,end);
      print_spaces(30);
    }
    else if(p1_field.size() == 3)
    {
      print_spaces(20);
      cout << p1_field[0].getCardDisp().substr(start,end);
      cout << "   ";
      cout << p1_field[1].getCardDisp().substr(start,end);
      cout << "   ";
      cout << p1_field[2].getCardDisp().substr(start,end);
      print_spaces(20);
    }
    else if(p1_field.size() == 4)
    {
      print_spaces(10);
      for(int i = 0; i < 4; i++)
      {
        cout << p1_field[i].getCardDisp().substr(start,end);
        cout << "   ";
      }
      print_spaces(7);
    }
    else
    {
      for(int i = 0; i < 5; i++)
      {
        cout << p1_field[i].getCardDisp().substr(start,end);
        if(i < 4)
          cout << "   ";
      }
    }
  }
  else
  {
    if(p2_field.size() == 0)
      print_spaces(97);
    else if(p2_field.size() == 1)
    {
      print_spaces(40);
      cout << p2_field[0].getCardDisp().substr(start,end);
      print_spaces(40);
    }
    else if(p2_field.size() == 2)
    {
      print_spaces(30);
      cout << p2_field[0].getCardDisp().substr(start,end);
      cout << "   ";
      cout << p2_field[1].getCardDisp().substr(start,end);
      print_spaces(30);
    }
    else if(p2_field.size() == 3)
    {
      print_spaces(20);
      cout << p2_field[0].getCardDisp().substr(start,end);
      cout << "   ";
      cout << p2_field[1].getCardDisp().substr(start,end);
      cout << "   ";
      cout << p2_field[2].getCardDisp().substr(start,end);
      print_spaces(20);
    }
    else if(p2_field.size() == 4)
    {
      print_spaces(9);
      for(int i = 0; i < 4; i++)
      {
        cout << p2_field[i].getCardDisp().substr(start,end);
        cout << "   ";
      }
      print_spaces(6);
    }
    else
    {
      for(int i = 0; i < 5; i++)
      {
        cout << p2_field[i].getCardDisp().substr(start,end);
        if(i < 4)
          cout << "   ";
      }
    }
  }
}
void Board::cardStatLine(int p)
{
  int s;
  if(p == 1)
  {
    if(p1_field.size() == 0)
      print_spaces(97);
    else if(p1_field.size() == 1)
    {
      print_spaces(40);
      cout << "│ " << p1_field[0].getCardAtk()
           << p1_field[0].getCardDisp().substr(353,15)
           << p1_field[0].getCardHth() << " │";
      print_spaces(40);
    }
    else if(p1_field.size() == 2)
    {
      print_spaces(30);
      cout << "│ " << p1_field[0].getCardAtk()
           << p1_field[0].getCardDisp().substr(353,15)
           << p1_field[0].getCardHth() << " │";
      cout << "   ";
      cout << "│ " << p1_field[1].getCardAtk()
           << p1_field[1].getCardDisp().substr(353,15)
           << p1_field[1].getCardHth() << " │";
      print_spaces(30);
    }
    else if(p1_field.size() == 3)
    {
      print_spaces(20);
      cout << "│ " << p1_field[0].getCardAtk()
           << p1_field[0].getCardDisp().substr(353,15)
           << p1_field[0].getCardHth() << " │";
      cout << "   ";
      cout << "│ " << p1_field[1].getCardAtk()
           << p1_field[1].getCardDisp().substr(353,15)
           << p1_field[1].getCardHth() << " │";
      cout << "   ";
      cout << "│ " << p1_field[2].getCardAtk()
           << p1_field[2].getCardDisp().substr(353,15)
           << p1_field[2].getCardHth() << " │";
      print_spaces(20);
    }
    else if(p1_field.size() == 4)
    {
      print_spaces(10);
      for(int i = 0; i < 4; i++)
      {
        cout << "│ " << p1_field[i].getCardAtk()
           << p1_field[i].getCardDisp().substr(353,15)
           << p1_field[i].getCardHth() << " │";
        cout << "   ";
      }
      print_spaces(6);
    }
    else
    {
      for(int i = 0; i < 5; i++)
      {
        cout << "│ " << p1_field[i].getCardAtk()
           << p1_field[i].getCardDisp().substr(353,15)
           << p1_field[i].getCardHth() << " │";
        if(i < 4)
          cout << "   ";
      }
    }
  }
  else
  {
    if(p2_field.size() == 0)
      print_spaces(97);
    else if(p2_field.size() == 1)
    {
      print_spaces(40);
      cout << "│ " << p2_field[0].getCardAtk()
           << p2_field[0].getCardDisp().substr(353,367)
           << p2_field[0].getCardHth() << " │";
      print_spaces(40);
    }/*
    else if(p2_field.size() == 2)
    {
      print_spaces(30);
      cout << p2_field[0].getCardDisp().substr(start,end);
      cout << "   ";
      cout << p2_field[1].getCardDisp().substr(start,end);
      print_spaces(30);
    }
    else if(p2_field.size() == 3)
    {
      print_spaces(20);
      cout << p2_field[0].getCardDisp().substr(start,end);
      cout << "   ";
      cout << p2_field[1].getCardDisp().substr(start,end);
      cout << "   ";
      cout << p2_field[2].getCardDisp().substr(start,end);
      print_spaces(20);
    }
    else if(p2_field.size() == 4)
    {
      print_spaces(10);
      for(int i = 0; i < 4; i++)
      {
        cout << p2_field[i].getCardDisp().substr(start,end);
        cout << "   ";
      }
      print_spaces(6);
    }
    else
    {
      for(int i = 0; i < 5; i++)
      {
        cout << p2_field[i].getCardDisp().substr(start,end);
        if(i < 4)
          cout << "   ";
      }
    }*/
  }
}

void Board::printDeck(BoardDeck bDeck)
{
  CardNode* nodeTemp = bDeck.getDeckHead();
  for(int i = 0; i < 25; i++)
  {
    cout << nodeTemp->getCard().getCardName() << endl;
    nodeTemp = nodeTemp->getNextCard();
  }
}
string Board::cardBack()
{
  string cDisp;
  cDisp =  "┌───────────────┐\n";
  cDisp += "│               │\n";
  cDisp += "│               │\n";
  cDisp += "│               │\n";
  cDisp += "│               │\n";
  cDisp += "│               │\n";
  cDisp += "│               │\n";
  cDisp += "│               │\n";
  cDisp += "│               │\n";
  cDisp += "│               │\n";
  cDisp += "│               │\n";
  cDisp += "│               │\n";
  cDisp += "└───────────────┘\n";
  return cDisp;
}
void Board::print_spaces(int times)
{
  for(int s = 0; s < times; s++)
    cout << " ";
}
void Board::log(string phrase)
{
  action_log.push_back(phrase);
  if (board_log.size() > 9)
    board_log.erase(board_log.begin());
  board_log.push_back(phrase);
  update_board();
  return;
}

void Board::CDB_effects(const CardDB&  CDB, int p, bool play, int cardNum, int element)
{
  int player, choose_element;
  string phrase;
  bool valid = false;

  switch(cardNum)
  {
    case 1:
    case 31: return;
    default: break;
  }
  if (play)
  {
    switch(cardNum)
    {
      case 3: cout << "\nGnome Priest - Play Effect\n";
              if(getField(1).size() == 0 && getField(2).size() == 0)
                return;
              do
              {
                cout << "Use for Player: ";
                cin >> player;
                if(player < 1 || player > 2)
                  cout << "\n\n* Invalid Player *\n\n";
                else if(getField(player).size() == 0)
                  cout << "\n\n* That Field Is Empty *\n\n";
                else
                  valid = true;
              }while(!valid);
              valid = false;
              do
              {
                cout << "Field Card Number: ";
                cin >> choose_element;
                if(getField(player).size() < choose_element || element < 0)
                  cout << "\n\n* That Card Doesn't Exist *\n\n";
                else
                  valid = true;
              }while(!valid);
              choose_element--;
              if(player == 1)
              {
                p1_field[choose_element].changeCardMaxHth(2);
                p1_field[choose_element].changeCardHth(2);
              }
              if(player == 2)
              {
                p2_field[choose_element].changeCardMaxHth(2);
                p2_field[choose_element].changeCardHth(2);
              }
              break;
      case 12: aura = true;
               for(int i = 0; i < p1_field.size(); i++)
               {
                 if(p1_field[i].getCardMinType() == "Beast")
                 {
                   p1_field[i].changeCardMinAtk(2);
                   p1_field[i].changeCardAtk(2);
                 }
               }
               break;
      default: log("* No Card Effect *");
    }
  }
  else if (!play)
  {
    switch(cardNum)
    {
      case 2: add_field(CDB,p,'r',CDB.getCDB_Card(31));
              phrase = "P";
              phrase += to_string(p);
              phrase += "'s Ritualist summons Imp";
              log(phrase);
              break;
      case 4: switch(p)
              {
                case 1: p1_field[element].changeCardAtk(1);
                        break;
                case 2: p2_field[element].changeCardAtk(1);
                        break;
                default: log("* CDB_effects Default *");
              }
              break;
      case 5: log("* Fairy Effect *");
              break;
      case 6:
      case 7: 
      case 8: 
      case 9: log("* A Sprite Effect *");
              break;
      case 10: log("* Tradesman Effect *");
               break;
      case 11: log("* Spirit Guide Effect *");
               break;
      case 12: for(int i = 0; i < p1_field.size(); i++)
               {
                if(p1_field[i].getAura())
                  i = p1_field.size();
                else if(i == p1_field.size()-1)
                  aura = false;
               }
               for(int i = 0; i < p1_field.size(); i++)
               {
                 if(p1_field[i].getCardMinType() == "Beast")
                 {
                   p1_field[i].changeCardMinAtk(-2);
                   p1_field[i].changeCardAtk(-2);
                 }
               }
                 break;
      case 13: 
      case 14: 
      case 15: 
      case 16: 
      case 17: 
      case 18: 
      case 19: 
      case 20: 
      case 21: 
      case 22: 
      case 23: 
      case 24: 
      case 25: 
      case 26: 
      case 27: 
      case 28: 
      case 29: 
      case 30: 
      case 31: 
      case 32: 
      case 33: 
      case 34: 
      case 35: 
      case 36: 
      case 37: 
      case 38: 
      case 39: 
      case 40: 
      case 41: 
      case 42: 
      case 43: 
      case 44: 
      case 45: 
      case 46: 
      case 47: 
      case 48: 
      case 49: 
      case 50: 
      case 51: 
      case 52: 
      case 53: 
      case 54: 
      case 55: 
      case 56: 
      case 57: 
      case 58: 
      case 59: 
      case 60: 
      case 61: 
      case 62: 
      case 63: 
      case 64: 
      case 65: 
      case 66: 
      case 67: 
      case 68: 
      case 69: 
      case 70: 
      case 71: 
      case 72: 
      case 73: 
      case 74: 
      case 75: 
      case 76: 
      case 77: 
      case 78: 
      case 79: 
      case 80: 
      case 81: 
      case 82: 
      case 83: 
      case 84: 
      case 85: 
      case 86: 
      case 87: 
      case 88: 
      case 89: 
      case 90: 
      case 91: 
      case 92: 
      case 93: 
      case 94: 
      case 95: 
      case 96: 
      case 97: 
      case 98: 
      case 99: 
      case 100: 
      default: break;
    }
  }
  return;
}
void Board::ExCDB_effects(int p, int cardNum)
{
  switch(cardNum)
  {
    case 3: 
    case 4: 
    case 5: 
    case 6: 
    case 7: 
    case 8: 
    case 9: 
    case 10: 
    case 11: 
    case 12: 
    case 13: 
    case 14: 
    case 15: 
    case 16: 
    default: break;
  }
}
void Board::aura_check(const CardDB& CDB, Card& playedCard)
{ 
  // (12) Centaur - Beasts have +2 Atk
  for(int i = 0; i < p1_field.size(); i++)
  {
    if(p1_field[i].getCardNum() == 12 && currentCard.getCardMinType() == "Beast")
    {
      playedCard.changeCardMinAtk(2);
      playedCard.changeCardAtk(2);
    }
  }
  return;
}

void Board::update_board()
{
  //cout << "\033[2J\033[1;1H";
  if(p1_mana < 0)
    p1_mana = 0;
  if(p2_mana < 0)
    p2_mana = 0;
  system("clear");
  //print_hand(2);
  cout <<
  "\t\t╔═════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n"
  "\t\t║                                                                                                         ║\n";
  print_field(2);
  cout<<
  "\t\t║                                                                                                         ║\n";
  print_mid_board();
  cout <<
  "\t\t║                                                                                                         ║\n";
  print_field(1);
  cout <<
  "\t\t║                                                                                                         ║\n"
  "\t\t╚═════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
  cout << "\t\t\t\t\t\t\t\t\t _______________________________________________\n"
          "\t\t\t\t\t\t\t\t\t|                                               |\n"
          "\t\t\t\t\t\t\t\t\t|                    Actions                    |\n"
          "\t\t\t\t\t\t\t\t\t|                                               |\n"
          "\t\t\t\t\t\t\t\t\t|     1 - Play a card from your hand            |\n"
          "\t\t\t\t\t\t\t\t\t|     2 - Attack with a card from your field    |\n"
          "\t\t\t\t\t\t\t\t\t|     3 - End Turn                              |\n"
          "\t\t\t\t\t\t\t\t\t|                                               |\n"
          "\t\t\t\t\t\t\t\t\t|     0 - Return to Action Selection            |\n"
          "\t\t\t\t\t\t\t\t\t|_______________________________________________|\n\n";
  print_hand(1);
}
