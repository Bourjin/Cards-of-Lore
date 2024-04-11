/* FileName: hand.cpp
   Summary: Implementation for Hand
   Author: Chris Sebring
   Date: 6/6/2023
*/

#include "hand.h"
using namespace std;

Hand::Hand()
{
  player = 1;
  cardAmt = 0;
  headPtr = nullptr;
}

void Hand::changeCardAmt(char change)
{
  if(change == '+')
    cardAmt++;
  if(change == '-')
    cardAmt--;
}