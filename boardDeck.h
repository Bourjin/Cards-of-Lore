/* FileName: boardDeck.h
   Summary: Header for BoardDeck
   Author: Chris Sebring
   Date: 05/12/2023
*/

#include "card.h"
#include "cardNode.h"

#ifndef BOARDDECK_H
#define BOARDDECK_H

class BoardDeck
{
  private:
    int player;
    int cardAmt;
    int drawCount;
    CardNode* headPtr;

  public:
    BoardDeck();
    ~BoardDeck(){}
    void setPlayer(int p) { player = p; }
    void setCardAmt(int cardA) { cardAmt = cardA; }
    void setDrawCount(int drawC) { drawCount = drawC; }
    void setDeckHead(CardNode* hPtr) { headPtr = hPtr; }
    int getPlayer() { return player; }
    int getCardAmt() { return cardAmt; }
    int getDrawCount() { return drawCount; }
    CardNode* getDeckHead() { return headPtr; }
    void changeCardAmt(char);
    void operator = (BoardDeck);
};

#endif //BOARDDECK_H