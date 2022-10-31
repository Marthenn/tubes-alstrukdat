/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDIN_H
#define LISTDIN_H

#include "boolean.h"

/*  Kamus Umum */
#define LISTDIN_IDX_MIN 0
/* Indeks minimum list */
#define LISTDIN_IDX_UNDEF -1
/* Indeks tak terdefinisi*/

#define MIN_LISTDIN_CAP 2

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct
{
    int *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDin;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define LISTDIN_NEFF(l) (l).nEff
#define LISTDIN_BUFFER(l) (l).buffer
#define LISTDIN_ELMT(l, i) (l).buffer[i]
#define LISTDIN_CAP(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void DeallocateListDin(ListDin *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int ListDinLength(ListDin l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType GetListDinFirstIdx(ListDin l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType GetListDinLastIdx(ListDin l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsListDinIdxValid(ListDin l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsListDinIdxEff(ListDin l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsListDinEmpty(ListDin l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean IsListDinFull(ListDin l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */

void PrintListDin(ListDin l);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean IsListDinEqual(ListDin l1, ListDin l2);
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType ListDinIndexOf(ListDin l, int val);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */


/* ********** OPERASI LAIN ********** */
void CopyListDin(ListDin lIn, ListDin *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 

int CountListDinVal(ListDin l, int val);
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void SortListDin(ListDin *l, boolean asc);
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void InsertFirstListDin(ListDin *l, int val);
/* Proses: Menambahkan val sebagai elemen pertama List dinamis */
/* I.S. List l boleh kosong, jika penuh maka kapasitas ditambah */
/* F.S. val adalah elemen pertama l yang baru, kapasitas dapat bertambah */
/* *** Menambahkan elemen pada index tertentu *** */

void InsertAtListDin(ListDin *l, int val, IdxType idx);
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong, jika penuh maka kapasitas ditambah, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l, kapasitas dapat bertambah */

/* *** Menambahkan elemen terakhir *** */
void InsertLastListDin(ListDin *l, int val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, jika penuh maka kapasitas ditambah */
/* F.S. val adalah elemen terakhir l yang baru, kapasitas dapat bertambah */


/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void DeleteFirstListDin(ListDin *l, int *val);
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong, kapasitas dapat dikurangi */
/* *** Menghapus elemen pada index tertentu *** */

void DeleteAtListDin(ListDin *l, int *val, IdxType idx);
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong, kapasitas dapat dikurangi */
/* *** Menghapus elemen terakhir *** */

/* ********** MENGHAPUS ELEMEN ********** */
void DeleteLastListDin(ListDin *l, int *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong, kapasitas dapat dikurangi */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void ExpandListDin(ListDin *l);
/* Proses : Menambahkan capacity l menjadi 1.5 kali capacity semula */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah menjadi 1.5 kali ukuran semula */

void ShrinkListDin(ListDin *l);
/* Proses : Mengurangi capacity menjadi setengah semula atau MIN_LISTDIN_CAP*/
/* I.S. List sudah terdefinisi, isi list dinamis <= 1/4 capacity */
/* F.S. Ukuran list berkurang menjadi setengah ukuran awal atau MIN_LISTDIN_CAP. */

void CompressListDin(ListDin *l);
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */

#endif