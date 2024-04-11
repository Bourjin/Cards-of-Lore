/* Filename: cardGame.cpp
   Summary: Plays a card game
   Author: Christopher Sebring
   Date: 03/23/2023
*/

#include "cardDB.h"
#include "exCardDB.h"
#include "deck.h"
#include "board.h"
#include <iostream>
#include <string>
using namespace std;

void mainMenu(int&,bool&);
void playGame(CardDB,ExCardDB,vector<Deck>&,vector<Deck>&);
bool chooseCPU(int&);
void credits();

int main()
{
  srand(time(NULL));
  CardDB CDB;
  ExCardDB EXCDB;
  vector<Deck> deckCase;
  vector<Deck> cpuDeckCase;
  int mmOpt;
  int deckNum = -1;
  bool MMdisp = true, MMfunc = true;
  CDB.setCardDB();
  EXCDB.setExCardDB();
  loadDeckCase(CDB,deckCase);
  loadDeckCase_CPU(CDB,deckCase,cpuDeckCase);

  do
  {
    if(MMfunc)
      mainMenu(mmOpt,MMdisp);
    MMfunc = true;
    switch(mmOpt)
    {
      case -4: credits();
               break;
      case -3: cout << " - View Extra Cards Collection -\n\n";
               break;
      case -2: ExCDB_PrintInfo(EXCDB);
               break;
      case -1: CDB_PrintInfo(CDB);
               break;
      case 1:  playGame(CDB,EXCDB,deckCase,cpuDeckCase);
               break;
      case 2:  viewCollection(CDB,deckCase,deckNum);
               break;
      case 3:  MMfunc = deckLobby(CDB,deckCase,deckNum);
               if(MMfunc == false)
                 mmOpt = 2;
               break;
    }
    if(mmOpt < 0)
      MMdisp = false;
  }while(mmOpt != 0);
  return 0;
}

void mainMenu(int& mmOpt, bool& MMdisp)
{
  mmOpt = 0;
  do
  {
    if(MMdisp)
    {
      cout << "\033[2J\033[1;1H";
      cout << endl <<
      "\t\t\t\t\t\t\t\t\t  ╓───────────┬───────────────────┬───────────╖\n"
      "\t\t\t\t\t\t\t\t\t  ║         ╔═╧═══════════════════╧═╗         ║\n"
      "\t\t\t\t\t\t\t\t\t  ║         ║  Cards of Antiquitus  ║         ║\n"
      "\t\t\t\t\t\t\t\t\t  ║         ╚═══════════════════════╝         ║\n"
      "\t\t\t\t\t\t\t\t\t  ║                                           ║\n"
      "\t\t\t\t\t\t\t\t\t  ║            ┌─────────────────┐            ║\n"
      "\t\t\t\t\t\t\t\t\t  ║            │  1 Play Game    │            ║\n"
      "\t\t\t\t\t\t\t\t\t  ║            └─────────────────┘            ║\n"
      "\t\t\t\t\t\t\t\t\t  ║            ┌─────────────────┐            ║\n"
      "\t\t\t\t\t\t\t\t\t  ║            │  2 Collection   │            ║\n"
      "\t\t\t\t\t\t\t\t\t  ║            └─────────────────┘            ║\n"
      "\t\t\t\t\t\t\t\t\t  ║            ┌─────────────────┐            ║\n"
      "\t\t\t\t\t\t\t\t\t  ║            │  3 Deck Lobby   │            ║\n"
      "\t\t\t\t\t\t\t\t\t  ║            └─────────────────┘            ║\n"
      "\t\t\t\t\t\t\t\t\t  ║            ┌─────────────────┐            ║\n"
      "\t\t\t\t\t\t\t\t\t  ║            │  0 Exit Game    │            ║\n"
      "\t\t\t\t\t\t\t\t\t  ║            └─────────────────┘            ║\n"
      "\t\t\t\t\t\t\t\t\t  ╙───────────────────────────────────────────╜\n";
    }
    MMdisp = true;
    if(mmOpt < -3 || mmOpt > 3)
      cout << "\t\t\t\t\t\t\t\t\t\t\t\t  ** Invalid Option **\n";
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tEnter: ";
    cin >> mmOpt;
  }while(mmOpt < -3 || mmOpt > 3);
  return;
}

void playGame(CardDB CDB, ExCardDB EXCDB, vector<Deck>& deckCase, vector<Deck>& cpuDeckCase)
{
  Board theBoard;
  int deckNum, cpuDeckNum;

  do
  {
    cout << "\033[2J\033[1;1H" << endl;
    cout << "\n == Choose Your Deck ==\n\n";
    for(int i = 0; i < deckCase.size(); i++)
      cout << i+1 << ") " << deckCase[i].getDeckName() << endl << endl;
    cout << "                        Main Menu - Enter 0\n\n";
    deckNum = -218;
    do
    {
      if(deckNum != -218)
      {
        if(deckNum < deckCase.size()-1)
          cout << "** Invalid Deck Number **\n\n";
        else if(deckCase[deckNum-1].getCardAmt() < 25)
        {
          cout << "** The deck must have 25 cards to play **\n\n";
          cout << deckCase[deckNum-1].getCardAmt() << endl << endl;
        } 
      }
      cout << "Deck Number: ";
      cin >> deckNum;
      if (deckNum == 0)
        return;
    }while(deckCase[deckNum-1].getCardAmt() < 25 ||
           deckNum > deckCase.size() || deckNum < 1);
  }while (!chooseCPU(cpuDeckNum));
  theBoard.deck_copy(deckCase[deckNum-1],true);
  theBoard.deck_copy(cpuDeckCase[cpuDeckNum-1],false);
  theBoard.gameplay(CDB,EXCDB);
  cout << endl;
  cin >> deckNum;
  return;
}

bool chooseCPU(int& cpuDeckNum)
{
  int option;
  cout << "================================================\n\n"
       << "  --   Choose a deck for your opponent   --\n\n"
       << "       1. Vir\n\n"
       << "       2. ---\n\n"
       << "       3. ---\n\n"
       << "       4. ---                         Main Menu\n\n"
       << "       5. ---                          Enter 0\n\n"
       << "================================================\n\n";
  do
  {
    cout << "                Deck: ";
    cin >> option;
    cout << "\n\n";
    if(option < 0 || option > 1)
      cout << "        == Invalid Deck ==\n\n";
    else if(option > 0 && option <= 1)
    {
      cpuDeckNum = option;
      return true;
    }
  }while(option != 0);
  return false;
}

void credits()
{
  char space;
  cout << "===========================\n\n"
       << " -- Coding Advice --\n\n"
       << "Jordon Kelly\n\n";
  cin >> space;
  return;
}