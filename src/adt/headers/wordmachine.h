/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

/* ADT */
#include "boolean.h"
#include "charmachine.h"


#define NMax 100
#define BLANK '\n'
#define FILE_BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean EndWord, EndFileWord;
extern Word currentWord, currentFileWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar BLANK atau MARK yang terletak setelah kata yang diakuisisi */

void ADVWORD();
/* I.S. : currentChar BLANK atau MARK
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar BLANK atau MARK yang terletak setelah kata yang diakuisisi
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar BLANK atau MARK yang terletak setelah kata yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void IgnoreFileBlanks();
/* Mengabaikan satu atau beberapa FILE_BLANK dalam file txt
   I.S. : currentFileChar sembarang
   F.S. : currentFileChar ≠ BLANK atau currentFileChar = '\n' */

void STARTFILEWORD(char *path);
/* I.S. : currentFileChar sembarang
   F.S. : EndFileWord = true, dan mesin kata mencapai EOF;
          atau EndFileWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentFileChar karakter pertama sesudah karakter terakhir kata */

void ADVFILEWORD();
/* I.S. : currentFileChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentFileChar adalah karakter pertama dari kata berikutnya, mungkin mencapai EOF
          Jika EOF, EndFileWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyFileWord */

void CopyFileWord();
/* Mengakuisisi kata, menyimpan dalam currentFileWord
   I.S. : currentFileChar adalah karakter pertama dari kata
   F.S. : currentFileWord berisi kata yang sudah diakuisisi;
          currentFileChar = BLANK atau mesin karakter mencapai EOF;
          currentFileChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

#endif
