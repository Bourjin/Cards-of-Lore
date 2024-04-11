/*  Filename: cardDB.cpp
    Summary: implementation for card database
    Chris Sebring
    03/14/2023
*/

#include "cardDB.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

CardDB::CardDB(){}
void CardDB::setCardDB()
{
  string cDisp;

  /* Empty 000 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│     Empty     │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│   │       │   │\n";
  cDisp+= "└───┴───────┴───┘\n";
  empty.setCardDisp(cDisp);
  empty.setCardName("empty");

              // Minions

  /* Goblin 001 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│    Goblin     │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 1 │  Vir  │ 1 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  goblin.setCardDisp(cDisp);
  goblin.setCardName("Goblin");
  goblin.setCardClass(getType(0));
  goblin.setCardMinType(getType(6));
  goblin.setCardNum(1);
  goblin.setCardText(1);
  goblin.setCardCost(0);
  goblin.setCardAtk(1);
  goblin.setCardHth(1);
  goblin.setCardMaxHth(1);
  goblin.setAura(false);

  /* Ritualist 002 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Ritualist   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │ Demon │ 3 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  ritualist.setCardDisp(cDisp);
  ritualist.setCardName("Ritualist");
  ritualist.setCardClass(getType(0));
  ritualist.setCardType(getType(5));
  ritualist.setCardMinType(getType(10));
  ritualist.setCardNum(2);
  ritualist.setCardText(2);
  ritualist.setCardCost(3);
  ritualist.setCardAtk(2);
  ritualist.setCardHth(3);
  ritualist.setCardMaxHth(3);
  ritualist.setAura(false);

  /* Gnome Priest 003 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Gnome  Priest │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 1 │  Vir  │ 1 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  gnome_priest.setCardDisp(cDisp);
  gnome_priest.setCardName("Gnome Priest");
  gnome_priest.setCardClass(getType(0));
  gnome_priest.setCardType(getType(3));
  gnome_priest.setCardMinType(getType(6));
  gnome_priest.setCardNum(3);
  gnome_priest.setCardText(3);
  gnome_priest.setCardCost(1);
  gnome_priest.setCardAtk(1);
  gnome_priest.setCardHth(1);
  gnome_priest.setCardMaxHth(1);
  gnome_priest.setAura(false);

  /* Blade Master 004 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Blade  Master │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 5 │  Vir  │ 5 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  blade_master.setCardDisp(cDisp);
  blade_master.setCardName("Blade Master");
  blade_master.setCardClass(getType(0));
  blade_master.setCardType(getType(4));
  blade_master.setCardMinType(getType(6));
  blade_master.setCardNum(4);
  blade_master.setCardText(4);
  blade_master.setCardCost(5);
  blade_master.setCardAtk(5);
  blade_master.setCardHth(5);
  blade_master.setCardMaxHth(5);
  blade_master.setAura(false);

  /* Fairy 005 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│     Fairy     │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 1 │  Vir  │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  fairy.setCardDisp(cDisp);
  fairy.setCardName("Fairy");
  fairy.setCardClass(getType(0));
  fairy.setCardType(getType(4));
  fairy.setCardMinType(getType(6));
  fairy.setCardNum(5);
  fairy.setCardText(5);
  fairy.setCardCost(2);
  fairy.setCardAtk(1);
  fairy.setCardHth(2);
  fairy.setCardMaxHth(2);
  fairy.setAura(false);

  /* Forest Sprite 006 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Forest Sprite │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │ Umbra │ 1 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  sprite_forest.setCardDisp(cDisp);
  sprite_forest.setCardName("Forest Sprite");
  sprite_forest.setCardClass(getType(0));
  sprite_forest.setCardType(getType(4));
  sprite_forest.setCardMinType(getType(7));
  sprite_forest.setCardNum(6);
  sprite_forest.setCardText(6);
  sprite_forest.setCardCost(2);
  sprite_forest.setCardAtk(2);
  sprite_forest.setCardHth(1);
  sprite_forest.setCardMaxHth(1);
  sprite_forest.setAura(false);

  /* Fire Sprite 007 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Fire Sprite  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 4 │ Umbra │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  sprite_fire.setCardDisp(cDisp);
  sprite_fire.setCardName("Fire Sprite");
  sprite_fire.setCardClass(getType(0));
  sprite_fire.setCardType(getType(4));
  sprite_fire.setCardMinType(getType(7));
  sprite_fire.setCardNum(7);
  sprite_fire.setCardText(7);
  sprite_fire.setCardCost(4);
  sprite_fire.setCardAtk(4);
  sprite_fire.setCardHth(2);
  sprite_fire.setCardMaxHth(2);
  sprite_fire.setAura(false);

  /* Water Sprite 008 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Water  Sprite │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │ Umbra │ 4 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  sprite_water.setCardDisp(cDisp);
  sprite_water.setCardName("Water Sprite");
  sprite_water.setCardClass(getType(0));
  sprite_water.setCardType(getType(4));
  sprite_water.setCardMinType(getType(7));
  sprite_water.setCardNum(8);
  sprite_water.setCardText(8);
  sprite_water.setCardCost(3);
  sprite_water.setCardAtk(2);
  sprite_water.setCardHth(4);
  sprite_water.setCardMaxHth(4);
  sprite_water.setAura(false);

  /* Earth Sprite 009 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Earth  Sprite │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 4 │ Umbra │ 6 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  sprite_earth.setCardDisp(cDisp);
  sprite_earth.setCardName("Earth Sprite");
  sprite_earth.setCardClass(getType(0));
  sprite_forest.setCardType(getType(4));
  sprite_earth.setCardMinType(getType(7));
  sprite_earth.setCardNum(9);
  sprite_earth.setCardText(9);
  sprite_earth.setCardCost(5);
  sprite_earth.setCardAtk(4);
  sprite_earth.setCardHth(6);
  sprite_earth.setCardMaxHth(6);
  sprite_earth.setAura(false);

  /* Tradesman 010 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Tradesman   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 1 │  Vir  │ 4 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  tradesman.setCardDisp(cDisp);
  tradesman.setCardName("Tradesman");
  tradesman.setCardClass(getType(0));
  tradesman.setCardType(getType(3));
  tradesman.setCardMinType(getType(6));
  tradesman.setCardNum(10);
  tradesman.setCardText(10);
  tradesman.setCardCost(3);
  tradesman.setCardAtk(1);
  tradesman.setCardHth(4);
  tradesman.setCardMaxHth(4);
  tradesman.setAura(false);

  /* Spirit Guide 011 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Spirit  Guide │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 0 │ Umbra │ 5 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  spirit_guide.setCardDisp(cDisp);
  spirit_guide.setCardName("Spirit Guide");
  spirit_guide.setCardClass(getType(0));
  spirit_guide.setCardType(getType(4));
  spirit_guide.setCardMinType(getType(7));
  spirit_guide.setCardNum(11);
  spirit_guide.setCardText(11);
  spirit_guide.setCardCost(3);
  spirit_guide.setCardAtk(0);
  spirit_guide.setCardHth(5);
  spirit_guide.setCardMaxHth(5);
  spirit_guide.setAura(false);

  /* Centaur 012 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│    Centaur    │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 3 │ Beast │ 4 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  centaur.setCardDisp(cDisp);
  centaur.setCardName("Centaur");
  centaur.setCardClass(getType(0));
  centaur.setCardType(getType(4));
  centaur.setCardMinType(getType(8));
  centaur.setCardNum(12);
  centaur.setCardText(12);
  centaur.setCardCost(3);
  centaur.setCardAtk(3);
  centaur.setCardHth(4);
  centaur.setCardMaxHth(4);
  centaur.setAura(true);

  /* Phoenix 013 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│    Phoenix    │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 5 │ Beast │ 3 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  phoenix.setCardDisp(cDisp);
  phoenix.setCardName("Phoenix");
  phoenix.setCardClass(getType(0));
  phoenix.setCardType(getType(5));
  phoenix.setCardMinType(getType(8));
  phoenix.setCardNum(13);
  phoenix.setCardText(13);
  phoenix.setCardCost(4);
  phoenix.setCardAtk(5);
  phoenix.setCardHth(3);
  phoenix.setCardMaxHth(3);
  phoenix.setAura(false);

  /* Mimic Chest 014 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Mimic Chest  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 4 │       │ 4 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  mimic_chest.setCardDisp(cDisp);
  mimic_chest.setCardName("Mimic Chest");
  mimic_chest.setCardClass(getType(0));
  mimic_chest.setCardType(getType(4));
  mimic_chest.setCardMinType(getType(11));
  mimic_chest.setCardNum(14);
  mimic_chest.setCardText(14);
  mimic_chest.setCardCost(3);
  mimic_chest.setCardAtk(4);
  mimic_chest.setCardHth(4);
  mimic_chest.setCardMaxHth(4);
  mimic_chest.setAura(false);

  /* Witch 015 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│     Witch     │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │  Vir  │ 6 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  witch.setCardDisp(cDisp);
  witch.setCardName("Witch");
  witch.setCardClass(getType(0));
  witch.setCardType(getType(4));
  witch.setCardMinType(getType(6));
  witch.setCardNum(15);
  witch.setCardText(15);
  witch.setCardCost(4);
  witch.setCardAtk(2);
  witch.setCardHth(6);
  witch.setCardMaxHth(6);
  witch.setAura(false);

  /* Elf Archer 016 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Elf  Archer  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 4 │  Vir  │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  elf_archer.setCardDisp(cDisp);
  elf_archer.setCardName("Elf Archer");
  elf_archer.setCardClass(getType(0));
  elf_archer.setCardType(getType(3));
  elf_archer.setCardMinType(getType(6));
  elf_archer.setCardNum(16);
  elf_archer.setCardText(16);
  elf_archer.setCardCost(3);
  elf_archer.setCardAtk(4);
  elf_archer.setCardHth(2);
  elf_archer.setCardMaxHth(2);
  elf_archer.setAura(false);

  /* Hydra 017 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│     Hydra     │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│  * * * * * *  │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 4 │ Beast │ 5 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  hydra.setCardDisp(cDisp);
  hydra.setCardName("Hydra");
  hydra.setCardClass(getType(0));
  hydra.setCardType(getType(4));
  hydra.setCardMinType(getType(8));
  hydra.setCardNum(17);
  hydra.setCardText(17);
  hydra.setCardCost(6);
  hydra.setCardAtk(4);
  hydra.setCardHth(5);
  hydra.setCardMaxHth(5);
  hydra.setAura(false);

  /* Troll 018 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│     Troll     │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│  * * * * * *  │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 6 │  Vir  │ 6 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  troll.setCardDisp(cDisp);
  troll.setCardName("Troll");
  troll.setCardClass(getType(0));
  troll.setCardType(getType(4));
  troll.setCardMinType(getType(6));
  troll.setCardNum(18);
  troll.setCardText(18);
  troll.setCardCost(6);
  troll.setCardAtk(6);
  troll.setCardHth(6);
  troll.setCardMaxHth(6);
  troll.setAura(false);

  /* Lunar Koi 019 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Lunar Koi   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 1 │ Beast │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  koi_lunar.setCardDisp(cDisp);
  koi_lunar.setCardName("Lunar Koi");
  koi_lunar.setCardClass(getType(0));
  koi_lunar.setCardType(getType(3));
  koi_lunar.setCardMinType(getType(8));
  koi_lunar.setCardNum(19);
  koi_lunar.setCardText(19);
  koi_lunar.setCardCost(1);
  koi_lunar.setCardAtk(1);
  koi_lunar.setCardHth(2);
  koi_lunar.setCardMaxHth(2);
  koi_lunar.setAura(false);

  /* Solar Koi 020 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Solar Koi   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │ Beast │ 1 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  koi_solar.setCardDisp(cDisp);
  koi_solar.setCardName("Solar Koi");
  koi_solar.setCardClass(getType(0));
  koi_solar.setCardType(getType(3));
  koi_solar.setCardMinType(getType(8));
  koi_solar.setCardNum(20);
  koi_solar.setCardText(20);
  koi_solar.setCardCost(1);
  koi_solar.setCardAtk(2);
  koi_solar.setCardHth(1);
  koi_solar.setCardMaxHth(1);
  koi_solar.setAura(false);

  /* Oni 021 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│      Oni      │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│  * * * * * *  │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 7 │ Demon │ 7 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  oni.setCardDisp(cDisp);
  oni.setCardName("Oni");
  oni.setCardClass(getType(0));
  oni.setCardType(getType(4));
  oni.setCardMinType(getType(10));
  oni.setCardNum(21);
  oni.setCardText(21);
  oni.setCardCost(6);
  oni.setCardAtk(7);
  oni.setCardHth(7);
  oni.setCardMaxHth(7);
  oni.setAura(false);

  /* Bronze Dwarf 022 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Bronze  Dwarf │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 3 │  Vir  │ 5 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  dwarf_bronze.setCardDisp(cDisp);
  dwarf_bronze.setCardName("Bronze Dwarf");
  dwarf_bronze.setCardClass(getType(0));
  dwarf_bronze.setCardType(getType(4));
  dwarf_bronze.setCardMinType(getType(6));
  dwarf_bronze.setCardNum(22);
  dwarf_bronze.setCardText(22);
  dwarf_bronze.setCardCost(4);
  dwarf_bronze.setCardAtk(3);
  dwarf_bronze.setCardHth(5);
  dwarf_bronze.setCardMaxHth(5);
  dwarf_bronze.setAura(false);

  /* Sapling 023 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│    Sapling    │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 1 │ Plant │ 1 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  sapling.setCardDisp(cDisp);
  sapling.setCardName("Sapling");
  sapling.setCardClass(getType(0));
  sapling.setCardType(getType(4));
  sapling.setCardMinType(getType(9));
  sapling.setCardNum(23);
  sapling.setCardText(23);
  sapling.setCardCost(1);
  sapling.setCardAtk(1);
  sapling.setCardHth(1);
  sapling.setCardMaxHth(1);
  sapling.setAura(false);

  /* Stone Behemoth 024 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Stone  Behemoth│\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 6 │       │ 6 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  stone_behemoth.setCardDisp(cDisp);
  stone_behemoth.setCardName("Stone Behemoth");
  stone_behemoth.setCardClass(getType(0));
  stone_behemoth.setCardMinType(getType(11));
  stone_behemoth.setCardNum(24);
  stone_behemoth.setCardText(24);
  stone_behemoth.setCardCost(5);
  stone_behemoth.setCardAtk(6);
  stone_behemoth.setCardHth(6);
  stone_behemoth.setCardMaxHth(6);
  stone_behemoth.setAura(false);


  /* Lava Whelp 025 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Lava  Whelp  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 3 │       │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  whelp_lava.setCardDisp(cDisp);
  whelp_lava.setCardName("Lava Whelp");
  whelp_lava.setCardClass(getType(0));
  whelp_lava.setCardType(getType(4));
  whelp_lava.setCardMinType(getType(11));
  whelp_lava.setCardNum(25);
  whelp_lava.setCardText(25);
  whelp_lava.setCardCost(2);
  whelp_lava.setCardAtk(3);
  whelp_lava.setCardHth(2);
  whelp_lava.setCardMaxHth(2);
  whelp_lava.setAura(false);

  /* Hungry Grass 026 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Hungry  Grass │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 1 │ Plant │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  hungry_grass.setCardDisp(cDisp);
  hungry_grass.setCardName("Hungry Grass");
  hungry_grass.setCardClass(getType(0));
  hungry_grass.setCardType(getType(4));
  hungry_grass.setCardMinType(getType(9));
  hungry_grass.setCardNum(26);
  hungry_grass.setCardText(26);
  hungry_grass.setCardCost(2);
  hungry_grass.setCardAtk(1);
  hungry_grass.setCardHth(2);
  hungry_grass.setCardMaxHth(2);
  hungry_grass.setAura(false);

  /* Chimera 027 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│    Chimera    │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │ Beast │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  chimera.setCardDisp(cDisp);
  chimera.setCardName("Chimera");
  chimera.setCardClass(getType(0));
  chimera.setCardType(getType(3));
  chimera.setCardMinType(getType(8));
  chimera.setCardNum(27);
  chimera.setCardText(27);
  chimera.setCardCost(5);
  chimera.setCardAtk(2);
  chimera.setCardHth(2);
  chimera.setCardMaxHth(2);
  chimera.setAura(false);

  /* Rose Sprout 028 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Rose Sprout  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 1 │ Plant │ 1 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  rose_sprout.setCardDisp(cDisp);
  rose_sprout.setCardName("Rose Sprout");
  rose_sprout.setCardClass(getType(0));
  rose_sprout.setCardType(getType(4));
  rose_sprout.setCardMinType(getType(9));
  rose_sprout.setCardNum(28);
  rose_sprout.setCardText(28);
  rose_sprout.setCardCost(1);
  rose_sprout.setCardAtk(1);
  rose_sprout.setCardHth(1);
  rose_sprout.setCardMaxHth(1);
  rose_sprout.setAura(false);

  /* Black Widow 029 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Black Widow  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 1 │ Beast │ 1 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  black_widow.setCardDisp(cDisp);
  black_widow.setCardName("Black Widow");
  black_widow.setCardClass(getType(0));
  black_widow.setCardType(getType(4));
  black_widow.setCardMinType(getType(8));
  black_widow.setCardNum(29);
  black_widow.setCardText(29);
  black_widow.setCardCost(1);
  black_widow.setCardAtk(1);
  black_widow.setCardHth(1);
  black_widow.setCardMaxHth(1);
  black_widow.setAura(false);

  /* Oceans Whelp 030 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Oceans Whelp  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │       │ 3 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  whelp_oceans.setCardDisp(cDisp);
  whelp_oceans.setCardName("Oceans Whelp");
  whelp_oceans.setCardClass(getType(0));
  whelp_oceans.setCardType(getType(4));
  whelp_oceans.setCardMinType(getType(11));
  whelp_oceans.setCardNum(30);
  whelp_oceans.setCardText(30);
  whelp_oceans.setCardCost(2);
  whelp_oceans.setCardAtk(2);
  whelp_oceans.setCardHth(3);
  whelp_oceans.setCardMaxHth(3);
  whelp_oceans.setAura(false);

  /* Imp 031 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│      Imp      │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 1 │ Demon │ 1 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  imp.setCardDisp(cDisp);
  imp.setCardName("Imp");
  imp.setCardClass(getType(0));
  imp.setCardType(getType(3));
  imp.setCardMinType(getType(10));
  imp.setCardNum(31);
  imp.setCardText(31);
  imp.setCardCost(1);
  imp.setCardAtk(1);
  imp.setCardHth(1);
  imp.setCardMaxHth(1);
  imp.setAura(false);

  /* Ghost 032 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│     Ghost     │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 1 │ Umbra │ 1 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  ghost.setCardDisp(cDisp);
  ghost.setCardName("Ghost");
  ghost.setCardClass(getType(0));
  ghost.setCardType(getType(4));
  ghost.setCardMinType(getType(7));
  ghost.setCardNum(32);
  ghost.setCardText(32);
  ghost.setCardCost(1);
  ghost.setCardAtk(1);
  ghost.setCardHth(1);
  ghost.setCardMaxHth(1);
  ghost.setAura(false);

  /* Amarok 033 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Amarok the Wolf│\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │ Beast │ 3 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  amarok.setCardDisp(cDisp);
  amarok.setCardName("Amarok the Wolf");
  amarok.setCardClass(getType(0));
  amarok.setCardType(getType(4));
  amarok.setCardMinType(getType(8));
  amarok.setCardNum(33);
  amarok.setCardText(33);
  amarok.setCardCost(2);
  amarok.setCardAtk(2);
  amarok.setCardHth(3);
  amarok.setCardMaxHth(3);
  amarok.setAura(false);

  /* Banshee 034 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│    Banshee    │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 3 │ Umbra │ 1 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  banshee.setCardDisp(cDisp);
  banshee.setCardName("Banshee");
  banshee.setCardClass(getType(0));
  banshee.setCardType(getType(3));
  banshee.setCardMinType(getType(7));
  banshee.setCardNum(34);
  banshee.setCardText(34);
  banshee.setCardCost(2);
  banshee.setCardAtk(3);
  banshee.setCardHth(1);
  banshee.setCardMaxHth(1);
  banshee.setAura(false);


  /* Eye Tyrant 035 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Eye  Tyrant  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 4 │ Demon │ 3 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  eye_tyrant.setCardDisp(cDisp);
  eye_tyrant.setCardName("Eye Tyrant");
  eye_tyrant.setCardClass(getType(0));
  eye_tyrant.setCardType(getType(4));
  eye_tyrant.setCardMinType(getType(10));
  eye_tyrant.setCardNum(35);
  eye_tyrant.setCardText(35);
  eye_tyrant.setCardCost(4);
  eye_tyrant.setCardAtk(4);
  eye_tyrant.setCardHth(3);
  eye_tyrant.setCardMaxHth(3);
  eye_tyrant.setAura(false);

  /* Jiangshi 036 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Jiangshi    │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 6 │ Demon │ 3 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  jiangshi.setCardDisp(cDisp);
  jiangshi.setCardName("Jiangshi");
  jiangshi.setCardClass(getType(0));
  jiangshi.setCardType(getType(4));
  jiangshi.setCardMinType(getType(10));
  jiangshi.setCardNum(36);
  jiangshi.setCardText(36);
  jiangshi.setCardCost(5);
  jiangshi.setCardAtk(6);
  jiangshi.setCardHth(3);
  jiangshi.setCardMaxHth(3);
  jiangshi.setAura(false);

  /* Wendigo 037 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│    Wendigo    │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│  * * * * * *  │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 6 │ Umbra │ 6 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  wendigo.setCardDisp(cDisp);
  wendigo.setCardName("Wendigo");
  wendigo.setCardClass(getType(0));
  wendigo.setCardType(getType(4));
  wendigo.setCardMinType(getType(7));
  wendigo.setCardNum(37);
  wendigo.setCardText(37);
  wendigo.setCardCost(6);
  wendigo.setCardAtk(6);
  wendigo.setCardHth(6);
  wendigo.setCardMaxHth(6);
  wendigo.setAura(false);

  /* Mummy 038 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│     Mummy     │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │       │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  mummy.setCardDisp(cDisp);
  mummy.setCardName("Mummy");
  mummy.setCardClass(getType(0));
  mummy.setCardMinType(getType(11));
  mummy.setCardNum(38);
  mummy.setCardText(38);
  mummy.setCardCost(1);
  mummy.setCardAtk(2);
  mummy.setCardHth(2);
  mummy.setCardMaxHth(2);
  mummy.setAura(false);


  /* Vine Wall 039 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Vine Wall   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 0 │ Plant │ 7 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  vine_wall.setCardDisp(cDisp);
  vine_wall.setCardName("Vine Wall");
  vine_wall.setCardClass(getType(0));
  vine_wall.setCardType(getType(4));
  vine_wall.setCardMinType(getType(9));
  vine_wall.setCardNum(39);
  vine_wall.setCardText(39);
  vine_wall.setCardCost(4);
  vine_wall.setCardAtk(0);
  vine_wall.setCardHth(7);
  vine_wall.setCardMaxHth(7);
  vine_wall.setAura(false);

  /* Wicked Flytrap 040 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Wicked  Flytrap│\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 3 │ Plant │ 3 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  wicked_flytrap.setCardDisp(cDisp);
  wicked_flytrap.setCardName("Wicked Flytrap");
  wicked_flytrap.setCardClass(getType(0));
  wicked_flytrap.setCardType(getType(5));
  wicked_flytrap.setCardMinType(getType(9));
  wicked_flytrap.setCardNum(40);
  wicked_flytrap.setCardText(40);
  wicked_flytrap.setCardCost(3);
  wicked_flytrap.setCardAtk(3);
  wicked_flytrap.setCardHth(3);
  wicked_flytrap.setCardMaxHth(3);
  wicked_flytrap.setAura(false);

  /* Poison Ivy 041 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Poison Ivy   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │ Plant │ 1 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  poison_ivy.setCardDisp(cDisp);
  poison_ivy.setCardName("Poison Ivy");
  poison_ivy.setCardClass(getType(0));
  poison_ivy.setCardType(getType(4));
  poison_ivy.setCardMinType(getType(9));
  poison_ivy.setCardNum(41);
  poison_ivy.setCardText(41);
  poison_ivy.setCardCost(2);
  poison_ivy.setCardAtk(2);
  poison_ivy.setCardHth(1);
  poison_ivy.setCardMaxHth(1);
  poison_ivy.setAura(false);

  /* Forest Keeper 042 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Forest Keeper │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 5 │ Plant │ 5 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  forest_keeper.setCardDisp(cDisp);
  forest_keeper.setCardName("Forest Keeper");
  forest_keeper.setCardClass(getType(0));
  forest_keeper.setCardType(getType(3));
  forest_keeper.setCardMinType(getType(9));
  forest_keeper.setCardNum(42);
  forest_keeper.setCardText(42);
  forest_keeper.setCardCost(5);
  forest_keeper.setCardAtk(5);
  forest_keeper.setCardHth(5);
  forest_keeper.setCardMaxHth(5);
  forest_keeper.setAura(false);

  /* Tree of Life 043 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Tree of Life  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│  * * * * * *  │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 6 │ Plant │ 6 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  life_tree.setCardDisp(cDisp);
  life_tree.setCardName("Tree of Life");
  life_tree.setCardClass(getType(0));
  life_tree.setCardType(getType(4));
  life_tree.setCardMinType(getType(9));
  life_tree.setCardNum(43);
  life_tree.setCardText(43);
  life_tree.setCardCost(6);
  life_tree.setCardAtk(6);
  life_tree.setCardHth(6);
  life_tree.setCardMaxHth(6);
  life_tree.setAura(false);

  /* Funal Carnage 044 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Fungal  Carnage│\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 4 │ Plant │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  fungal_carnage.setCardDisp(cDisp);
  fungal_carnage.setCardName("Fungal Carnage");
  fungal_carnage.setCardClass(getType(0));
  fungal_carnage.setCardType(getType(5));
  fungal_carnage.setCardMinType(getType(9));
  fungal_carnage.setCardNum(44);
  fungal_carnage.setCardText(44);
  fungal_carnage.setCardCost(4);
  fungal_carnage.setCardAtk(4);
  fungal_carnage.setCardHth(2);
  fungal_carnage.setCardMaxHth(2);
  fungal_carnage.setAura(false);

  /* Aka Manah 045 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Aka Manah   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 4 │ Demon │ 3 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  aka_manah.setCardDisp(cDisp);
  aka_manah.setCardName("Aka Manah");
  aka_manah.setCardClass(getType(0));
  aka_manah.setCardType(getType(3));
  aka_manah.setCardMinType(getType(10));
  aka_manah.setCardNum(45);
  aka_manah.setCardText(45);
  aka_manah.setCardCost(5);
  aka_manah.setCardAtk(4);
  aka_manah.setCardHth(3);
  aka_manah.setCardMaxHth(3);
  aka_manah.setAura(false);

  /* Vrock 046 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│     Vrock     │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │ Demon │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  vrock.setCardDisp(cDisp);
  vrock.setCardName("Vrock");
  vrock.setCardClass(getType(0));
  vrock.setCardType(getType(4));
  vrock.setCardMinType(getType(10));
  vrock.setCardNum(46);
  vrock.setCardText(46);
  vrock.setCardCost(2);
  vrock.setCardAtk(2);
  vrock.setCardHth(2);
  vrock.setCardMaxHth(2);
  vrock.setAura(false);

  /* Hezrou 047 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│    Hezrou     │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 3 │ Demon │ 3 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  hezrou.setCardDisp(cDisp);
  hezrou.setCardName("Hezrou");
  hezrou.setCardClass(getType(0));
  hezrou.setCardType(getType(4));
  hezrou.setCardMinType(getType(10));
  hezrou.setCardNum(47);
  hezrou.setCardText(47);
  hezrou.setCardCost(3);
  hezrou.setCardAtk(3);
  hezrou.setCardHth(3);
  hezrou.setCardMaxHth(3);
  hezrou.setAura(false);

  /* Leviathan 048 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Leviathan   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│  * * * * * *  │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 7 │       │ 8 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  leviathan.setCardDisp(cDisp);
  leviathan.setCardName("Leviathan");
  leviathan.setCardClass(getType(0));
  leviathan.setCardType(getType(4));
  leviathan.setCardMinType(getType(11));
  leviathan.setCardNum(48);
  leviathan.setCardText(48);
  leviathan.setCardCost(6);
  leviathan.setCardAtk(7);
  leviathan.setCardHth(8);
  leviathan.setCardMaxHth(8);
  leviathan.setAura(false);

  /* Ugly Ogre 049 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Ugly Ogre   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 5 │       │ 5 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  ugly_ogre.setCardDisp(cDisp);
  ugly_ogre.setCardName("Ugly Ogre");
  ugly_ogre.setCardClass(getType(0));
  ugly_ogre.setCardMinType(getType(11));
  ugly_ogre.setCardNum(49);
  ugly_ogre.setCardText(49);
  ugly_ogre.setCardCost(4);
  ugly_ogre.setCardAtk(5);
  ugly_ogre.setCardHth(5);
  ugly_ogre.setCardMaxHth(5);
  ugly_ogre.setAura(false);

  /* Amalgam 050 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│    Amalgam    │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 3 │       │ 3 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  amalgam.setCardDisp(cDisp);
  amalgam.setCardName("Amalgam");
  amalgam.setCardClass(getType(0));
  amalgam.setCardType(getType(4));
  amalgam.setCardMinType(getType(11));
  amalgam.setCardNum(50);
  amalgam.setCardText(50);
  amalgam.setCardCost(3);
  amalgam.setCardAtk(3);
  amalgam.setCardHth(3);
  amalgam.setCardMaxHth(3);
  amalgam.setAura(false);

              // Spells

  /* High Charisma 051 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ High Charisma │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "│       ~       │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  high_charisma.setCardDisp(cDisp);
  high_charisma.setCardName("High Charisma");
  high_charisma.setCardClass(getType(1));
  high_charisma.setCardType(getType(12));
  high_charisma.setCardNum(51);
  high_charisma.setCardText(51);
  high_charisma.setCardCost(2);

  /* Natural Growth 052 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Natural  Growth│\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "│      (_)      │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  natural_growth.setCardDisp(cDisp);
  natural_growth.setCardName("Natural Growth");
  natural_growth.setCardClass(getType(1));
  natural_growth.setCardType(getType(13));
  natural_growth.setCardNum(52);
  natural_growth.setCardText(52);
  natural_growth.setCardCost(3);

  /* Arcane Bolt 053 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Arcane Bolt  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│       ~       │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  arcane_bolt.setCardDisp(cDisp);
  arcane_bolt.setCardName("Arcane Bolt");
  arcane_bolt.setCardClass(getType(1));
  arcane_bolt.setCardType(getType(12));
  arcane_bolt.setCardNum(53);
  arcane_bolt.setCardText(53);
  arcane_bolt.setCardCost(0);

  /* Arcane Burst 054 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Arcane Burst │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "│       ~       │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  arcane_burst.setCardDisp(cDisp);
  arcane_burst.setCardName("Arcane Burst");
  arcane_burst.setCardClass(getType(1));
  arcane_burst.setCardType(getType(12));
  arcane_burst.setCardNum(54);
  arcane_burst.setCardText(54);
  arcane_burst.setCardCost(2);

  /* Solar Flare 055 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Solar Flare  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "│      (_)      │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  solar_flare.setCardDisp(cDisp);
  solar_flare.setCardName("Solar Flare");
  solar_flare.setCardClass(getType(1));
  solar_flare.setCardType(getType(13));
  solar_flare.setCardNum(55);
  solar_flare.setCardText(55);
  solar_flare.setCardCost(4);

  /* Spirit Plane 056 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Spirit  Plane │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "│       ~       │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  spirit_plane.setCardDisp(cDisp);
  spirit_plane.setCardName("Spirit Plane");
  spirit_plane.setCardClass(getType(1));
  spirit_plane.setCardType(getType(12));
  spirit_plane.setCardNum(56);
  spirit_plane.setCardText(56);
  spirit_plane.setCardCost(4);

  /* Delusion 057 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Delusion    │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "│      _=_      │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  delusion.setCardDisp(cDisp);
  delusion.setCardName("Delusion");
  delusion.setCardClass(getType(1));
  delusion.setCardType(getType(14));
  delusion.setCardNum(57);
  delusion.setCardText(57);
  delusion.setCardCost(3);

  /* Exchange 058 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Exchange    │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "│       ~       │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  exchange.setCardDisp(cDisp);
  exchange.setCardName("Exchange");
  exchange.setCardClass(getType(1));
  exchange.setCardType(getType(12));
  exchange.setCardNum(58);
  exchange.setCardText(58);
  exchange.setCardCost(1);

  /* Last Stand 059 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Last  Stand  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "│       ~       │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  last_stand.setCardDisp(cDisp);
  last_stand.setCardName("Last Stand");
  last_stand.setCardClass(getType(1));
  last_stand.setCardType(getType(12));
  last_stand.setCardNum(59);
  last_stand.setCardText(59);
  last_stand.setCardCost(2);

  /* Polymorph 060 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Polymorph   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "│       ~       │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  polymorph.setCardDisp(cDisp);
  polymorph.setCardName("Polymorph");
  polymorph.setCardClass(getType(1));
  polymorph.setCardType(getType(12));
  polymorph.setCardNum(60);
  polymorph.setCardText(60);
  polymorph.setCardCost(4);

  /* Fire Ball 061 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Fire Ball   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "│       ~       │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  fire_ball.setCardDisp(cDisp);
  fire_ball.setCardName("Fire Ball");
  fire_ball.setCardClass(getType(1));
  fire_ball.setCardType(getType(12));
  fire_ball.setCardNum(61);
  fire_ball.setCardText(61);
  fire_ball.setCardCost(3);

  /* Ethereal Totem 062 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Ethereal  Totem│\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "│      (_)      │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  ethereal_totem.setCardDisp(cDisp);
  ethereal_totem.setCardName("Ethereal Totem");
  ethereal_totem.setCardClass(getType(1));
  ethereal_totem.setCardType(getType(13));
  ethereal_totem.setCardNum(62);
  ethereal_totem.setCardText(62);
  ethereal_totem.setCardCost(3);

  /* Green Thumb 063 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Green Thumb  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "│       ~       │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  green_thumb.setCardDisp(cDisp);
  green_thumb.setCardName("Green Thumb");
  green_thumb.setCardClass(getType(1));
  green_thumb.setCardType(getType(12));
  green_thumb.setCardNum(63);
  green_thumb.setCardText(63);
  green_thumb.setCardCost(1);

  /* Foreshadow 064 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Foreshadow   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "│      (_)      │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  foreshadow.setCardDisp(cDisp);
  foreshadow.setCardName("Foreshadow");
  foreshadow.setCardClass(getType(1));
  foreshadow.setCardType(getType(13));
  foreshadow.setCardNum(64);
  foreshadow.setCardText(64);
  foreshadow.setCardCost(1);

  /* Dungeon Feast 065 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Dungeon Feast │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "│      (_)      │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  dungeon_feast.setCardDisp(cDisp);
  dungeon_feast.setCardName("Dungeon Feast");
  dungeon_feast.setCardClass(getType(1));
  dungeon_feast.setCardType(getType(13));
  dungeon_feast.setCardNum(65);
  dungeon_feast.setCardText(65);
  dungeon_feast.setCardCost(2);

  /* Blood Bath 066 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Blood Bath   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "│       ~       │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  blood_bath.setCardDisp(cDisp);
  blood_bath.setCardName("Blood Bath");
  blood_bath.setCardClass(getType(1));
  blood_bath.setCardType(getType(12));
  blood_bath.setCardNum(66);
  blood_bath.setCardText(66);
  blood_bath.setCardCost(5);

  /* Village Emblem 067 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Village  Emblem│\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "│      (_)      │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  village_emblem.setCardDisp(cDisp);
  village_emblem.setCardName("Village Emblem");
  village_emblem.setCardClass(getType(1));
  village_emblem.setCardType(getType(13));
  village_emblem.setCardNum(67);
  village_emblem.setCardText(67);
  village_emblem.setCardCost(3);

  /* Frost Bolt 068 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Frost  Bolt  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "│       ~       │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  frost_bolt.setCardDisp(cDisp);
  frost_bolt.setCardName("Frost Bolt");
  frost_bolt.setCardClass(getType(1));
  frost_bolt.setCardType(getType(12));
  frost_bolt.setCardNum(68);
  frost_bolt.setCardText(68);
  frost_bolt.setCardCost(3);

  /* Mind Control 069 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Mind  Control │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│  * * * * * *  │\n";
  cDisp+= "│       ~       │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  mind_control.setCardDisp(cDisp);
  mind_control.setCardName("Mind Control");
  mind_control.setCardClass(getType(1));
  mind_control.setCardType(getType(12));
  mind_control.setCardNum(69);
  mind_control.setCardText(69);
  mind_control.setCardCost(6);

  /* Redirect 070 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Redirect    │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "│      _=_      │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  redirect.setCardDisp(cDisp);
  redirect.setCardName("Redirect");
  redirect.setCardClass(getType(1));
  redirect.setCardType(getType(14));
  redirect.setCardNum(70);
  redirect.setCardText(70);
  redirect.setCardCost(3);  

  /* Spell Counter 071 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Spell Counter │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "│      _=_      │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  counter_spell.setCardDisp(cDisp);
  counter_spell.setCardName("Spell Counter");
  counter_spell.setCardClass(getType(1));
  counter_spell.setCardType(getType(14));
  counter_spell.setCardNum(71);
  counter_spell.setCardText(71);
  counter_spell.setCardCost(4);

  /* Disarming Block 072 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Disarming Block│\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "│      _=_      │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  disarming_block.setCardDisp(cDisp);
  disarming_block.setCardName("Disarming Block");
  disarming_block.setCardClass(getType(1));
  disarming_block.setCardType(getType(14));
  disarming_block.setCardNum(72);
  disarming_block.setCardText(72);
  disarming_block.setCardCost(4);

  /* Side Quests 073 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Side Quests  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "│      (_)      │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  side_quests.setCardDisp(cDisp);
  side_quests.setCardName("Side Quests");
  side_quests.setCardClass(getType(1));
  side_quests.setCardType(getType(13));
  side_quests.setCardNum(73);
  side_quests.setCardText(73);
  side_quests.setCardCost(5);

  /* Reanimate Rune 074 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Reanimate Rune │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "│      _=_      │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  reanimate_rune.setCardDisp(cDisp);
  reanimate_rune.setCardName("Reanimate Rune");
  reanimate_rune.setCardClass(getType(1));
  reanimate_rune.setCardType(getType(14));
  reanimate_rune.setCardNum(74);
  reanimate_rune.setCardText(74);
  reanimate_rune.setCardCost(2);

  /* Freeloader 075 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Freeloader   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "│      _=_      │\n";
  cDisp+= "│     Spell     │\n";
  cDisp+= "└───────────────┘\n";
  freeloader.setCardDisp(cDisp);
  freeloader.setCardName("Freeloader");
  freeloader.setCardClass(getType(1));
  freeloader.setCardType(getType(14));
  freeloader.setCardNum(75);
  freeloader.setCardText(75);
  freeloader.setCardCost(2);

              // Equipment

  /* Lief's Hide 076 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Lief's Hide  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "│     |(:)|     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  liefs_hide.setCardDisp(cDisp);
  liefs_hide.setCardName("Lief's Hide");
  liefs_hide.setCardClass(getType(2));
  liefs_hide.setCardType(getType(15));
  liefs_hide.setCardNum(76);
  liefs_hide.setCardText(76);
  liefs_hide.setCardCost(4);

  /* Erik's Wrath 077 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Erik's  Wrath │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│  * * * * * *  │\n";
  cDisp+= "│     -{---     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  eriks_wrath.setCardDisp(cDisp);
  eriks_wrath.setCardName("Erik's Wrath");
  eriks_wrath.setCardClass(getType(2));
  eriks_wrath.setCardType(getType(16));
  eriks_wrath.setCardNum(77);
  eriks_wrath.setCardText(77);
  eriks_wrath.setCardCost(6);

  /* Ferydis Chain 078 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Ferydis Chain │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "│     |(:)|     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  freydis_chain.setCardDisp(cDisp);
  freydis_chain.setCardName("Freydis Chain");
  freydis_chain.setCardClass(getType(2));
  freydis_chain.setCardType(getType(15));
  freydis_chain.setCardNum(78);
  freydis_chain.setCardText(78);
  freydis_chain.setCardCost(5);

  /* Bjorn's Plate 079 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Bjorn's Plate │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│  * * * * * *  │\n";
  cDisp+= "│     |(:)|     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  bjorns_plate.setCardDisp(cDisp);
  bjorns_plate.setCardName("Bjorn's Plate");
  bjorns_plate.setCardClass(getType(2));
  bjorns_plate.setCardType(getType(15));
  bjorns_plate.setCardNum(79);
  bjorns_plate.setCardText(79);
  bjorns_plate.setCardCost(6);

  /* Cloth Garment 080 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Cloth Garment │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "│     |(:)|     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  cloth_garment.setCardDisp(cDisp);
  cloth_garment.setCardName("Cloth Garment");
  cloth_garment.setCardClass(getType(2));
  cloth_garment.setCardType(getType(15));
  cloth_garment.setCardNum(80);
  cloth_garment.setCardText(80);
  cloth_garment.setCardCost(3);

  /* Shank 081 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│     Shank     │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "│     -{---     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  shank.setCardDisp(cDisp);
  shank.setCardName("Shank");
  shank.setCardClass(getType(2));
  shank.setCardType(getType(16));
  shank.setCardNum(81);
  shank.setCardText(81);
  shank.setCardCost(1);

  /* Merlin's Robe 082 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Merlin's Robe │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│  * * * * * *  │\n";
  cDisp+= "│     |(:)|     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  merlins_robe.setCardDisp(cDisp);
  merlins_robe.setCardName("Merlin's Robe");
  merlins_robe.setCardClass(getType(2));
  merlins_robe.setCardType(getType(15));
  merlins_robe.setCardNum(82);
  merlins_robe.setCardText(82);
  merlins_robe.setCardCost(6);

  /* Short Sword 083 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Short Sword  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "│     -{---     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  short_sword.setCardDisp(cDisp);
  short_sword.setCardName("Short Sword");
  short_sword.setCardClass(getType(2));
  short_sword.setCardType(getType(16));
  short_sword.setCardNum(83);
  short_sword.setCardText(83);
  short_sword.setCardCost(2);

  /* One-Handed Axe 084 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│One-Handed Axe │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "│     -{---     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  onehand_axe.setCardDisp(cDisp);
  onehand_axe.setCardName("One-Handed Axe");
  onehand_axe.setCardClass(getType(2));
  onehand_axe.setCardType(getType(16));
  onehand_axe.setCardNum(84);
  onehand_axe.setCardText(84);
  onehand_axe.setCardCost(3);

  /* Brimstone Ring 085 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Brimstone Ring │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "│     |(:)|     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  brimstone_ring.setCardDisp(cDisp);
  brimstone_ring.setCardName("Brimstone Ring");
  brimstone_ring.setCardClass(getType(2));
  brimstone_ring.setCardType(getType(15));
  brimstone_ring.setCardNum(85);
  brimstone_ring.setCardText(85);
  brimstone_ring.setCardCost(1);

  /* Gold Ring 086 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Gold Ring   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "│     |(:)|     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  gold_ring.setCardDisp(cDisp);
  gold_ring.setCardName("Gold Ring");
  gold_ring.setCardClass(getType(2));
  gold_ring.setCardType(getType(15));
  gold_ring.setCardNum(86);
  gold_ring.setCardText(86);
  gold_ring.setCardCost(1);

  /* Amulet of Hlin 087 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Amulet of Hlin │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "│     |(:)|     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  hlin_amulet.setCardDisp(cDisp);
  hlin_amulet.setCardName("Amulet of Hlin");
  hlin_amulet.setCardClass(getType(2));
  hlin_amulet.setCardType(getType(15));
  hlin_amulet.setCardNum(87);
  hlin_amulet.setCardText(87);
  hlin_amulet.setCardCost(2);

  /* Necronomicon 088 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Necronomicon  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "│     |(:)|     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  necro.setCardDisp(cDisp);
  necro.setCardName("Necronomicon");
  necro.setCardClass(getType(2));
  necro.setCardType(getType(15));
  necro.setCardNum(88);
  necro.setCardText(88);
  necro.setCardCost(5);

  /* Loot Pouch 089 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Loot  Pouch  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "│     |(:)|     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  loot_pouch.setCardDisp(cDisp);
  loot_pouch.setCardName("Loot Pouch");
  loot_pouch.setCardClass(getType(2));
  loot_pouch.setCardType(getType(15));
  loot_pouch.setCardNum(89);
  loot_pouch.setCardText(89);
  loot_pouch.setCardCost(4);

  /* Runelit Staff 090 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Runelit Staff │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "│     -{---     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  runelit_staff.setCardDisp(cDisp);
  runelit_staff.setCardName("Runelit Staff");
  runelit_staff.setCardClass(getType(2));
  runelit_staff.setCardType(getType(16));
  runelit_staff.setCardNum(90);
  runelit_staff.setCardText(90);
  runelit_staff.setCardCost(5);

  /* Frozen Tuna 91 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Frozen  Tuna  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "│     -{---     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  frozen_tuna.setCardDisp(cDisp);
  frozen_tuna.setCardName("Frozen Tuna");
  frozen_tuna.setCardClass(getType(2));
  frozen_tuna.setCardType(getType(16));
  frozen_tuna.setCardNum(91);
  frozen_tuna.setCardText(91);
  frozen_tuna.setCardCost(4);

  /* Excalibur 092 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Excalibur   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│  * * * * * *  │\n";
  cDisp+= "│     -{---     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  excalibur.setCardDisp(cDisp);
  excalibur.setCardName("Excalibur");
  excalibur.setCardClass(getType(2));
  excalibur.setCardType(getType(16));
  excalibur.setCardNum(92);
  excalibur.setCardText(92);
  excalibur.setCardCost(6);

  /* Scale Shield 093 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Scale  Shield │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "│     -{---     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  scale_shield.setCardDisp(cDisp);
  scale_shield.setCardName("Scale Shield");
  scale_shield.setCardClass(getType(2));
  scale_shield.setCardType(getType(16));
  scale_shield.setCardNum(93);
  scale_shield.setCardText(93);
  scale_shield.setCardCost(3);

  /* Hand of Mitus 094 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Hand of Mitus │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "│     |(:)|     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  mitus_hand.setCardDisp(cDisp);
  mitus_hand.setCardName("Hand of Mitus");
  mitus_hand.setCardClass(getType(2));
  mitus_hand.setCardType(getType(15));
  mitus_hand.setCardNum(94);
  mitus_hand.setCardText(94);
  mitus_hand.setCardCost(3);

  /* Traveler Attire 095 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Traveler Attire│\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "│     |(:)|     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  trav_attire.setCardDisp(cDisp);
  trav_attire.setCardName("Traveler Attire");
  trav_attire.setCardClass(getType(2));
  trav_attire.setCardType(getType(15));
  trav_attire.setCardNum(95);
  trav_attire.setCardText(95);
  trav_attire.setCardCost(2);

  /* Aged Wand 096 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Aged Wand   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "│     -{---     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  aged_wand.setCardDisp(cDisp);
  aged_wand.setCardName("Aged Wand");
  aged_wand.setCardClass(getType(2));
  aged_wand.setCardType(getType(16));
  aged_wand.setCardNum(96);
  aged_wand.setCardText(96);
  aged_wand.setCardCost(1);

  /* Torch 097 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│     Torch     │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "│     -{---     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  torch.setCardDisp(cDisp);
  torch.setCardName("Torch");
  torch.setCardClass(getType(2));
  torch.setCardType(getType(16));
  torch.setCardNum(97);
  torch.setCardText(97);
  torch.setCardCost(2);

  /* Longbow 098 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│    Longbow    │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "│     -{---     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  longbow.setCardDisp(cDisp);
  longbow.setCardName("Longbow");
  longbow.setCardClass(getType(2));
  longbow.setCardType(getType(16));
  longbow.setCardNum(98);
  longbow.setCardText(98);
  longbow.setCardCost(4);

  /* Battle Axe 099 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Battle Axe   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "│     -{---     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  battle_axe.setCardDisp(cDisp);
  battle_axe.setCardName("Battle Axe");
  battle_axe.setCardClass(getType(2));
  battle_axe.setCardType(getType(16));
  battle_axe.setCardNum(99);
  battle_axe.setCardText(99);
  battle_axe.setCardCost(5);

  /* Soulstone 100 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Soulstone   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│    * * * *    │\n";
  cDisp+= "│     |(:)|     │\n";
  cDisp+= "│     Equip     │\n";
  cDisp+= "└───────────────┘\n";
  soulstone.setCardDisp(cDisp);
  soulstone.setCardName("Soulstone");
  soulstone.setCardClass(getType(2));
  soulstone.setCardType(getType(15));
  soulstone.setCardNum(100);
  soulstone.setCardText(100);
  soulstone.setCardCost(4);
}
string CardDB::getType(int typeElement) const
{
  switch (typeElement)
  {
    case 0: return "Minion";
    case 1: return "Spell";
    case 2: return "Equip";
    case 3: return "Play";
    case 4: return "Effect";
    case 5: return "Deathrattle";
    case 6: return "Vir";
    case 7: return "Umbra";
    case 8: return "Beast";
    case 9: return "Plant";
    case 10: return "Demon";
    case 11: return "Trito";
    case 12: return "Instant";
    case 13: return "Field";
    case 14: return "Covert";
    case 15: return "Gear";
    case 16: return "Weapon";
    default: return "- cardDB.cpp/ getType()/ switch default -";
  }
}
Card CardDB::getCDB_Card(int card_num) const
{
  switch(card_num)
  {
    case 1: return goblin;
    case 2: return ritualist;
    case 3: return gnome_priest;
    case 4: return blade_master;
    case 5: return fairy;
    case 6: return sprite_forest;
    case 7: return sprite_fire;
    case 8: return sprite_water;
    case 9: return sprite_earth;
    case 10: return tradesman;
    case 11: return spirit_guide;
    case 12: return centaur;
    case 13: return phoenix;
    case 14: return mimic_chest;
    case 15: return witch;
    case 16: return elf_archer;
    case 17: return hydra;
    case 18: return troll;
    case 19: return koi_lunar;
    case 20: return koi_solar;
    case 21: return oni;
    case 22: return dwarf_bronze;
    case 23: return sapling;
    case 24: return stone_behemoth;
    case 25: return whelp_lava;
    case 26: return hungry_grass;
    case 27: return chimera;
    case 28: return rose_sprout;
    case 29: return black_widow;
    case 30: return whelp_oceans;
    case 31: return imp;
    case 32: return ghost;
    case 33: return amarok;
    case 34: return banshee;
    case 35: return eye_tyrant;
    case 36: return jiangshi;
    case 37: return wendigo;
    case 38: return mummy;
    case 39: return vine_wall;
    case 40: return wicked_flytrap;
    case 41: return poison_ivy;
    case 42: return forest_keeper;
    case 43: return life_tree;
    case 44: return fungal_carnage;
    case 45: return aka_manah;
    case 46: return vrock;
    case 47: return hezrou;
    case 48: return leviathan;
    case 49: return ugly_ogre;
    case 50: return amalgam;
    case 51: return high_charisma;
    case 52: return natural_growth;
    case 53: return arcane_bolt;
    case 54: return arcane_burst;
    case 55: return solar_flare;
    case 56: return spirit_plane;
    case 57: return delusion;
    case 58: return exchange;
    case 59: return last_stand;
    case 60: return polymorph;
    case 61: return fire_ball;
    case 62: return ethereal_totem;
    case 63: return green_thumb;
    case 64: return foreshadow;
    case 65: return dungeon_feast;
    case 66: return blood_bath;
    case 67: return village_emblem;
    case 68: return frost_bolt;
    case 69: return mind_control;
    case 70: return redirect;
    case 71: return counter_spell;
    case 72: return disarming_block;
    case 73: return side_quests;
    case 74: return reanimate_rune;
    case 75: return freeloader;
    case 76: return liefs_hide;
    case 77: return eriks_wrath;
    case 78: return freydis_chain;
    case 79: return bjorns_plate;
    case 80: return cloth_garment;
    case 81: return shank;
    case 82: return merlins_robe;
    case 83: return short_sword;
    case 84: return onehand_axe;
    case 85: return brimstone_ring;
    case 86: return gold_ring;
    case 87: return hlin_amulet;
    case 88: return necro;
    case 89: return loot_pouch;
    case 90: return runelit_staff;
    case 91: return frozen_tuna;
    case 92: return excalibur;
    case 93: return scale_shield;
    case 94: return mitus_hand;
    case 95: return trav_attire;
    case 96: return aged_wand;
    case 97: return torch;
    case 98: return longbow;
    case 99: return battle_axe;
    default: return empty;
  }
}  // srchManip uses typeCount - 17
void CardDB::srchManip(string& srch)
{
  vector<int> capEles;
  string srchTemp, cardNameTemp;
  Card cardTemp;

  srchTemp = srch;
  srchTemp[0] = toupper(srchTemp[0]);
  for(int i = 0; i < 17; i++) // here
    if(srchTemp == getType(i))
      srch[0] = toupper(srch[0]);
  return;
}
void CardDB::cardCount(vector<int>& costCount, vector<int>& typeCount)
{
  Card cardTemp;
  char classTemp;
  string typeTemp, minTypeTemp;

  for(int i = 0; i < costCount.size(); i++)
    costCount[i] = 0;
  for(int i = 0; i < typeCount.size(); i++)
    typeCount[i] = 0;

  for(int i = 1; i <= totalCards; i++)
  {
    cardTemp = getCDB_Card(i);
    typeTemp = cardTemp.getCardType();
    minTypeTemp = cardTemp.getCardMinType();
    classTemp = '?';
    if(cardTemp.getCardClass() == "Minion")
      classTemp = 'm';
    else if(cardTemp.getCardClass() == "Spell")
      classTemp = 's';
    else if(cardTemp.getCardClass() == "Equip")
      classTemp = 'e';
    switch(cardTemp.getCardCost())
    {
      case 0: costCount[0]++;
              break;
      case 1: costCount[1]++;
              break;
      case 2: costCount[2]++;
              break;
      case 3: costCount[3]++;
              break;
      case 4: costCount[4]++;
              break;
      case 5: costCount[5]++;
              break;
      case 6: costCount[6]++;
              break;
      default: cout << "- cardDB.cpp/ cardCount() COST switch default -\n\n";
    }
    switch(classTemp)
    {
      case 'm': typeCount[0]++;
                if(typeTemp == getType(3))
                  typeCount[3]++;
                else if(typeTemp == getType(4))
                  typeCount[4]++;
                else if(typeTemp == getType(5))
                  typeCount[5]++;
                if(minTypeTemp == getType(6))
                  typeCount[6]++;
                else if(minTypeTemp == getType(7))
                  typeCount[7]++;
                else if(minTypeTemp == getType(8))
                  typeCount[8]++;
                else if(minTypeTemp == getType(9))
                  typeCount[9]++;
                else if(minTypeTemp == getType(10))
                  typeCount[10]++;
                else if(minTypeTemp == getType(11))
                  typeCount[11]++;
                break;
      case 's': typeCount[1]++;
                if(typeTemp == getType(12))
                  typeCount[12]++;
                else if(typeTemp == getType(13))
                  typeCount[13]++;
                else if(typeTemp == getType(14))
                  typeCount[14]++;
                break;
      case 'e': typeCount[3]++;
                if(typeTemp == getType(15))
                  typeCount[15]++;
                else if (typeTemp == getType(16))
                  typeCount[16]++;
                break;
      default: "- cardDB.cpp/ cardCount TYPE switch default -\n\n";
    }
  }
  return;
}
void loadDeckCase(CardDB CDB, vector<Deck>& deckCase)
{
  ifstream fin;
  string index;
  int cardNumber;
  Deck deckTemp;

  for(int i = 1; i <= 5; i++)
  {
    switch(i)
    {
      case 1: fin.open("deck1.txt");
              break;
      case 2: fin.open("deck2.txt");
              break;
      case 3: fin.open("deck3.txt");
              break;
      case 4: fin.open("deck4.txt");
              break;
      case 5: fin.open("deck5.txt");
              break;
      default: cout << "** cardDB.cpp/ loadDeckCase() fin default **\n\n";
    }
    getline(fin,index);
    if(index != "-")
    {
      deckTemp.setDeckNum(i);
      deckTemp.setDeckName(index);
      deckCase.push_back(deckTemp);
      deckTemp.reset();
      while(!fin.eof())
      {
        getline(fin,index);
        cardNumber = stoi(index);
        if(deckCase[i-1].addCheck(CDB.getCDB_Card(cardNumber)))
          deckCase[i-1].addCard(CDB.getCDB_Card(cardNumber),false);
      }
    }
    else
    {
      fin.close();
      return;
    }
    fin.close();
  }
  return;
}
void loadDeckCase_CPU(CardDB CDB, vector<Deck>& deckCase, vector<Deck>& cpuDeckCase)
{
  ifstream fin;
  string index;
  int cardNumber;
  Deck deckTemp;

  for(int i = 1; i <= 5; i++)
  {
    switch(i)
    {
      case 1: fin.open("cpu_deck1.txt");
              break;
      case 2: fin.open("cpu_deck2.txt");
              break;
      case 3: fin.open("cpu_deck3.txt");
              break;
      case 4: fin.open("cpu_deck4.txt");
              break;
      case 5: fin.open("cpu_deck5.txt");
              break;
      default: cout << "** cardDB.cpp/ loadDeckCase_CPU() fin default **\n\n";
    }
    getline(fin,index);
    if(index != "-")
    {
      deckTemp.setDeckNum(i);
      deckTemp.setDeckName(index);
      cpuDeckCase.push_back(deckTemp);
      deckTemp.reset();
      while(!fin.eof())
      {
        getline(fin,index);
        cardNumber = stoi(index);
        if(cpuDeckCase[i-1].addCheck(CDB.getCDB_Card(cardNumber)))
          cpuDeckCase[i-1].addCard(CDB.getCDB_Card(cardNumber),false);
      }
    }
    else
    {
      fin.close();
      return;
    }
    fin.close();
  }
  return;
}
void saveDeckCase(vector<Deck> deckCase)
{
  ofstream fout;
  CardNode *tempPtr;

  for(int i = 1; i <= 5; i++)
  {
    switch(i)
    {
      case 1: fout.open("deck1.txt");
              break;
      case 2: fout.open("deck2.txt");
              break;
      case 3: fout.open("deck3.txt");
              break;
      case 4: fout.open("deck4.txt");
              break;
      case 5: fout.open("deck5.txt");
              break;
      default: cout << "cardDB.cpp/ saveDeckCase() switch default -\n\n";
    }
    if(i-1 < deckCase.size())
    {
      fout << deckCase[i-1].getDeckName();
      if(deckCase[i-1].getCardAmt() > 0)
      {
        fout << endl;
        tempPtr = deckCase[i-1].getDeckHead();
        while(tempPtr != NULL)
        {
          fout << tempPtr->getCard().getCardNum();
          tempPtr = tempPtr->getNextCard();
          if(tempPtr != NULL)
            fout << endl;
        }
      }
    }
    else
      fout << "-";
    fout.close();
  }
}
void saveDeckCase_CPU(vector<Deck> cpuDeckCase)
{
  ofstream fout;
  CardNode *tempPtr;

  for(int i = 1; i <= 5; i++)
  {
    switch(i)
    {
      case 1: fout.open("cpu_deck1.txt");
              break;
      case 2: fout.open("cpu_deck2.txt");
              break;
      case 3: fout.open("cpu_deck3.txt");
              break;
      case 4: fout.open("cpu_deck4.txt");
              break;
      case 5: fout.open("cpu_deck5.txt");
              break;
      default: cout << "cardDB.cpp/ cpu saveDeckCase() switch default -\n\n";
    }
    if(i-1 < cpuDeckCase.size())
    {
      fout << cpuDeckCase[i-1].getDeckName();
      if(cpuDeckCase[i-1].getCardAmt() > 0)
      {
        fout << endl;
        tempPtr = cpuDeckCase[i-1].getDeckHead();
        while(tempPtr != NULL)
        {
          fout << tempPtr->getCard().getCardNum();
          tempPtr = tempPtr->getNextCard();
          if(tempPtr != NULL)
            fout << endl;
        }
      }
    }
    else
      fout << "-";
    fout.close();
  }
}
void CDB_PrintInfo(CardDB CDB)
{
  vector<int> costCount(7);
  vector<int> typeCount(17);
  CDB.cardCount(costCount,typeCount);
  cout << "Cost Count\n";
  for (int i = 0; i < costCount.size(); i++)
    cout << "[" << i << "]  " << costCount[i] << endl;
  cout << endl << "Type Count\n";
  for (int i = 0; i < typeCount.size(); i++)
  {
    cout << "[" << i << "] " << CDB.getType(i) << ": "
         << typeCount[i] << endl;
    if(i == 2 || i == 5 || i == 11 || i == 14)
      cout << endl;
  }
  cout << endl << "Total: " << CDB.totalCards << endl << endl;
  return;
}
void viewCollection(CardDB CDB, vector<Deck>& deckCase, int& deckNum)
{
  vector <Card> cardList;
  Card cardTemp, sortTemp;
  string srch, strTemp;
  bool found = false;
  bool editMode = false;
  bool MMfunc;
  int srchCost = -1, srchIt = -1;
  int cardListSize, printK, cardQty, printQty;
  int printCLS = 0, sortSmall, txtEle, setwTemp;
  int addNum;

  cin.ignore(80,'\n');
  do
  {
    cout << "\033[2J\033[1;1H";
    cout << "  =====                                                 =====\n"
         << "  ==========                                       ==========\n"
         << "  ===============                             ===============\n"
         << "  ====================                   ====================\n"
         << "  ======================               ======================\n"
         << "  ====================                   ====================\n"
         << "  ===============                             ===============\n"
         << "  ==========                                       ==========\n"
         << "  =====                                                 =====\n";

    cardList = {CDB.empty};
    if(srch == "~")
    {
      for(int i = 1; i <= CDB.totalCards; i++)
      {
        cardTemp = CDB.getCDB_Card(i);
        if(cardListSize == 0)
          cardList[0] = cardTemp;
        else
          cardList.push_back(CDB.getCDB_Card(i));
        cardListSize++;
      }
    }
    else if(srch != "")
    {
      for(int i = 1; i <= CDB.totalCards; i++)
      {
        if(srchCost > -1)
        {
          cardTemp = CDB.getCDB_Card(i);
          if(srchCost == cardTemp.getCardCost())
              found = true;
          if(i == CDB.totalCards)
            srchCost = -1;
        }
        else
        {
          cardTemp = CDB.getCDB_Card(i);
          srchIt = cardTemp.getCardType().find(srch);
          if(srchIt > -1)
            found = true;
          if(found == false)
          {
            srchIt = cardTemp.getCardMinType().find(srch);
            if(srchIt > -1)
              found = true;
          }
          if(found == false)
          {
            srchIt = cardTemp.getCardClass().find(srch);
            if(srchIt > -1)
              found = true;
          }
          if(found == false)
          {
            strTemp = cardTemp.getCardName();
            for(int i = 0; i < strTemp.length(); i++)
              if(isupper(strTemp[i]))
                strTemp[i] = tolower(strTemp[i]);
            srchIt = strTemp.find(srch);
            if(srchIt > -1)
              found = true;
          }
          if(found == false)
          {
            strTemp = cardTemp.getCardText();
            for(int i = 0; i < strTemp.length(); i++)
              if(isupper(strTemp[i]))
                strTemp[i] = tolower(strTemp[i]);
            srchIt = strTemp.find(srch);
            if(srchIt > -1)
              found = true;
          }
        }
        if(found)
        {
          if(cardListSize == 0)
            cardList[0] = cardTemp;
          else
            cardList.push_back(cardTemp);
          cardListSize++;
          found = false;
          srchIt = -1;
        }
      }
    }
    if(cardListSize > 0)
    {
      for (int i = 0; i < cardListSize -1; i++)
      {
        sortSmall = i;
        for (int j = i; j < cardListSize; j++)
        {
          if (cardList[j].getCardCost() < cardList[sortSmall].getCardCost())
            sortSmall = j;
        }
        sortTemp = cardList[sortSmall];
        cardList[sortSmall] = cardList[i];
        cardList[i] = sortTemp;
      }
      cardQty = cardListSize;
      if(cardListSize%5 == 0)
        printCLS = cardListSize / 5;
      else
        printCLS = (cardListSize / 5) +1;
      for(int i = 0; i < printCLS; i++)
      {
        if(cardQty >= 5)
        {
          printQty = 5;
          cardQty -= 5;
        }
        else
          printQty = cardQty;
        for(int j = 0; j < 13; j++)
        {
          for(int k = 0; k < printQty; k++)
          {
            printK = (i*5)+k;
            switch(j)
            {
              case 0:  cout << cardList[printK].getCardDisp().substr(0,51);
                       break;
              case 1:  cout << cardList[printK].getCardDisp().substr(52,21);
                       break;
              case 2:  cout << cardList[printK].getCardDisp().substr(74,51);
                       break;
              case 3:  cout << cardList[printK].getCardDisp().substr(126,21);
                       break;
              case 4:  cout << cardList[printK].getCardDisp().substr(148,21);
                       break;
              case 5:  cout << cardList[printK].getCardDisp().substr(170,21);
                       break;
              case 6:  cout << cardList[printK].getCardDisp().substr(192,21);
                       break;
              case 7:  cout << cardList[printK].getCardDisp().substr(214,21);
                       break;
              case 8:  cout << cardList[printK].getCardDisp().substr(236,51);
                       break;
              case 9:  cout << cardList[printK].getCardDisp().substr(288,21);
                       break;
              case 10: if(cardList[printK].getCardClass() == "Minion")
                        cout << cardList[printK].getCardDisp().substr(310,37);
                       else
                        cout << cardList[printK].getCardDisp().substr(310,21);
                       break;
              case 11: if(cardList[printK].getCardClass() == "Minion")
                        cout << cardList[printK].getCardDisp().substr(348,25);
                       else
                        cout << cardList[printK].getCardDisp().substr(332,21);
                       break;
              case 12: if(cardList[printK].getCardClass() == "Minion")
                        cout << cardList[printK].getCardDisp().substr(374,51);
                       else
                        cout << cardList[printK].getCardDisp().substr(354,51);
                       break;
              if(k < printQty)
                cout << " ";
            }
          }
          cout << endl;
        }
        if(editMode)
        {
          for(int e = 0; e < printQty; e++)
          {
            if(e == 0)
              cout << setw(9);
            else
              cout << setw(17);
            cout << ((i * 5) + e) +1;
          }
        }
        cout << endl <<
        "┌────────────────────────────────────────────────────────────┐\n";
        for(int t = 0; t < printQty; t++)
        {
          txtEle = (i * 5) + t;
          cout << "│ - "
               << cardList[txtEle].getCardName() << " -"
               << setw(58-cardList[txtEle].getCardName().length()) 
               << right << "│" << endl 
               << left << "│ " << cardList[txtEle].getCardText() 
               << setw(62-cardList[txtEle].getCardText().length())
               << right << "│" << endl;
          if(t != printQty-1)
            cout <<
            "├────────────────────────────────────────────────────────────┤\n";
          else
            cout <<
            "└────────────────────────────────────────────────────────────┘\n"
            << setw(80) << "Page  " << i+1 << " of " << printCLS << endl <<
            "════════════════════════════════════════════"
            "════════════════════════════════════════════\n\n"
            "════════════════════════════════════════════"
            "════════════════════════════════════════════\n\n";
        }
      }
    }
    cout << endl <<
    "       ╓────────────────────────────────────────────────╖\n"
    "       ║               Search Conditions                ║\n"
    "       ║           ──────────────────────────           ║\n"
    "       ║                                                ║\n"
    "       ║         ∙ Words and Numbers                    ║\n"
    "       ║         ∙ \"drop\"  -  to search by cost         ║\n"
    "       ║         ∙ \"lobby\" -  to enter Deck Lobby       ║\n";
    if(deckNum == -1)
      cout <<
    "       ║         ∙ quit  -  for Main Menu               ║\n";
    else
      cout <<
    "       ║                                                ║\n"
    "       ║      \"add\" + list number adds card to deck     ║\n";
    cout << 
    "       ╙────────────────────────────────────────────────╜\n\n";
    if(deckNum > -1)
    {
      editMode = true;
      cout << "\t\t\t\t\tEditing Deck: " << deckCase[deckNum-1].getDeckName() << "\n\n\n";
    }
    if(srch != "" && cardListSize == 0)
      cout << "-- No results for \""<< srch << "\" --\n\n";
    else if(srch != "" && cardListSize > 0)
      cout << "Cards found for \"" << srch << "\": " << cardListSize << endl << endl;
    cout << "Search: ";
    if(srch == "drop")
      cin.ignore(80,'\n');
    getline(cin,srch);
    CDB.srchManip(srch);
    if(srch == "drop")
    {
      cout << "\nDrop: ";
      cin >> srchCost;
    }
    if(srch == "lobby")
    {
      deckNum = -1; 
      MMfunc = deckLobby(CDB,deckCase,deckNum);
      if(MMfunc)
        srch = "quit";
    }
    if(srch == "add" && deckNum != -1)
    {
      if(cardListSize > 0)
      {
        cout << " ";
        cin >> addNum;
        cardTemp = cardList[addNum-1];
        if(deckCase[deckNum-1].addCheck(cardTemp))
          deckCase[deckNum-1].addCard(cardTemp,true);
      }
      else
        cout << "** Search cards to add cards **\n\n";
    }
    if(srch == "quit" && deckNum == -1)
      return;
    cardListSize = 0;
    cardList.clear();
  }while(srch != "quit");
  return;
}
bool deckLobby(CardDB CDB, vector<Deck>& deckCase, int& deckNum)
{
  vector<Deck>::iterator iter;
  bool dlMenu = true;
  bool deckEdit = false;
  bool validDeck = true;
  Deck deckTemp;
  int deckNameSetW, deckEle;
  int removeNum;
  bool removeVal = true;
  string strTemp;
  char option = '^';
  char yesNo;

  do
  {
    cout << "\033[2J\033[1;1H" << endl;
    if(dlMenu)
    {
      cout << "┌────────────────────────────────────────────┐\n"
           << "│                 Deck Lobby                 │\n"
           << "└────────────────────────────────────────────┘\n"
           << "┌────────────────────────────────────────────┐\n"
           << "│     M - Main Menu        C - Collection    │\n"
           << "└────────────────────────────────────────────┘\n\n"
           << "┌────────────────────────────────────────────┐\n"
           << "│                Decks " << deckCase.size() 
           << " / " << "5                 │\n";
      if(deckCase.size() > 0)
      {
        cout << "│                                            │\n";
        for(int i = 0; i < deckCase.size(); i++)
        {
          cout << "│  " << deckCase[i].getDeckName();
          deckNameSetW = 46 - deckCase[i].getDeckName().length();
          cout << setw(deckNameSetW) << right << "│\n";
        }
      }
      cout << "│                                            │\n"
           << "└────────────────────────────────────────────┘\n"
           << "┌────────────────────────────────────────────┐\n"
           << "│                  Options                   │\n";
      if(deckCase.size() < 5)
        cout << "│ 1) Create New                              │\n";
      if(deckCase.size() > 0)
      {
        cout << "│ 2) Delete                                  │\n"
             << "│ 3) Edit                                    │\n";
      }
      cout << "│                                            │\n"
           << "└────────────────────────────────────────────┘\n\n"
           << "Option: ";
      cin >> option;
      option = tolower(option);
      if(option == '1' && deckCase.size() < 5)
      {
        cout << "Deck Name: ";
        cin.ignore(80,'\n');
        getline(cin,strTemp);
        deckTemp.setDeckNum(deckCase.size()+1);
        deckTemp.setDeckName(strTemp);
        deckCase.push_back(deckTemp);
        deckTemp.reset();
      }
      else if(option == '2')
      {
        do
        {
          if(!validDeck)
            cout << "** Not a valid deck number **\n\n";
          validDeck = true;
          cout << "Deck Number: ";
          cin >> deckEle;
          if(deckEle < 1 || deckEle > deckCase.size())
            validDeck = false;
        }while(!validDeck);
        cout << endl;
        cout << "Are you sure you want to delete ";
        cout << "\"" << deckCase[deckEle-1].getDeckName() << "\"?\n"
             << "             (Y)es or (N)o : ";
        cin >> yesNo;
        yesNo = tolower(yesNo);
        if(yesNo == 'y')
        {
          deckCase[deckEle-1].deleteDeck();
          deckCase.erase(deckCase.begin()+(deckEle-1));
          for(int i = 0; i < deckCase.size(); i++)
            deckCase[i].setDeckNum(i+1);
          saveDeckCase(deckCase);
        }
      }
      else if(option == '3')
      {
        dlMenu = false;
        deckEdit = true;
      }
    }
    else
    {
      cout << "┌────────────────────────────────────────────┐\n"
           << "│                 Deck  Case                 │\n"
           << "└────────────────────────────────────────────┘\n"
           << "┌────────────────────────────────────────────┐\n"
           << "│             0 - Close Deck Case            │\n"
           << "└────────────────────────────────────────────┘\n\n"
           << "┌────────────────────────────────────────────┐\n"
           << "│                Decks " << deckCase.size() 
           << " / " << "5                 │\n";
      if(deckCase.size() > 0)
      {
        cout << "│                                            │\n";
        for(int i = 0; i < deckCase.size(); i++)
        {
          cout << "│ " << i+1 << ") " << deckCase[i].getDeckName();
          deckNameSetW = 44 - deckCase[i].getDeckName().length();
          cout << setw(deckNameSetW) << right << "│\n";
        }
      }
      cout << "│                                            │\n"
           << "└────────────────────────────────────────────┘\n";
      do
      {
        if(!validDeck)
          cout << "** Not a valid deck number **\n\n";
        validDeck = true;
        cout << "Deck Number: ";
        cin >> deckEle;
        if(deckEle < 0 || deckEle > deckCase.size())
          validDeck = false;
      }while(!validDeck);
      if(deckEle == 0)
      {
        dlMenu = true;
        deckEdit = false;
      }
      else
      {
        do
        {
          cout << "\033[2J\033[1;1H" << endl;
          deckNameSetW = 41 - deckCase[deckEle-1].getDeckName().length();
          cout << "┌────────────────────────────────────────────┐\n"
               << "│          0 - Return to Deck Lobby          │\n"
               << "└────────────────────────────────────────────┘\n\n"
               << "┌────────────────────────────────────────────┐\n"
               << "│ " << deckCase[deckEle-1].getDeckName() << " ";
          if(deckCase[deckEle-1].getCardAmt() < 10)
            cout << "0";
          cout << deckCase[deckEle-1].getCardAmt() << "/25"
               << setw(deckNameSetW) << "│\n"
               << "│                                            │\n";

          if(deckCase[deckEle-1].getCardAmt() < 25)
            cout << "│ 1) Add Cards                               │\n";
          if(deckCase[deckEle-1].getCardAmt() > 0)
            cout << "│ 2) Remove Cards                            │\n";
          cout << "│ 3) Rename Deck                             │\n"
               << "│                                            │\n"
               << "└────────────────────────────────────────────┘\n\n";
          deckCase[deckEle-1].printDeckBasic();
          do
          {
            if(option > '3' || option < '0')
              cout << "** Invalid Option **\n\n";
            cout << "Option: ";
            cin >> option;
            option = tolower(option);
          }while(option > '3' || option < '0');
          if(option == '2')
          {
            if(deckCase[deckEle-1].getCardAmt() > 0)
            {
              do
              {
                if(!removeVal)
                  cout << "* Invalid Number *\n\n";
                cout << "Remove Number: ";
                cin >> removeNum;
                if(removeNum <= deckCase[deckEle-1].getCardAmt()
                   && removeNum > 0)
                {
                  deckCase[deckEle-1].removeCard(removeNum);
                  saveDeckCase(deckCase);
                  removeVal = true;
                }
              }while(!removeVal);
            }
          }
          if(option == '3')
          {
            cout << "Rename: ";
            cin.ignore(80,'\n');
            getline(cin,strTemp);
            deckCase[deckEle-1].setDeckName(strTemp);
          }
        }while(option == '2' || option == '3');
        if(option == '1')
        {
          if(deckCase[deckEle-1].getCardAmt() < 25)
          {
            deckNum = deckEle;
            option = 'c';
          }
        }
        else if(option == '0')
        {
          dlMenu = true;
          deckEdit = false;
        }
      }
    }
  }while(option != 'm' && option != 'c');
  if(option == 'm')
    return true;
  else
    return false;
}