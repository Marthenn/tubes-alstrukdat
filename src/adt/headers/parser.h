/* File: parser.h */

#ifndef __PARSER_H__
#define __PARSER_H__

// headers
#include "boolean.h"
#include "wordmachine.h"
#include "liststatik.h"

// command constants
#define GAP 'a' - 'A'
#define START_WORD NewWord("START", 5)
#define EXIT_WORD NewWord("EXIT", 4)
#define BUY_WORD NewWord("BUY", 3)
#define DELIVERY_WORD NewWord("DELIVERY", 8)
#define MOVE_NORTH_WORD NewWord("MOVE NORTH", 10)
#define MOVE_EAST_WORD NewWord("MOVE EAST", 9)
#define MOVE_WEST_WORD NewWord("MOVE WEST", 9)
#define MOVE_SOUTH_WORD NewWord("MOVE SOUTH", 10)
#define MIX_WORD NewWord("MIX", 3)
#define CHOP_WORD NewWord("CHOP", 4)
#define FRY_WORD NewWord("FRY", 3)
#define BOIL_WORD NewWord("BOIL", 4)
#define WAIT_WORD NewWord("WAIT", 4)
#define UNDO_WORD NewWord("UNDO", 4)
#define REDO_WORD NewWord("REDO", 4)
#define WAIT_WORD NewWord("WAIT", 4)
#define CATALOG_WORD NewWord("CATALOG", 7)
#define COOKBOOK_WORD NewWord("COOKBOOK", 8)
#define EMPTY_WORD NewWord("", 0)
#define BLANK_WORD NewWord(" ", 1)

#define NUM_CHAR_MIN '0'
#define NUM_CHAR_MAX '9'
#define NUM_UNDEF -999
#define MAX_DIGIT 9

Word NewWord(char* s, int length);
// mengembalikan data Word dengan panjang length dan karakter-karakter beserta urutannya sama dengan pada array s

boolean IsInputEqual(Word kata);
// mengembalikan true jika kata sama dengan currentWord (tidak case-sensitive)

boolean IsInputPrefixEqual(Word kata);
// mengembalikan true jika kata sama dengan prefix currentWord (tidak case-sensitive)

boolean IsWordEqual(Word kata1, Word kata2);
// mengembalikan true jika kata1 sama dengan kata2 (tidak case-sensitive)

int WordToInt(Word kata);
// mengembalikan representasi integer dari kata atau mengembalikan NUM_UNDEF jika input bukan angka atau banyak digit lebih besar dari 9

void ConcatWord(Word *kata1, Word kata2);
// I.S. kata2 terdefinisi, kata1 dapat terdefinisi
// F.S. kata2 dikonkatenasi di akhir kata1

void CopyDefinedWord(Word *kata1, Word kata2);
// I.S. kata1 sembarang
// F.S. kata1 memiliki panjang dan karakter-karakter yang sama dengan kata2

void DisplayWord(Word kata);
// I.S. kata terdefinisi
// F.S. kata ditampilkan ke layar 


void DisplayWordLine(Word kata);
// I.S. kata terdefinisi 
// F.S. kata ditampilkan ke layar dengan new line di akhir

ListStatik SplitWord(Word kata, char separator);
// mengembalikan list berisi subkata yang dipisahkan karakter separator
#endif
