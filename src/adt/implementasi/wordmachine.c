/* File: wordmachine.c */
/* Definisi Word Machine: Model Akuisisi Versi I */

// headers
#include "../headers/boolean.h"
#include "../headers/charmachine.h"
#include "../headers/wordmachine.h"

// implementations
#include "../implementasi/charmachine.c"

/* State Mesin Word */
char currentChar, currentFileChar;
boolean EOP, FILE_EOP;

boolean EndWord, EndFileWord;
Word currentWord, currentFileWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
	// KAMUS LOKAL
	// ALGORITMA
	
	while(currentChar == BLANK)
	{
		ADV();
	}
}
void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
	// KAMUS LOKAL
	// ALGORITMA
	
	START();
	IgnoreBlanks();
	
	if (currentChar == MARK)
	{
		EndWord = true;
	}
	
	else {
		EndWord = false;
		
		CopyWord();
	}

}
void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
	// KAMUS LOKAL
	// ALGORITMA
	
	IgnoreBlanks();

	if (currentChar == MARK)
	{
		EndWord = true;
	}
	
	else {		
		CopyWord();
	}	
}
void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	// KAMUS LOKAL
	int i;
	// ALGORITMA
	
	i = 0;
	while ((currentChar != MARK) && (currentChar != BLANK)) 
	{
		if (i < NMax)
		{
			currentWord.TabWord[i] = currentChar;
			i++;
		}
		ADV();
	}
	
	currentWord.Length = i;
}

void IgnoreFileBlanks()
/* Mengabaikan satu atau beberapa BLANK dalam file txt
   I.S. : currentFileChar sembarang
   F.S. : currentFileChar ≠ FILE_BLANK atau currentFileChar = MARK */

{
	// KAMUS LOKAL
	// ALGORITMA
	
	while(currentFileChar == FILE_BLANK)
	{
		ADV_FILE();
	}
}

void STARTFILEWORD(char *path)
/* I.S. : currentFileChar sembarang
   F.S. : EndFileWord = true, dan currentFileChar = MARK;
          atau EndFileWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentFileChar karakter pertama sesudah karakter terakhir kata */
{
	// KAMUS LOKAL

	// ALGORITMA

	START_FILE(path);
	IgnoreFileBlanks();

	if (FILE_EOP)
	{
		EndFileWord = true;
	}
	
	else {
		EndFileWord = false;
		
		CopyFileWord();
	}
}

void ADVFILEWORD()
/* I.S. : currentFileChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentFileChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentFileChar = MARK, EndFileWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyFileWord */
{
	// KAMUS LOKAL

	// ALGORITMA

	if (FILE_EOP)
	{
		EndFileWord = true;
	}
	
	else {		
		CopyFileWord();
	}	
}

void CopyFileWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentFileChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentFileChar = BLANK atau currentFileChar = MARK;
          currentFileChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	// KAMUS LOKAL
	int i;
	// ALGORITMA
	
	i = 0;
	while ((FILE_EOP == false) && (currentFileChar != FILE_BLANK) && (currentFileChar != '\n')) 
	{
		if (i < NMax)
		{
			currentFileWord.TabWord[i] = currentFileChar;
			i++;
		}

		ADV_FILE();
	}
	
	currentFileWord.Length = i;

	IgnoreFileBlanks();
}
