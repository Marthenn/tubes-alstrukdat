/* File : prioqueue.h */
/* Definisi Priority Queue versi 2 dengan list dinamik */
/* Priority queue memiliki komponen Info berupa int dan Time berupa Waktu */

#ifndef prioqueue_H
#define prioqueue_H

/* ADT */
#include "boolean.h"
#include "makanan.h"
#include "eltype.h"

#define Nil -1
#define DEF_SIZE 20
#define IDX_UNDEF -1

typedef int PQElType;
typedef struct {
    Waktu Time;
    PQElType Info;
} infotype;

typedef struct{
    infotype * Tab;
    int Head,Tail,Cap;
} PrioQueue;

/* **** Getter & Setter **** */
PQElType GetHeadInfo(PrioQueue Q);
/* Mengembalikan Info pada Head */

Waktu GetHeadTime(PrioQueue Q);
/* Mengembalikan Time pada Head */

PQElType GetElmtInfo(PrioQueue Q,int idx);
/* Mengembalikan Info elemen indeks ke-idx secara logikal pada Q. idx = 0 adalah Head */
/* idx berada pada rentang [0..length(Q)] */

Waktu GetElmtTime(PrioQueue Q,int idx);
/* Mengembalikan waktu dari elemen indeks ke-idx secara logikal pada Q. idx = 0 adalah Head */
/* idx berada pada rentang [0..length(Q)] */

void SetElmtTime(PrioQueue *Q, int idx, Waktu newTime);
/* Mengganti nilai waktu dari elemen indeks ke-idx secara logikal pada Q dan
/* memposisikan ulang elemen tersebut. idx = 0 adahal Head */
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

/* *** Realokator *** */
void ReallocatePQ(PrioQueue * Q, int newCap);
/* Mengalokasi ulang kapasitas Q */
/* I.S. Q terdefinisi. Jika newCap lebih kecil dari kapasitas sebelumnya, maka haruslah length(Q) <= newCap */
/* F.S  Kapasitas Q menjadi newCap. Jika pada saat penambahan kapasitas gagal, maka ukuran Q tidak berubah dan
        pesan kesalahan akan ditampilkan di layar. Pengurangan kapasitas tidak akan mengalami kegagalan. */

/* *** Searching *** */
int IndexOfPQ(PrioQueue Q, PQElType X);
/* Mengembalikan indeks X pertama kali ditemukan di Q mulai dari depan. */
/* Mengembalikan IDX_UNDEF jika tidak ada */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueue * Q, PQElType X, Waktu time);
/* Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q terdefinisi dan mungkin kosong */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        Tail dimajukan. Kapasitas Q akan direalokasikan menjadi dua kalinya jika Q tidak muat. 
        Jika realokasi gagal, X tidak dimasukkan ke Q dan pesan kesalahan akan ditampilkan
        di layar. */

void Dequeue (PrioQueue * Q, PQElType* X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD dimajukan. Q mungkin kosong. 
        Kapasitas Q akan direalokasikan menjadi setengahnya jika Q sepi,
        yaitu ketika length(Q) <= Q.cap div 4*/

void DeleteAtPQ(PrioQueue* Q, PQElType* X,int idx);
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