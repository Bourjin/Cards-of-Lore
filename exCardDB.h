/* Filename: exMinDB.h
   Summary: Header of exMinDB
   Author: Christopher Sebring
   Date: 03/14/2023
*/

#include "card.h"
#include <string>
#include <vector>
using namespace std;

#ifndef EXCARDDB_H
#define EXCARDDB_H

class ExCardDB
{
  private:
    int totalCards = 16;
    Card empty;           /* 000 */
    Card forest_treant;   /* 001 */
    Card ancient_oak;     /* 002 */
    Card deadly_rose;     /* 003 */
    Card toxic_rosebush;  /* 004 */
    Card dragon_lava;     /* 005 */
    Card dragon_oceans;   /* 006 */
    Card phoenix_ash;     /* 007 */
    Card yinyang_koi;     /* 008 */
    Card hydra_head;      /* 009 */
    Card chim_bear;       /* 010 */
    Card chim_lion;       /* 011 */
    Card chim_eagle;      /* 012 */
    Card fly;             /* 013 */
    Card skeleton;        /* 014 */
    Card charmed_zombie;  /* 015 */
    Card gold_statue;     /* 016 */
  public:
    ExCardDB();
    ~ExCardDB() {}
    void setExCardDB();
    string getType(int) const;
    Card getExCDB_Card(int) const;
    void cardCount(vector<int>&,vector<int>&);

    friend void ExCDB_PrintInfo(ExCardDB);
};

#endif //EXCARDDB_H