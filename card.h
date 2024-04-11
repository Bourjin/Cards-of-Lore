/*  Filename: card.h
    Summary: header of card class
    Chris Sebring
    03/14/2023
*/

#include <string>
using namespace std;

#ifndef CARD_H
#define CARD_H

class Card
{
  private:
    string cardDisp;
    string cardName;
    string cardClass;
    string cardType;
    string cardMinType;
    string cardText;
    int cardCost;
    int cardNum;
    int cardAtk;
    int cardMinAtk;
    int cardHth;
    int cardMaxHth;
    bool aura;

  public:
    Card();
    ~Card() {}
    void setCardNum(int cNum)  { cardNum = cNum; }
    void setCardName(string cName) { cardName = cName; }
    void setCardDisp(string cDisp) { cardDisp = cDisp; }
    void setCardClass(string cClass) { cardClass = cClass; }
    void setCardType(string cType) { cardType = cType; }
    void setCardMinType(string cMinType) { cardMinType = cMinType; }
    void setCardCost(int cCost) { cardCost = cCost; }
    void setCardAtk(int cAtk) { cardAtk = cAtk; }
    void setCardMinAtk(int cAtk) { cardMinAtk = cAtk; }
    void setCardHth(int cHth) { cardHth = cHth; }
    void setCardMaxHth(int cHth) { cardMaxHth = cHth; }
    void changeCardAtk(int);
    void changeCardMinAtk(int);
    void changeCardHth(int);
    void changeCardMaxHth(int amt) { cardMaxHth += amt; }
    void setCardText(int);
    void setAura(bool yesNo) { aura = yesNo; }

    int getCardNum() const { return cardNum; }
    string getCardName() const { return cardName; }
    string getCardDisp() const { return cardDisp; }
    string getCardClass() const { return cardClass; }
    string getCardType() const { return cardType; }
    string getCardMinType() const { return cardMinType; }
    int getCardCost() const { return cardCost; }
    int getCardAtk() const { return cardAtk; }
    int getCardHth() const { return cardHth; }
    int getCardMaxHth() const { return cardMaxHth; }
    string getCardText() const { return cardText; }
    bool getAura() const { return aura; }
    void operator = (Card);
};

#endif //CARD_H