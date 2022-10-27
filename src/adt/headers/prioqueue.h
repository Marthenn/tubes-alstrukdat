/* File : prioqueue.h */
/* Definisi Priority Queue versi 2 dengan list dinamik */
/* Elemen priority queue berupa makanan*/

#ifndef prioqueue_H
#define prioqueue_H

#include "boolean.h"
#include "makanan.h"

#define Nil -1
#define DEF_SIZE 20
typedef int Index;
typedef Makanan ElType;

typedef struct {
    Waktu Time;
    ElType Info;
} infotype;

typedef struct{
    infotype * Tab;
    Index Head;
    Index Tail;
    int Cap;
} PrioQueue;

/* **** Getter **** */
ElType GetHeadInfo(PrioQueue Q);
/* Mengembalikan elemen pada Head */

ElType GetElmtPQ(PrioQueue Q,int idx);
/* Mengembalikan elemen indeks ke-idx secara logikal pada Q. idx = 0 adalah Head */
/* idx berada pada rentang [0..length(Q)] */

/* ********* Prototype ********* */
boolean IsEmptyPQ (PrioQueue Q);
/* Mengirim true jika Q kosong*/

boolean IsFullPQ (PrioQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak Cap */

int LengthPQ (PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmptyPQ(PrioQueue* Q);
/* Melakukan alokasi, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran DEF_SIZE */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */

/* *** Destruktor *** */
void DeallocatePQ(PrioQueue * Q);
/* Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi*/

/* *** Realokator ** */
void ReallocatePQ(PrioQueue * Q, int newCap);
/* Mengalokasi ulang kapasitas Q */
/* I.S. Q terdefinisi. Jika newCap lebih kecil dari kapasitas sebelumnya, maka haruslah length(Q) <= newCap */
/* F.S  Kapasitas Q menjadi newCap. Jika pada saat penambahan kapasitas gagal, maka ukuran Q tidak berubah dan
        pesan kesalahan akan ditampilkan di layar. Pengurangan kapasitas tidak akan mengalami kegagalan. */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueue * Q, ElType X, int time);
/* Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q terdefinisi dan mungkin kosong */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        Tail dimajukan. Kapasitas Q akan direalokasikan menjadi dua kalinya jika Q tidak muat. 
        Jika realokasi gagal, X tidak dimasukkan ke Q dan pesan kesalahan akan ditampilkan
        di layar. */

void Dequeue (PrioQueue * Q, ElType* X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD dimajukan. Q mungkin kosong. 
        Kapasitas Q akan direalokasikan menjadi setengahnya jika Q sepi,
        yaitu ketika length(Q) <= Q.cap div 4*/

void DeleteAtPQ(PrioQueue* Q, ElType* X,int idx);
/* Proses: Menghapus elemen ke-idx pada Q */
/* I.S. Q tidak mungkin kosong. idx berada padas rentang [0..length(Q)-1]*/
/* F.S. Elemen ke-idx dihapus, elemen sebelumnya akan dimajukan jika Q tidak menjadi kosong.
        X berisi elemen yang dihapus. Kapasitas Q akan direalokasikan menjadi setengahnya jika Q sepi,
        yaitu ketika length(Q) <= Q.cap div 4 */

/* Operasi Tambahan */
void DisplayPQ (PrioQueue Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar */

#endif 