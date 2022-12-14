/* File : filereader.h */

#ifndef __FILEREADER_H__
#define __FILEREADER_H__

// ADT
#include "../../adt/waktu/waktu.h"
#include "../../adt/map/map.h"
#include "../../adt/liststatik/liststatik.h"
#include "../../adt/makanan/makanan.h"
#include "../../adt/wordmachine/wordmachine.h"

#define FOOD_CONFIG_PATH "src/config/food_config.txt"
#define RECIPE_CONFIG_PATH "src/config/recipe_config.txt"
#define MAP_CONFIG_PATH "src/config/map_config.txt"

void STARTFILELINE(Word *kata, char *path);
/* I.S. : currentFileChar sembarang
   F.S. : EndFileWord = true, dan proses pembacaan mesin kata mencapai EOF;
          atau EndFileWord = false, currentFileWord adalah kata pertama pada baris selanjutnya,
          currentFileChar karakter pertama (bukan blank) setelah kata pertama pada baris selanjutnya*/

void NextLine();
// I.S. currentFileChar == '\n'
// F.S. currentFileChar merupakan karakter pertama setelah kata pertama pada baris selanjutnya, currentFileWord merupakan kata pertama pada baris selanjutnya

void ReadLine(Word *kata);
// I.S. kata sembarang, currentFileWord terdefinisi
// F.S. kata berisi string pada satu baris pada file yang sedang dibaca, currentFileWord merujuk ke Word pertama pada baris selanjutnya atau EOF
// proses : currentFileWord disalin ke variable. Kemudian, semua Word selanjutnya yang berada dalam satu baris di konkatenasi di akhir kata variable tersebut

void ReadIntLine(int *num);
// I.S. nilai num sembarang;
// F.S. nilai num merupakan representasi integer dari Word yang ada pada line saat ini pada file yang sedang dibaca, mesin kata dan mesin karakter menuju line berikutnya.
// nilai num == NUM_UNDEF jika kata dalam satu line tidak dapat direpresentasikan sebagai integer

void ReadInt(int *num);
// I.S. nilai num sembarang
// F.S. nilai num merupakan representasi integer dari currentFileWord, mesin karakter mengakuisisi kata selanjutnya

void ReadTime(Waktu *time);

// I.S. nilai komponen pada time sembarang;
// F.S. time merupakan representasi waktu dari baris yang sedang dibaca, mesin kata dan mesin karakter menuju line berikutnya.

void ReadFoodConfig(ListStatik *l, Map *map);
// I.S. 
void ReadRecipeConfig(ListStatik *recipes);
void ReadMapConfig(Map *map);
void ReadAllConfig(Map *map, ListStatik *foods, ListStatik *recipes);

#endif