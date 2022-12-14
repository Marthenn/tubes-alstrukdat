/* File : prioqueue.h */
/* Definisi Priority Queue versi 2 dengan list dinamik */
/* Priority queue memiliki komponen Info berupa int dan Time berupa Waktu */
/* Elemen akan terurut membesar berdasarkan Time, apabila sama maka Info lebih kecil didahulukan */

#ifndef prioqueue_H
#define prioqueue_H

/* ADT */
#include "../../boolean.h"
#include "../makanan/makanan.h"
#include "../eltype/eltype.h"

#define PQ_NIL -1
#define PQ_MIN_CAP 1
#define PQ_IDX_UNDEF -1


typedef struct {
    Waktu Time;
    int Info;
} PQInfoType;

typedef struct{
    PQInfoType * Tab;
    int Head,Tail,Cap;
} PrioQueue;

/* **** Getter & Setter **** */
int GetHeadInfo(PrioQueue Q);
/* Mengembalikan Info pada Head */

Waktu GetHeadTime(PrioQueue Q);
/* Mengembalikan Time pada Head */

int GetElmtInfo(PrioQueue Q,int idx);
/* Mengembalikan Info elemen indeks ke-idx secara logikal pada Q. idx = 0 adalah Head */
/* idx berada pada rentang [0..length(Q)-1] */

Waktu GetElmtTime(PrioQueue Q,int idx);
/* Mengembalikan waktu dari elemen indeks ke-idx secara logikal pada Q. idx = 0 adalah Head */
/* idx berada pada rentang [0..length(Q)-1] */

void SetElmtTime(PrioQueue *Q, int idx, Waktu newTime);
/* Mengganti nilai waktu dari elemen indeks ke-idx secara logikal pada Q dan
/* memposisikan ulang elemen tersebut. idx = 0 adalah Head */
/* idx berada pada rentang [0..length(Q)-1] */

/* ********* Element Comparator ********* */
boolean IsEarlier(PQInfoType a, PQInfoType b);
/* Mengembalikan true apabila a terletak lebih awal daripada b di priority queue*/

/* ********* Prototype ********* */
boolean IsEmptyPQ (PrioQueue Q);
/* Mengirim true jika Q kosong*/

boolean IsFullPQ (PrioQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak Cap */

int LengthPQ (PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmptyPQ(PrioQueue * Q);
/* Membuat Q kosong */
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dengan Q.cap = MIN_CAP. 
        Tidak dilakukan dealokasi memori Q.Tab lama */

/* *** Destruktor *** */
void DeallocatePQ(PrioQueue * Q);
/* Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi*/

/* *** Realokator *** */
void ReallocatePQ(PrioQueue * Q, int newCap);
/* Mengalokasi ulang kapasitas Q */
/* I.S. Q, newCap terdefinisi. newCap != 0. Jika newCap lebih kecil dari kapasitas sebelumnya, maka haruslah length(Q) <= newCap */
/* F.S  Kapasitas Q menjadi newCap. Jika pada saat penambahan kapasitas gagal, maka ukuran Q tidak berubah dan
        pesan kesalahan akan ditampilkan di layar. Pengurangan kapasitas tidak akan mengalami kegagalan. */

/* *** Searching *** */
int IndexOfPQ(PrioQueue Q, int X);
/* Mengembalikan indeks X pertama kali ditemukan di Q. */
/* Mengembalikan IDX_UNDEF jika tidak ada */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueue * Q, int X, Waktu time);
/* Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time lalu info */
/* I.S. Q terdefinisi dan mungkin kosong */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        Tail dimajukan. Kapasitas Q akan direalokasikan menjadi dua kalinya jika Q tidak muat. 
        Jika realokasi gagal, X tidak dimasukkan ke Q dan pesan kesalahan akan ditampilkan
        di layar. */

void Dequeue (PrioQueue * Q, int* X, Waktu* time);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD dimajukan. Q mungkin kosong. 
        Kapasitas Q akan direalokasikan menjadi setengahnya jika Q sepi,
        yaitu ketika length(Q) <= Q.cap div 4*/

void DeleteAtPQ(PrioQueue* Q, int* X, Waktu *time, int idx);
/* Proses: Menghapus elemen ke-idx pada Q */
/* I.S. Q tidak mungkin kosong. idx berada padas rentang [0..length(Q)-1]*/
/* F.S. Elemen ke-idx dihapus, elemen sebelumnya akan dimajukan jika Q tidak menjadi kosong.
        X berisi elemen yang dihapus. Kapasitas Q akan direalokasikan menjadi setengahnya jika Q sepi,
        yaitu ketika length(Q) <= Q.cap div 4 */

void DeleteElmtPQ(PrioQueue* Q, int X, Waktu time);
/* Proses: Menghapus elemen pada Q yang memiliki nilai X dan waktu time */
/* I.S. Q tidak mungkin kosong.*/
/* F.S. Elemen dengan nilai X dan waktu time dihapus, elemen sebelumnya akan dimajukan jika Q tidak menjadi kosong.
        Elemen dapat tidak ditemukan (tidak dilakukan apa-apa). Kapasitas Q akan direalokasikan menjadi setengahnya jika Q sepi,
        yaitu ketika length(Q) <= Q.cap div 4 */
        
/* Operasi Tambahan */
void AssignPQ (PrioQueue A, PrioQueue* B);
/* Melakukan operasi B := A sehingga konten B akan sama menjadi A */
/* A dan B harus terdefinisi agar dapat dilakukan pembebasan memori */

void DisplayInfoTypePQ(PQInfoType p);
/* Menampilkan info dari PQInfoType */
/* I.S. Q terdefinisi */
/* F.S. Info dari p ditampilkan ke layar */

void DisplayPQ (PrioQueue Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar */

#endif 