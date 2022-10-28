/* File : filereader.h */

// C libraries
#include <stdio.h>

/* ADT */
#include "../../adt/headers/makanan.h"
#include "../../adt/headers/waktu.h"
#include "../../adt/headers/wordmachine.h"
#include "../../adt/headers/eltype.h"
#include "../../adt/headers/matriks.h"
#include "../../adt/headers/liststatik.h"
#include "../../adt/headers/map.h"

/* APP */
#include "../headers/parser.h"
#include "../headers/filereader.h"


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

void ReadFoodConfig(ListStatik *l, Map *map)
{
    // KAMUS LOKAL
    Makanan food;
    ElType foodElement;
    Word kata, judul, hari, jam, menit;
    int N, i, id, idx;
    Waktu expiredTime, deliveryTime;
    Point actionPoint;

    // ALGORITMA

    CreateListStatik(l);
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
        CREATE_POINT_UNDEF(actionPoint);
        
        if (IsWordEqual(kata, BUY_WORD))
        {
            actionPoint = T(*map);
        }
        
        else if (IsWordEqual(kata, MIX_WORD))
        {
            actionPoint = M(*map);
        }

        else if (IsWordEqual(kata, CHOP_WORD))
        {
            actionPoint = C(*map);
        }

        else if (IsWordEqual(kata, FRY_WORD))
        {
            actionPoint = F(*map);
        }

        else if (IsWordEqual(kata, BOIL_WORD))
        {
            actionPoint = B(*map);
        }

        CreateMakanan(&food, id, judul, expiredTime, deliveryTime, actionPoint);
        foodElement = NewElType(3, (union Data){.m=food});
        idx = ListIndexOf(*l, foodElement);
        
        if (idx == IDX_UNDEF && ListLength(*l) < CAPACITY)
        {
            ListInsertLast(l, foodElement);
        }
        
        else {
            l->contents[idx] = foodElement;
        }
    }
    
}

void ReadMapConfig(Map *map)
{
    // KAMUS LOKAL
    int i, j, n, m;
    Word kata;
    char cc;
    // ALGORITMA

    STARTFILEWORD(MAP_CONFIG_PATH);
    ReadInt(&n);
    ReadInt(&m);
    NextLine();
    CreateMatriks(n, m, &TAB(*map));

    for (i = 0; (i < n && i < ROW_CAP); i++)
    {
        ReadLine(&kata);
        
        for (j = 0; (j < m && j < COL_CAP); j++)
        {
            cc = kata.TabWord[j];

            MAT_ELMT(TAB(*map), i, j) = cc;

            if (cc == 'S' || cc == 's')
            {  
                CreatePoint(&S(*map), i, j);
            }

            else if (cc == 'T' || cc == 't')
            {
                CreatePoint(&T(*map), i, j);
            }

            else if (cc == 'M' || cc == 'm')
            {
                CreatePoint(&M(*map), i, j);
            }

            else if (cc == 'C' || cc == 'c')
            {
                CreatePoint(&C(*map), i, j);
            }

            else if (cc == 'F' || cc == 'f')
            {
                CreatePoint(&F(*map), i, j);
            }

            else if (cc == 'B' || cc == 'b')
            {
                CreatePoint(&B(*map), i, j);
            }

            else if (cc == 'X' || cc == 'x')
            {
                CreatePoint(&X(*map), i, j);
            }
        }
    }
}

void ReadAllConfig(Map *map, ListStatik *foods, ListStatik *recipes)
{
    // KAMUS LOKAL

    // ALGORITMA
    ReadMapConfig(map);
    ReadFoodConfig(foods, map);
    // ReadRecipeConfig(recipes);

}