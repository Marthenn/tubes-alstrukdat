/* File : filereader.h */

// C libraries
#include <stdio.h>
// headers
#include "../headers/filereader.h"
#include "../headers/parser.h"
#include "../headers/makanan.h"
#include "../headers/waktu.h"
#include "../headers/wordmachine.h"
//implementation
#include "parser.c"
#include "makanan.c"
#include "point.c"
#include "waktu.c"
#include "wordmachine.c"

boolean EndFileWord;
Word currentFileWord;

void STARTFILELINE(Word *kata, char *path)
/* I.S. : currentFileChar sembarang
   F.S. : EndFileWord = true, dan currentFileChar = MARK;
          atau EndFileWord = false, currentWord adalah kata pertama pada baris selanjutnya,
          currentFileChar karakter pertama pada baris selanjutnya*/

{
    // KAMUS LOKAL

    // ALGORITMA
    STARTFILEWORD(path);
    ReadLine(kata);

}

void NextLine()
{
    ADV_FILE();
    IgnoreFileBlanks();
    ADVFILEWORD();
}

void ReadLine(Word *kata)
// I.S. kata belum terdefinisi, mesin kata sedang membaca file, currentFileWord terdefinisi
// F.S. kata berisi string satu baris pada file yang sedang dibaca, currentFileChar merujuk ke Word pertama pada file selanjutnya (bisa terjadi FILE_EOP == true)
// proses : currentFileWord disalin ke kata kemudian semua Word selanjutnya yang berada dalam satu baris di konkatenasi di akhir kata

{
    *kata = EMPTY_WORD; 

    while (EndFileWord == false)
    {

        ConcatWord(kata, currentFileWord);

        if (currentFileChar == '\n')
        {
            NextLine();
            break;
            
        }

        else {
            ConcatWord(kata, BLANK_WORD);
            ADVFILEWORD();
        }
    }
}

void ReadIntLine(int *num)
{
    Word kata;

    ReadLine(&kata);
    *num = WordToInt(kata);
}
void ReadTime(waktu *time)
{
    // KAMUS LOKAL
    int h, j, m;
    Word hari, jam, menit;

    // ALGORITMA
    
    CopyDefinedWord(&hari, currentFileWord);
    ADVFILEWORD();

    CopyDefinedWord(&jam, currentFileWord);
    ADVFILEWORD();

    CopyDefinedWord(&menit, currentFileWord);
    
    h = WordToInt(hari);
    j = WordToInt(jam);
    m = WordToInt(menit);

    createWaktu(time, h, j, m);

    // currentFileChar should be '\n'
    NextLine();
}

void ReadFoodConfig()
{
    // KAMUS LOKAL
    makanan food;
    Word kata, judul, hari, jam, menit;
    int N, i, id;
    waktu expiredTime, deliveryTime;
    point actionPoint;
    // ALGORITMA

    STARTFILELINE(&kata, FOOD_CONFIG_PATH);
    N = WordToInt(kata);

    for (i = 0; i < N; i++)
    {
        // read id
        ReadIntLine(&id);
        // read food name
        ReadLine(&judul);
    
        // read expired time
        ReadTime(&expiredTime);

        // read delivery time
        ReadTime(&deliveryTime);

        ReadLine(&kata);
        
        createPoint(&actionPoint, 0, 0);

        createMakanan(&food, id, judul, expiredTime, deliveryTime, actionPoint);

        printf("Makanan ke-%d\n", i+1);
        displayMakanan(food);
    }
    
}
void ReadRecipeConfig()
{
    // KAMUS LOKAL

    // ALGORITMA
}

void ReadMapConfig()
{
    // KAMUS LOKAL

    // ALGORITMA
}

void ReadAllConfig()
{
    // KAMUS LOKAL

    // ALGORITMA

    ReadMapConfig();
    ReadFoodConfig();
    ReadRecipeConfig();
}