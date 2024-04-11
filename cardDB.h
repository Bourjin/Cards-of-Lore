/*  Filename: cardDB.h
    Summary: header of card database
    Chris Sebring
    03/14/2023
*/

#include "card.h"
#include "deck.h"
#include <vector>

#ifndef CARDDB_H
#define CARDDB_H

class CardDB
{
  private:
    int totalCards = 100;
    Card empty;           /* 000 */
    Card goblin;          /* 001 */
    Card ritualist;       /* 002 */
    Card gnome_priest;    /* 003 */
    Card blade_master;    /* 004 */
    Card fairy;           /* 005 */
    Card sprite_forest;   /* 006 */
    Card sprite_fire;     /* 007 */
    Card sprite_water;    /* 008 */
    Card sprite_earth;    /* 009 */
    Card tradesman;       /* 010 */
    Card spirit_guide;    /* 011 */
    Card centaur;         /* 012 */
    Card phoenix;         /* 013 */
    Card mimic_chest;     /* 014 */
    Card witch;           /* 015 */
    Card elf_archer;      /* 016 */
    Card hydra;           /* 017 */
    Card troll;           /* 018 */
    Card koi_lunar;       /* 019 */
    Card koi_solar;       /* 020 */
    Card oni;             /* 021 */
    Card dwarf_bronze;    /* 022 */
    Card sapling;         /* 023 */
    Card stone_behemoth;  /* 024 */
    Card whelp_lava;      /* 025 */
    Card hungry_grass;    /* 026 */
    Card chimera;         /* 027 */
    Card rose_sprout;     /* 028 */
    Card black_widow;     /* 029 */
    Card whelp_oceans;    /* 030 */
    Card imp;             /* 031 */
    Card ghost;           /* 032 */
    Card amarok;          /* 033 */
    Card banshee;         /* 034 */
    Card eye_tyrant;      /* 035 */
    Card jiangshi;        /* 036 */
    Card wendigo;         /* 037 */
    Card mummy;           /* 038 */
    Card vine_wall;       /* 039 */
    Card wicked_flytrap;  /* 040 */
    Card poison_ivy;      /* 041 */
    Card forest_keeper;   /* 042 */
    Card life_tree;       /* 043 */
    Card fungal_carnage;  /* 044 */
    Card aka_manah;       /* 045 */
    Card vrock;           /* 046 */
    Card hezrou;          /* 047 */
    Card leviathan;       /* 048 */
    Card ugly_ogre;       /* 049 */
    Card amalgam;         /* 050 */
    Card high_charisma;   /* 051 */
    Card natural_growth;  /* 052 */
    Card arcane_bolt;     /* 053 */
    Card arcane_burst;    /* 054 */
    Card solar_flare;     /* 055 */
    Card spirit_plane;    /* 056 */
    Card delusion;        /* 057 */
    Card exchange;        /* 058 */
    Card last_stand;      /* 059 */
    Card polymorph;       /* 060 */
    Card fire_ball;       /* 061 */
    Card ethereal_totem;  /* 062 */
    Card green_thumb;     /* 063 */
    Card foreshadow;      /* 064 */
    Card dungeon_feast;   /* 065 */
    Card blood_bath;      /* 066 */
    Card village_emblem;  /* 067 */
    Card frost_bolt;      /* 068 */
    Card mind_control;    /* 069 */
    Card redirect;        /* 070 */
    Card counter_spell;   /* 071 */
    Card disarming_block; /* 072 */
    Card side_quests;     /* 073 */
    Card reanimate_rune;  /* 074 */
    Card freeloader;      /* 075 */
    Card liefs_hide;      /* 076 */
    Card eriks_wrath;     /* 077 */
    Card freydis_chain;   /* 078 */
    Card bjorns_plate;    /* 079 */
    Card cloth_garment;   /* 080 */
    Card shank;           /* 081 */
    Card merlins_robe;    /* 082 */
    Card short_sword;     /* 083 */
    Card onehand_axe;     /* 084 */
    Card brimstone_ring;  /* 085 */
    Card gold_ring;       /* 086 */
    Card hlin_amulet;     /* 087 */
    Card necro;           /* 088 */
    Card loot_pouch;      /* 089 */
    Card runelit_staff;   /* 090 */
    Card frozen_tuna;     /* 091 */
    Card excalibur;       /* 092 */
    Card scale_shield;    /* 093 */
    Card mitus_hand;      /* 094 */
    Card trav_attire;     /* 095 */
    Card aged_wand;       /* 096 */
    Card torch;           /* 097 */
    Card longbow;         /* 098 */
    Card battle_axe;      /* 099 */
    Card soulstone;       /* 100 */
  public:
    CardDB();
    ~CardDB() {}
    void setCardDB();
    string getType(int) const;
    Card getCDB_Card(int) const;
    void srchManip(string&);
    void cardCount(vector<int>&,vector<int>&);

    friend void loadDeckCase(CardDB,vector<Deck>&);
    friend void loadDeckCase_CPU(CardDB,vector<Deck>&,vector<Deck>&);
    friend void saveDeckCase(vector<Deck>);
    friend void saveDeckCase_CPU(vector<Deck>);
    friend void CDB_PrintInfo(CardDB);
    friend void viewCollection(CardDB,vector<Deck>&,int&);
    friend bool deckLobby(CardDB,vector<Deck>&,int&);
};

#endif //CARDDB_H