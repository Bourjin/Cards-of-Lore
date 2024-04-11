/* FileName: cardNode.h
   Summary: Header for cardNode
   Author: Chris Sebring
   Date: 04/21/2023
*/

#include "card.h"

#ifndef CARDNODE_H
#define CARDNODE_H

class CardNode
{
  private:
    Card card;
    CardNode* nextCard;
    CardNode* prevCard;
  public:
    CardNode();
    CardNode(Card);
    CardNode(Card,CardNode*);
    CardNode(Card,CardNode*,CardNode*);
    ~CardNode(){}
    void setCard(Card newCard) { card = newCard; }
    void setNextCard(CardNode* next) { nextCard = next; }
    void setPrevCard(CardNode* prev) { prevCard = prev; }
    Card getCard() { return card; }
    CardNode* getNextCard() { return nextCard; }
    CardNode* getPrevCard() { return prevCard; }
};

#endif //CARDNODE_H