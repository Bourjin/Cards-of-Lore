/* FileName: boardDeck.cpp
   Summary: Implementation for BoardDeck
   Author: Chris Sebring
   Date: 05/22/2023
*/

#include "boardDeck.h"
#include <iostream>
using namespace std;

BoardDeck::BoardDeck()
{
  player = 1;
  cardAmt = 25;
  drawCount = 1;
  headPtr = nullptr;
}

void BoardDeck::changeCardAmt(char change)
{
  if(change == '+')
    cardAmt++;
  if(change == '-')
    cardAmt--;
}

void BoardDeck::operator = (BoardDeck deck)
{
  cardAmt = deck.getCardAmt();
  headPtr = deck.getDeckHead();
}