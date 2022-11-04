/* C libraries */
#include <stdlib.h>
/* ADT */
#include "../../boolean.h"
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
	//KAMUS LOKAL
	
	//ALGORITMA
	StackTop(*S) = STACK_NIL;
	free(StackTab(*S));
	StackTab(*S) = (Record*) malloc(0);
	StackCap(*S) = 0;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	//KAMUS LOKAL
	//ALGORITMA
	
	if (StackTop(S) == STACK_NIL)
	{
		return true;
	}
	
	return false;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stack * S, Record X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	//KAMUS LOKAL
	//ALGORITMA
	
	StackTop(*S)++;

	if (StackTop(*S) == StackCap(*S))
	{
		ExpandStack(S);
	}

	StackTab(*S)[StackTop(*S)] = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack * S, Record* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	//KAMUS LOKAL
	//ALGORITMA
	
	*X = StackInfoTop(*S);

	if (StackTop(*S) <= StackCap(*S) / 4)
	{
		ShrinkStack(S);
	}

	StackTop(*S)--;
	
}

void ExpandStack(Stack *S)
{
	// KAMUS LOKAL
    int newCap;
    // ALGORITMA
    
    newCap = StackCap(*S) * 3 / 2;

    if (newCap == StackCap(*S))
    {
        newCap++;
    }
    StackTab(*S) = realloc(StackTab(*S), newCap * sizeof(Record));
    StackCap(*S) = newCap;
}

void ShrinkStack(Stack *S)
{
	int newCap = StackCap(*S) / 2;

	StackTab(*S) = realloc(StackTab(*S), newCap * sizeof(Record));
    StackCap(*S) = newCap;

}
