/*  Filename deck.cpp
    Summary: Implementation of deck.h
    Chris Sebring
    03/24/2023
*/
#include "deck.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Deck::Deck()
{
  deckNum = 0;
  cardAmt = 0;
  deckName = "- No Deck Name -";
  headPtr = NULL;
}
void Deck::setDeckName(string dName)
{
  ifstream fin;
  ofstream fout;
  string index;
  int counter;
  vector <string> deckText;

  switch(deckNum)
  {
    case 1: fin.open("deck1.txt");
            break;
    case 2: fin.open("deck2.txt");
            break;
    case 3: fin.open("deck3.txt");
            break;
    case 4: fin.open("deck4.txt");
            break;
    case 5: fin.open("deck5.txt");
            break;
    default: cout << "** deck.cpp/ setDeckName() fin default **\n\n";
  }
  getline(fin,index);
  deckText.push_back(dName);
  while(!fin.eof())
  {
    getline(fin,index);
    deckText.push_back(index);
  }
  fin.close();
  switch(deckNum)
  {
    case 1: fout.open("deck1.txt");
            break;
    case 2: fout.open("deck2.txt");
            break;
    case 3: fout.open("deck3.txt");
            break;
    case 4: fout.open("deck4.txt");
            break;
    case 5: fout.open("deck5.txt");
            break;
    default: cout << "** deck.cpp/ setDeckName() fout default **\n\n";
  }
  for(int i = 0; i < deckText.size(); i++)
  {
    fout << deckText[i];
    if(i < deckText.size()-1)
      fout << endl;
  }   
  fout.close();
  
  deckName = dName;
}
void Deck::changeCardAmt(int number)
{
  if(number == 1)
    cardAmt++;
  else if(number == -1)
    cardAmt--;
}
void Deck::addCard(Card card, bool fileWrite)
{
  ifstream fin;
  ofstream fout;
  string index;
  int counter;
  vector <string> deckText;
  CardNode *nodeTemp, *iter;

  switch(deckNum)
  {
    case 1: fin.open("deck1.txt");
            break;
    case 2: fin.open("deck2.txt");
            break;
    case 3: fin.open("deck3.txt");
            break;
    case 4: fin.open("deck4.txt");
            break;
    case 5: fin.open("deck5.txt");
            break;
    default: cout << "** deck.cpp/ addCard() fin default **\n\n";
  }
  while(!fin.eof())
  {
    getline(fin,index);
    deckText.push_back(index);
  }
  fin.close();
  deckText.push_back(to_string(card.getCardNum()));

  if(fileWrite)
  {
    switch(deckNum)
    {
      case 1: fout.open("deck1.txt");
              break;
      case 2: fout.open("deck2.txt");
              break;
      case 3: fout.open("deck3.txt");
              break;
      case 4: fout.open("deck4.txt");
              break;
      case 5: fout.open("deck5.txt");
              break;
      default: cout << "** deck.cpp/ addCard() fout default **\n\n";
    }
    for(int i = 0; i < deckText.size(); i++)
    {
      fout << deckText[i];
      if(i < deckText.size()-1)
        fout << endl;
    }
    fout.close();
  }
  nodeTemp = new CardNode(card,NULL);
  if(headPtr == NULL)
  {
    headPtr = nodeTemp;
    cardAmt++;
    return;
  }
  else
  {
    iter = headPtr;
    while(iter->getNextCard() != NULL)
        iter = iter->getNextCard();
    iter->setNextCard(nodeTemp);
    cardAmt++;
  }
}
void Deck::removeCard(int counter)
{
  if(cardAmt == 0)
    return;

  CardNode *currPtr;
  if(counter == 1)
  {
    if(cardAmt == 1)
    {
      delete headPtr;
      headPtr = NULL;
      cardAmt--;
    }
    currPtr = headPtr->getNextCard();
    delete headPtr;
    headPtr = currPtr;
    cardAmt--;
  }
  else if(counter > 1)
  {
    CardNode *prevPtr;
    currPtr = headPtr;
    for(int i = 2; i <= counter; i++)
    {
      prevPtr = currPtr;
      currPtr = currPtr->getNextCard();
      if(i == counter)
      {
        if(currPtr->getNextCard() != NULL)
        {
          CardNode* tempPtr = currPtr->getNextCard();
          prevPtr->setNextCard(tempPtr);
        }
        else
          prevPtr->setNextCard(NULL);
        delete currPtr;
        cardAmt--;
      }
    }
  }
}
void Deck::printDeckBasic()
{
  Card cardTemp;
  CardNode* tempPtr = headPtr;
  if(headPtr != NULL)
  {
    for(int i = 0; i < cardAmt; i++)
    {
      cardTemp = tempPtr->getCard();
      if((i+1) < 10)
        cout << " ";
      cout << " " << i+1 << ". ";
      cout << cardTemp.getCardName() << endl;
      tempPtr = tempPtr->getNextCard();
    }
  }
  else
    cout << "* Deck is Empty *";
  cout << endl << endl;
}
void Deck::deleteDeck()
{
  ofstream fout;
  if(cardAmt == 1)
    delete headPtr;
  else if(cardAmt > 1)
  {
    CardNode *prevPtr;
    CardNode *tempPtr = headPtr->getNextCard();
    delete headPtr;
    while(tempPtr != NULL)
    {
      prevPtr = tempPtr;
      tempPtr = tempPtr->getNextCard();
      delete prevPtr;
    }
  }
}
bool Deck::addCheck(Card card)
{
  if(cardAmt == 0 || cardAmt == 1)
    return true;
  
  int counter = 0;
  CardNode *currPtr = headPtr;
  CardNode *markPtr;
  while(currPtr != NULL)
  {
    if(card.getCardNum() == currPtr->getCard().getCardNum())
    {
      markPtr = currPtr;
      counter++;
    }
    /*if(counter == 2)
      return false;*/
    currPtr = currPtr->getNextCard();
  }
  
  return true;
}
void Deck::reset()
{
  deckNum = 0;
  cardAmt = 0;
  deckName = "- No Deck Name -";
  headPtr = NULL;  
}