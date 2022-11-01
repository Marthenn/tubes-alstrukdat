/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

/* ADT */
#include "../../boolean.h"
#include "../point/point.h"
#include "../prioqueue/prioqueue.h"
#define STACK_NIL -1

/* Nil adalah stack dengan elemen kosong . */

typedef int StackAddress;   /* indeks tabel */

typedef struct {
  PrioQueue InventoryAdd;
  PrioQueue DeliveryAdd;
  PrioQueue InventoryDel;
  PrioQueue DeliveryDel;
  Point SimulatorLoc;
  Waktu Time;
} Record;

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  Record* T; /* tabel penyimpan elemen */
  StackAddress TOP;  /* alamat TOP: elemen puncak */
  int CAP;
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define StackTop(S) (S).TOP
#define StackInfoTop(S) (S).T[StackTop((S))]
#define StackTab(S) (S).T
#define StackCap(S) (S).CAP

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stack * S, Record X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack * S, Record* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */


void ExpandStack(Stack *S);
void ShrinkStack(Stack *S);

#endif
