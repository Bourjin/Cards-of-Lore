/* FileName: board.h
   Summary: Header for the game board
   Author: Chris Sebring
   Date: 05/12/2023
*/

#include "cardDB.h"
#include "exCardDB.h"
#include "deck.h"
#include "boardDeck.h"
#include "hand.h"
#include <string>
#include <vector>
using namespace std;

#ifndef BOARD_H
#define BOARD_H

const int FIELDSIZE = 5;
const int HANDSIZE = 5;

class Board
{
  private:
    vector<Card> p1_field;
    BoardDeck p1_deck;
    Hand p1_hand;
    int p1_deck_count;
    int p1_health;
    int p1_mana;
    int p1_max_mana;
    vector<Card> p2_field;
    BoardDeck p2_deck;
    Hand p2_hand;
    int p2_deck_count;
    int p2_health;
    int p2_mana;
    int p2_max_mana;

    bool aura;
    Card fieldCard;
    vector<string> action_log;
    vector<string> board_log;
    bool log_mode;
    
  public:
    Board();
    ~Board(){}
    void gameplay(CardDB,ExCardDB);
    void deck_copy(Deck,bool);
    BoardDeck getDeck(int) const;
    void printDeck(BoardDeck);

    void player_turn(const CardDB&);
    void ai_turn(const CardDB&);
    void draw_card(BoardDeck&,Hand&);
    bool add_hand(Hand&,CardNode*);
    bool remove_hand(int,CardNode*);
    void print_hand(int);
    void print_line_hand(int,int,int);

    void set_field_card(Card card) { fieldCard = card; }
    vector<Card> getField(int);
    void add_field(const CardDB&,int,char,Card);
    void remove_field(const CardDB&, int,int);
    void print_field(int);
    void print_line(int,int,int);
    void cardStatLine(int);

    void change_health(int,int);
    void change_mana(int,int);
    void change_max_mana(int,int);
    void print_mid_board();

    string cardBack();
    void print_spaces(int);
    void log(string);
    void print_field_card(int,int);
    void CDB_effects(const CardDB&,int,bool,int,int);
    void ExCDB_effects(int,int);
    void aura_check(const CardDB&, Card&);
    void update_board();
};

#endif //BOARD_H