/* Filename: exCardDB.cpp
   Summary: Implementation for exCardDB
   Author: Chris Sebring
   Date: 03/14/2023
*/

#include "exCardDB.h"
#include <string>
#include <vector>
#include <iostream>
ExCardDB::ExCardDB(){}
void ExCardDB::setExCardDB()
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
  
  /* Forest Treant 001 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Forest Treant │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 4 │ Plant │ 4 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  forest_treant.setCardDisp(cDisp);
  forest_treant.setCardName("Forest Treant");
  forest_treant.setCardClass(getType(0));
  forest_treant.setCardType(getType(4));
  forest_treant.setCardMinType(getType(9));
  forest_treant.setCardNum(1);
  forest_treant.setCardText(1);
  forest_treant.setCardCost(3);
  forest_treant.setCardAtk(4);
  forest_treant.setCardHth(4);
  forest_treant.setCardMaxHth(4);
                        
  /* Ancient Oak 002 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Ancient Oak  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│  * * * * * *  │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 8 │ Plant │ 8 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  ancient_oak.setCardDisp(cDisp);
  ancient_oak.setCardName("Ancient Oak");
  ancient_oak.setCardClass(getType(0));
  ancient_oak.setCardMinType(getType(9));
  ancient_oak.setCardNum(2);
  ancient_oak.setCardText(2);
  ancient_oak.setCardCost(6);
  ancient_oak.setCardAtk(8);
  ancient_oak.setCardHth(8);
  ancient_oak.setCardMaxHth(8);

  /* Deadly Rose 003 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Deadly Rose  │\n";
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
  deadly_rose.setCardDisp(cDisp);
  deadly_rose.setCardName("Deadly Rose");
  deadly_rose.setCardClass(getType(0));
  deadly_rose.setCardType(getType(4));
  deadly_rose.setCardMinType(getType(9));
  deadly_rose.setCardNum(3);
  deadly_rose.setCardText(3);
  deadly_rose.setCardCost(3);
  deadly_rose.setCardAtk(3);
  deadly_rose.setCardHth(3);
  deadly_rose.setCardMaxHth(3);

  /* Toxic Rose Bush 004 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Toxic Rose Bush│\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 6 │ Plant │ 6 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  toxic_rosebush.setCardDisp(cDisp);
  toxic_rosebush.setCardName("Toxic Rose Bush");
  toxic_rosebush.setCardClass(getType(0));
  toxic_rosebush.setCardMinType(getType(9));
  toxic_rosebush.setCardNum(4);
  toxic_rosebush.setCardText(4);
  toxic_rosebush.setCardCost(5);
  toxic_rosebush.setCardAtk(6);
  toxic_rosebush.setCardHth(6);
  toxic_rosebush.setCardMaxHth(6);
  
  /* Lava Dragon 005 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Lava Dragon  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 7 │       │ 6 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  dragon_lava.setCardDisp(cDisp);
  dragon_lava.setCardName("Lava Dragon");
  dragon_lava.setCardClass(getType(0));
  dragon_lava.setCardMinType(getType(11));
  dragon_lava.setCardNum(5);
  dragon_lava.setCardText(5);
  dragon_lava.setCardCost(5);
  dragon_lava.setCardAtk(7);
  dragon_lava.setCardHth(6);
  dragon_lava.setCardMaxHth(6);
  
  /* Oceans Dragon 006 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Oceans Dragon │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│   * * * * *   │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 6 │       │ 7 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  dragon_oceans.setCardDisp(cDisp);
  dragon_oceans.setCardName("Oceans Dragon");
  dragon_oceans.setCardClass(getType(0));
  dragon_oceans.setCardMinType(getType(11));
  dragon_oceans.setCardNum(6);
  dragon_oceans.setCardText(6);
  dragon_oceans.setCardCost(5);
  dragon_oceans.setCardAtk(6);
  dragon_oceans.setCardHth(7);
  dragon_oceans.setCardMaxHth(7);
   
  /* Phoenix Ash 007 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Phoenix Ash  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 0 │       │ 1 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  phoenix_ash.setCardDisp(cDisp);
  phoenix_ash.setCardName("Phoenix Ash");
  phoenix_ash.setCardClass(getType(0));
  phoenix_ash.setCardType(getType(4));
  phoenix_ash.setCardMinType(getType(11));
  phoenix_ash.setCardNum(7);
  phoenix_ash.setCardText(7);
  phoenix_ash.setCardCost(0);
  phoenix_ash.setCardAtk(0);
  phoenix_ash.setCardHth(1);
  phoenix_ash.setCardMaxHth(1);
  
  /* Yin-Yang Koi 008 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│ Yin-Yang  Koi │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 4 │ Beast │ 4 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  yinyang_koi.setCardDisp(cDisp);
  yinyang_koi.setCardName("Yin-Yang Koi");
  yinyang_koi.setCardClass(getType(0));
  yinyang_koi.setCardType(getType(4));
  yinyang_koi.setCardMinType(getType(8));
  yinyang_koi.setCardNum(8);
  yinyang_koi.setCardText(8);
  yinyang_koi.setCardCost(3);
  yinyang_koi.setCardAtk(4);
  yinyang_koi.setCardHth(4);
  yinyang_koi.setCardMaxHth(4);

  /* Hydra Head 009 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Hydra  Head  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│       *       │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │ Beast │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  hydra_head.setCardDisp(cDisp);
  hydra_head.setCardName("Hydra Head");
  hydra_head.setCardClass(getType(0));
  hydra_head.setCardMinType(getType(8));
  hydra_head.setCardNum(9);
  hydra_head.setCardText(9);
  hydra_head.setCardCost(1);
  hydra_head.setCardAtk(2);
  hydra_head.setCardHth(2);
  hydra_head.setCardMaxHth(2);

  /* Chimera - Bear Head 010 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Bear Head   │\n";
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
  chim_bear.setCardDisp(cDisp);
  chim_bear.setCardName("Bear Head");
  chim_bear.setCardClass(getType(0));
  chim_bear.setCardMinType(getType(8));
  chim_bear.setCardNum(10);
  chim_bear.setCardText(10);
  chim_bear.setCardCost(2);
  chim_bear.setCardAtk(2);
  chim_bear.setCardHth(3);
  chim_bear.setCardMaxHth(3);

  /* Chimera - Lion Head 011 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Lion Head   │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │ Beast │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  chim_lion.setCardDisp(cDisp);
  chim_lion.setCardName("Lion Head");
  chim_lion.setCardClass(getType(0));
  chim_lion.setCardMinType(getType(8));
  chim_lion.setCardNum(11);
  chim_lion.setCardText(11);
  chim_lion.setCardCost(2);
  chim_lion.setCardAtk(2);
  chim_lion.setCardHth(2);
  chim_lion.setCardMaxHth(2);

  /* Chimera - Eagle Head 012 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Eagle  Head  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 3 │ Beast │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  chim_eagle.setCardDisp(cDisp);
  chim_eagle.setCardName("Eagle Head");
  chim_eagle.setCardClass(getType(0));
  chim_eagle.setCardMinType(getType(8));
  chim_eagle.setCardNum(12);
  chim_eagle.setCardText(12);
  chim_eagle.setCardCost(2);
  chim_eagle.setCardAtk(3);
  chim_eagle.setCardHth(2);
  chim_eagle.setCardMaxHth(2);

  /* Fly 013 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│      Fly      │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 1 │       │ 1 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  fly.setCardDisp(cDisp);
  fly.setCardName("Fly");
  fly.setCardClass(getType(0));
  fly.setCardMinType(getType(11));
  fly.setCardNum(13);
  fly.setCardText(13);
  fly.setCardCost(0);
  fly.setCardAtk(1);
  fly.setCardHth(1);
  fly.setCardMaxHth(1);

  /* Skeleton 014 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│   Skeleton    │\n";
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
  skeleton.setCardDisp(cDisp);
  skeleton.setCardName("Skeleton");
  skeleton.setCardClass(getType(0));
  skeleton.setCardMinType(getType(7));
  skeleton.setCardNum(14);
  skeleton.setCardText(14);
  skeleton.setCardCost(1);
  skeleton.setCardAtk(1);
  skeleton.setCardHth(1);
  skeleton.setCardMaxHth(1);

  /* Charmed Zombie 015 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│Charmed  Zombie│\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│     * * *     │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 3 │ Umbra │ 3 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  charmed_zombie.setCardDisp(cDisp);
  charmed_zombie.setCardName("Charmed Zombie");
  charmed_zombie.setCardClass(getType(0));
  charmed_zombie.setCardType(getType(4));
  charmed_zombie.setCardMinType(getType(7));
  charmed_zombie.setCardNum(15);
  charmed_zombie.setCardText(15);
  charmed_zombie.setCardCost(3);
  charmed_zombie.setCardAtk(3);
  charmed_zombie.setCardHth(3);
  charmed_zombie.setCardMaxHth(3);

  /* Gold Statue 016 */
  cDisp = "┌───────────────┐\n";
  cDisp+= "│  Gold Statue  │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "│               │\n";
  cDisp+= "├───────────────┤\n";
  cDisp+= "│      * *      │\n";
  cDisp+= "├───┐       ┌───┤\n";
  cDisp+= "│ 2 │       │ 2 │\n";
  cDisp+= "└───┴───────┴───┘\n";
  gold_statue.setCardDisp(cDisp);
  gold_statue.setCardName("Gold Statue");
  gold_statue.setCardMinType(getType(11));
  gold_statue.setCardNum(16);
  gold_statue.setCardText(16);
  gold_statue.setCardCost(2);
  gold_statue.setCardAtk(2);
  gold_statue.setCardHth(2);
  gold_statue.setCardMaxHth(2);
}
string ExCardDB::getType(int typeElement) const
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
Card ExCardDB::getExCDB_Card(int card_num) const
{
  switch(card_num)
  {
    case 1:  return forest_treant;
    case 2:  return ancient_oak;
    case 3:  return deadly_rose;
    case 4:  return toxic_rosebush;
    case 5:  return dragon_lava;
    case 6:  return dragon_oceans;
    case 7:  return phoenix_ash;
    case 8:  return yinyang_koi;
    case 9:  return hydra_head;
    case 10: return chim_bear;
    case 11: return chim_lion;
    case 12: return chim_eagle;
    case 13: return fly;
    case 14: return skeleton;
    case 15: return charmed_zombie;
    case 16: return gold_statue;
    default: return empty;
  }
}
void ExCardDB::cardCount(vector<int>& costCount, vector<int>& typeCount)
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
    cardTemp = getExCDB_Card(i);
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
void ExCDB_PrintInfo(ExCardDB ExCDB)
{
  vector<int> costCount(7);
  vector<int> typeCount(17);
  ExCDB.cardCount(costCount,typeCount);
  cout << "Cost Count\n";
  for (int i = 0; i < costCount.size(); i++)
    cout << "[" << i << "]  " << costCount[i] << endl;
  cout << endl << "Type Count\n";
  for (int i = 0; i < typeCount.size(); i++)
  {
    cout << "[" << i << "] " << ExCDB.getType(i) << ": "
         << typeCount[i] << endl;
    if(i == 2 || i == 5 || i == 11 || i == 14)
      cout << endl;
  }
  cout << endl << "Total: " << ExCDB.totalCards << endl << endl;
  return;
}