/* File : filereader.h */

#ifndef __FILEREADER_H__
#define __FILEREADER_H__

#include "wordmachine.h"

#define FOOD_CONFIG_PATH ".../config/food_config.txt"
#define RECIPE_CONFIG_PATH ".../config/recipe_config.txt"
#define MAP_CONFIG_PATH ".../config/map_config.txt"

void STARTFILELINE(Word *kata, char *path);
/* I.S. : currentFileChar sembarang
   F.S. : EndFileWord = true, dan currentFileChar = MARK;
          atau EndFileWord = false, currentWord adalah kata pertama pada baris selanjutnya,
          currentFileChar karakter pertama pada baris selanjutnya*/

void NextLine();
//

void ReadLine(Word *kata);
// I.S. kata belum terdefinisi, mesin kata sedang membaca file, currentFileWord terdefinisi
// F.S. kata berisi string satu baris pada file yang sedang dibaca, currentFileChar merujuk ke Word pertama pada file selanjutnya (bisa terjadi FILE_EOP == true)
// proses : currentFileWord disalin ke kata kemudian semua Word selanjutnya yang berada dalam satu baris di konkatenasi di akhir kata

void ReadFoodConfig();
void ReadRecipeConfig();
void ReadMapConfig();
void ReadAllConfig();

#endif