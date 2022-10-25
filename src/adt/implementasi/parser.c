// headers
#include "../headers/boolean.h"
#include "../headers/wordmachine.h"

#include <stdio.h>
Word currentWord;

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

boolean IsPrefixEqual(Word kata)
// mengembalikan true jika kata sama dengan currentWord (tidak case-sensitive)
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

