/* File : filereader.h */

// C libraries
#include <stdio.h>
// headers
#include "../headers/filereader.h"
#include "../headers/parser.h"
#include "../headers/makanan.h"
#include "../headers/waktu.h"
#include "../headers/wordmachine.h"
#include "../headers/eltype.h"
#include "../headers/matriks.h"
//implementation
#include "parser.c"
#include "makanan.c"
#include "point.c"
#include "waktu.c"
#include "wordmachine.c"
#include "eltype.c"
#include "matriks.c"

boolean EndFileWord;
Word currentFileWord;

void STARTFILELINE(Word *kata, char *path)
/* I.S. : currentFileChar sembarang
   F.S. : EndFileWord = true, dan proses pembacaan mesin kata mencapai EOF;
          atau EndFileWord = false, currentFileWord adalah kata pertama pada baris selanjutnya,
          currentFileChar karakter pertama (bukan blank) setelah kata pertama pada baris selanjutnya*/
{
    // KAMUS LOKAL

    // ALGORITMA
    STARTFILEWORD(path);
    ReadLine(kata);

}

void NextLine()
// I.S. currentFileChar == '\n'
// F.S. currentFileChar merupakan karakter pertama setelah kata pertama pada baris selanjutnya, currentFileWord merupakan kata pertama pada baris selanjutnya
{
    ADV_FILE();
    IgnoreFileBlanks();
    ADVFILEWORD();
}

void ReadLine(Word *kata)
// I.S. kata sembarang, currentFileWord terdefinisi
// F.S. kata berisi string pada satu baris pada file yang sedang dibaca, currentFileWord merujuk ke Word pertama pada baris selanjutnya atau EOF
// proses : currentFileWord disalin ke variable. Kemudian, semua Word selanjutnya yang berada dalam satu baris di konkatenasi di akhir kata variable tersebut
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

        else if (FILE_EOP == false) {
            ConcatWord(kata, BLANK_WORD);
        }

        ADVFILEWORD();
    }
}

void ReadIntLine(int *num)
// I.S. nilai num sembarang;
// F.S. nilai num merupakan representasi integer dari Word yang ada pada line saat ini pada file yang sedang dibaca, mesin kata dan mesin karakter menuju line berikutnya.
// nilai num == NUM_UNDEF jika kata dalam satu line tidak dapat direpresentasikan sebagai integer
{
    Word kata;

    ReadLine(&kata);
    *num = WordToInt(kata);
}

void ReadInt(int *num)
// I.S. nilai num sembarang
// F.S. nilai num merupakan representasi integer dari currentFileWord, mesin karakter mengakuisisi kata selanjutnya
{
    *num = WordToInt(currentFileWord);
    ADVFILEWORD();
}

void ReadTime(Waktu *time)

// I.S. nilai komponen pada time sembarang;
// F.S. time merupakan representasi waktu dari baris yang sedang dibaca, mesin kata dan mesin karakter menuju line berikutnya.
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

    CreateWaktu(time, h, j, m);

    // currentFileChar should be '\n'
    NextLine();
}

void ReadFoodConfig()
{
    // KAMUS LOKAL
    Makanan food;
    Word kata, judul, hari, jam, menit;
    int N, i, id;
    Waktu expiredTime, deliveryTime;
    Point actionPoint;
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
        
        CreatePoint(&actionPoint, 0, 0);

        CreateMakanan(&food, id, judul, expiredTime, deliveryTime, actionPoint);

        printf("Makanan ke-%d\n", i+1);
        DisplayMakanan(food);
    }
    
}
void ReadRecipeConfig()
{
    // KAMUS LOKAL

    // ALGORITMA
}

void ReadMapConfig(Matriks *map)
{
    // KAMUS LOKAL
    int i, j, n, m;
    Word kata;
    // ALGORITMA

    STARTFILEWORD(MAP_CONFIG_PATH);
    ReadInt(&n);
    ReadInt(&m);
    NextLine();

    CreateMatriks(n, m, map);

    for (i = 0; i < n; i++)
    {
        ReadLine(&kata);
        
        
        for (j = 0; j < m; j++)
        {
            ELMT(*map, i, j) = NewElType(2, (union Data){.c=kata.TabWord[j]});
        }
    }
}

void ReadAllConfig(Matriks *map)
{
    // KAMUS LOKAL

    // ALGORITMA

    ReadMapConfig(map);
    ReadFoodConfig();
    ReadRecipeConfig();
}