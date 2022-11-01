/* File : filereader.h */

// C libraries
#include <stdio.h>

/* ADT */
#include "../../adt/eltype/eltype.h"
#include "../../adt/matriks/matriks.h"
#include "../../adt/tree/tree.h"

/* APP */
#include "../parser/parser.h"
#include "filereader.h"


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
    Word kata, judul, hari, jam, menit, aksi;
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
            aksi = BUY_WORD;
        }
        
        else if (IsWordEqual(kata, MIX_WORD))
        {
            actionPoint = M(*map);
            aksi = MIX_WORD;
        }

        else if (IsWordEqual(kata, CHOP_WORD))
        {
            actionPoint = C(*map);
            aksi = CHOP_WORD;
        }

        else if (IsWordEqual(kata, FRY_WORD))
        {
            actionPoint = F(*map);
            aksi = FRY_WORD;
        }

        else if (IsWordEqual(kata, BOIL_WORD))
        {
            actionPoint = B(*map);
            aksi = BOIL_WORD;
        }

        CreateMakanan(&food, id, judul, expiredTime, deliveryTime, aksi, actionPoint);
        foodElement = NewElType(3, (union Data){.m=food});
        idx = ListIndexOf(*l, foodElement);
        
        if (idx == LISTSTATIK_IDX_UNDEF && ListLength(*l) < LISTSTATIK_CAP)
        {
            ListInsertLast(l, foodElement);
        }
        
        else {
            LIST_ELMT(*l, idx) = foodElement;
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
        }
    }
}

void ReadRecipeConfig(ListStatik *recipes)
{
    // KAMUS LOKAL

    int parentIdx, childIdx, n, i, j, id, childrenNum;
    Tree parent, child;
    Address newNode;

    // ALGORITMA
    CreateListStatik(recipes);
    STARTFILEWORD(RECIPE_CONFIG_PATH);
    ReadIntLine(&n);

    for (i = 0; i < n; i++)
    {
        ReadInt(&id);
        ReadInt(&childrenNum);

        parentIdx = ListIndexOf(*recipes, NewElType(1, (union Data){.i=id}));

        if (parentIdx == LISTSTATIK_IDX_UNDEF)
        {
            parent = NewTree(id);
        }

        else
        {
            parent = GetVal(LIST_ELMT(*recipes, parentIdx)).t;

        }

        for (j = 0; j < childrenNum; j++)
        {
            ReadInt(&id);

            childIdx = ListIndexOf(*recipes, NewElType(1, (union Data){.i=id}));

            if (childIdx == LISTSTATIK_IDX_UNDEF)
            {
                AddChild(&parent, id, &newNode);
                ListInsertLast(recipes, NewElType(5, (union Data){.t=newNode}));
            }

            else {
                AddChildNode(&parent, GetVal(LIST_ELMT(*recipes, childIdx)).t);
            }
        }

        // insert new recipe tree if parent is not found
        if (parentIdx == LISTSTATIK_IDX_UNDEF)
        {
            ListInsertLast(recipes, NewElType(5, (union Data){.t=parent}));
        }   
        
        // should be end of line in the file
        NextLine();
    }

}

void ReadAllConfig(Map *map, ListStatik *foods, ListStatik *recipes)
{
    // KAMUS LOKAL

    // ALGORITMA
    ReadMapConfig(map);
    ReadFoodConfig(foods, map);
    ReadRecipeConfig(recipes);

}