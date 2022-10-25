/* File : filereader.h */

// C libraries
#include <stdio.h>
// headers
#include "../headers/filereader.h"

//implementation


boolean EndFileWord;
Word currentFileWord;

void ReadFoodConfig()
{
    // KAMUS LOKAL

    // ALGORITMA

    STARTFILEWORD(FOOD_CONFIG_PATH);

    while (EndFileWord == false)
    {
        DisplayWord(currentFileWord);
        printf("\n");
        ADVFILEWORD();
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

    ReadFoodConfig();
    ReadRecipeConfig();
    ReadMapConfig();
}