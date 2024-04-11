/* FileName: hand.h
   Summary: Header for hand
   Author: Chris Sebring
   Date: 6/6/2023
*/

#include "card.h"
#include "cardNode.h"

#ifndef HAND_H
#define HAND_H

class Hand
{
  private:
    int player;
    int cardAmt;
    CardNode* headPtr;

  public:
    Hand();
    ~Hand(){}
    void setPlayer(int p) { player = p; }
    void setCardAmt(int cardA) { cardAmt = cardA; }
    void setHeadPtr(CardNode* hPtr) { headPtr = hPtr; }
    int getPlayer() { return player; }
    int size() { return cardAmt; }
    CardNode* getHeadPtr() { return headPtr; }
    void changeCardAmt(char);
};

#endif //HAND_H