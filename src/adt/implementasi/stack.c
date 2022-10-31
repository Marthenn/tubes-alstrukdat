/* ADT */
#include "../headers/boolean.h"
#include "../headers/stack.h"

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
	CreateListDin(&StackTab(*S), 0);
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
void PushStack(Stack * S, int X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	//KAMUS LOKAL
	//ALGORITMA
	
	StackTop(*S)++;
	InsertLastListDin(&StackTab(*S), X);
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack * S, int* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	//KAMUS LOKAL
	//ALGORITMA
	
	DeleteLastListDin(&StackTab(*S), X);
	StackTop(*S)--;
}
