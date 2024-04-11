/* FileName: cardNode.cpp
   Summary: Implementation for CardNode
   Author: Chris Sebring
   Date: 04/21/2023
*/

#include "cardNode.h"

CardNode::CardNode()
{
  nextCard = nullptr;
  prevCard = nullptr;
}
CardNode::CardNode(Card newCard)
{
  card = newCard;
}
CardNode::CardNode(Card newCard, CardNode* nPtr)
{
  card = newCard;
  nextCard = nPtr;
}
CardNode::CardNode(Card newCard, CardNode* nPtr, CardNode* pPtr)
{
  card = newCard;
  nextCard = nPtr;
  prevCard = pPtr;
}