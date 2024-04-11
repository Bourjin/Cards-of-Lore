/*  Filename card.cpp
    Summary: Implementation of card.h
    Chris Sebring
    03/14/2023
*/

#include "card.h"
#include <fstream>
using namespace std;

Card::Card()
{
  cardName = "* No Name *";
  cardType = "###";
  cardMinType = "* Not A Minion *";
  cardText = "* No Text *";
  cardNum = 0;
  cardCost = 0;
  cardAtk = 0;
  cardMinAtk = 0;
  cardHth = 0;
  cardMaxHth = 0;
}
void Card::setCardText(int card_num)
{
  int count = (card_num*2)+(card_num-1);
  ifstream fin;
  fin.open("cardText.txt");
  if (!fin)
    exit(0);
  for(int i = 1; getline(fin,cardText); i++)
    if(i == count)
      break;
  fin.close();
  return;
}
void Card::changeCardAtk(int amt)
{
  cardAtk += amt;
  if(cardAtk < cardMinAtk)
    cardAtk = cardMinAtk;
  else if(cardAtk < 0)
    cardAtk = 0;
  return;
}
void Card::changeCardMinAtk(int amt)
{
  cardMinAtk += amt;
  if(cardMinAtk < 0)
    cardMinAtk = 0;
  return;
}
void Card::changeCardHth(int amt)
{
  cardHth += amt;
  if(cardHth < 0)
    cardHth = 0;
  return;
}
void Card::operator = (Card card)
{
  cardDisp = card.cardDisp;
  cardName = card.cardName;
  cardType = card.cardType;
  cardMinType = card.cardMinType;
  cardClass = card.cardClass;
  cardText = card.cardText;
  cardCost = card.cardCost;
  cardNum = card.cardNum;
  cardAtk = card.cardAtk;
  cardHth = card.cardHth;
  cardMaxHth = card.cardMaxHth;
}