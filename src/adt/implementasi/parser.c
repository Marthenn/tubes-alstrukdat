// C libraries
#include <math.h>

// headers
#include "../headers/boolean.h"
#include "../headers/wordmachine.h"
#include "../headers/parser.h"

#include <stdio.h>

Word NewWord(char* s, int length)
// mengembalikan data Word dengan panjang length dan karakter-karakter beserta urutannya sama dengan pada array s

{
    // KAMUS LOKAL
    Word kata;
    int i;
    // ALGORITMA

    for (i = 0; i < length; i++)
    {
        kata.TabWord[i] = s[i];
    }

    kata.Length = length;

    return kata;
}

boolean IsInputEqual(Word kata)
// mengembalikan true jika kata sama dengan currentWord (tidak case-sensitive)
{
    return IsWordEqual(kata, currentWord);
}

boolean IsInputPrefixEqual(Word kata)
// mengembalikan true jika kata sama dengan prefix currentWord (tidak case-sensitive)
{
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    if (kata.Length > currentWord.Length)
    {
        return false;
    }

    for (i = 0; i < kata.Length; i++)
    {
        if ((kata.TabWord[i] != currentWord.TabWord[i]) && (kata.TabWord[i] + GAP != currentWord.TabWord[i]))
        {
            return false;
        }
    }

    return true;

    
}

boolean IsWordEqual(Word kata1, Word kata2)
// mengembalikan true jika kata1 sama dengan kata2 (tidak case-sensitive)
{
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    if (kata1.Length != kata2.Length)
    {
        return false;
    }

    for (i = 0; i < kata1.Length; i++)
    {
        if ((kata1.TabWord[i] != kata2.TabWord[i]) && (kata1.TabWord[i] + GAP != kata2.TabWord[i]))
        {
            return false;
        }
    }

    return true;
}

int WordToInt(Word kata)
// mengembalikan representasi integer dari kata atau mengembalikan NUM_UNDEF jika input bukan angka atau banyak digit lebih besar dari 9
{
    // KAMUS LOKAL
    int i, res;

    //ALGORITMA

    res = 0;

    for (i = 0; i < kata.Length; i++)
    { 
        if(kata.TabWord[i] < NUM_CHAR_MIN || kata.TabWord[i] > NUM_CHAR_MAX || i > MAX_DIGIT) 
        {
            return NUM_UNDEF;

        }
        res = (res * 10) + (kata.TabWord[i] - NUM_CHAR_MIN);
    }

    return res;
}

void ConcatWord(Word *kata1, Word kata2)
{
    // KAMUS LOKAL
    int i;
    boolean overflow;

    // ALGORITMA

    overflow = false;

    for (i = 0; i < kata2.Length; i++)
    {
        if (i + kata1->Length < NMax)
        {
            kata1->TabWord[i + kata1->Length] = kata2.TabWord[i];
        }

        else {
            kata1->Length = NMax;
            overflow = true;
            break;
        }
    }

    if (overflow == false)
    {
        kata1->Length += kata2.Length;
    }
    
}

void CopyDefinedWord(Word *kata1, Word kata2)
// I.S. kata1 sembarang
// F.S. kata1 memiliki panjang dan karakter-karakter yang sama dengan kata2
{
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    kata1->Length = kata2.Length;

    for (i = 0; i < kata2.Length; i++)
    {
        kata1->TabWord[i] = kata2.TabWord[i];
    }
}

void DisplayWord(Word kata)
// I.S. kata terdefinisi
// F.S. kata ditampilkan ke layar 
{
    // KAMUS LOKAL
    int i;

    // ALGORITMA

    for (i = 0; i < kata.Length; i++)
    {
        printf("%c", kata.TabWord[i]);
    }
}

void DisplayWordLine(Word kata)
// I.S. kata terdefinisi 
// F.S. kata ditampilkan ke layar dengan new line di akhir
{
    DisplayWord(kata);
    printf("\n");
}

ListStatik SplitWord(Word kata, char separator)
// mengembalikan list berisi subkata yang dipisahkan karakter separator
{
    // KAMUS LOKAL
    ListStatik l;
    Word subkata, copiedKata;
    int i, count, elmtCount;

    // ALGORITMA
    i = 0;

    while(i < kata.Length && ListLength(l) < CAPACITY)
    {
        while(kata.TabWord[i] == separator && i < kata.Length)
        {
            i++;
        }

        count = 0;
        while(kata.TabWord[i] != separator && i < kata.Length)
        {
            subkata.TabWord[count] = kata.TabWord[i];
            count++;
            i++;
        }

        if (count > 0)
        {
            subkata.Length = count;
            CopyDefinedWord(&copiedKata, subkata);
            InsertFirst(&l,NewElType(4, (union Data){.w=copiedKata}));
        }
    }

    return l;
}

