/* Filename: deck.h
   Summary: Header of Deck class
   Author: Christopher Sebring
   Date: 03/24/2023
*/

#include "card.h"
#include "cardNode.h"
#include <string>
using namespace std;

#ifndef DECK_H
#define DECK_H

class Deck
{
  private:
    int deckNum;
    int cardAmt;
    string deckName;
    CardNode* headPtr;
    
  public:
    Deck();
    ~Deck(){}
    void setDeckNum(int dNum) { deckNum = dNum; }
    void setDeckName(string);
    void setDeckHead(CardNode *hptr) { headPtr = hptr; }
    void changeCardAmt(int);
    int getDeckNum() { return deckNum; }
    int getCardAmt() { return cardAmt; }
    string getDeckName() { return deckName; }
    CardNode* getDeckHead() { return headPtr; }
    void addCard(Card,bool);
    void removeCard(int);
    void printDeckBasic();
    void deleteDeck();
    bool addCheck(Card);
    void reset();
};

#endif // DECK_H