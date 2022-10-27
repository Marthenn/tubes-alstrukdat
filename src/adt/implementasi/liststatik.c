/* File : liststatik.c */
/* Implementasi List Statik */

#include <stdio.h>
#include "../headers/liststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi dengan Indeks Efektif = 0 */

    // KAMUS LOKAL
    // ALGORITMA
    EFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

    // KAMUS LOKAL
    // ALGORITMA
    return EFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

    // KAMUS LOKAL
    // ALGORITMA
    return listLength(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxEff(ListStatik l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

    // KAMUS LOKAL
    // ALGORITMA
    return i <= getLastIdx(l) && i >= 0;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    
    // KAMUS LOKAL
    // ALGORITMA
    return getLastIdx(l) == IDX_UNDEF;
}
/* *** Test List penuh *** */
boolean isFull(ListStatik l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

    // KAMUS LOKAL
    // ALGORITMA
    return listLength(l) == CAPACITY;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */

    // KAMUS LOKAL
    int i;
    // ALGORITMA
    i = 0;
    for(i = 0; i <= getLastIdx(l); i++){
        if(compare(ELMT(l, i), val)){
            return i;
        }
    }
    return IDX_UNDEF;
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */

    // KAMUS LOKAL
    int i;
    // ALGORITMA
    if(isEmpty(*l)){
        ELMT(*l, 0) = val;
    }
    else{
        for(i = getLastIdx(*l) + 1; i > 0; i--){
            ELMT(*l, i) = ELMT(*l, i-1);
        }
        ELMT(*l, 0) = val;
        EFF(*l)++;
    }
}
void insertAt(ListStatik *l, ElType val, IdxType idx){
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */

    // KAMUS LOKAL
    int i;
    // ALGORITMA
    for(i = getLastIdx(*l) + 1; i > idx; i--){
        ELMT(*l, i) = ELMT(*l, i-1);
    }
    ELMT(*l, idx) = val;
    EFF(*l)++;
}
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

    // KAMUS LOKAL
    // ALGORITMA
    ELMT(*l, getLastIdx(*l)+1) = val;
    EFF(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

    // KAMUS LOKAL
    int i;
    // ALGORITMA
    *val = ELMT(*l, 0);
    for(i = 0; i < getLastIdx(*l); i++){
        ELMT(*l, i) = ELMT(*l, i+1);
    }
    EFF(*l)--;
}
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

    // KAMUS LOKAL
    int i;
    // ALGORITMA
    *val = ELMT(*l, idx);
    for(i = idx; i < getLastIdx(*l); i++){
        ELMT(*l, i) = ELMT(*l, i+1);
    }
    EFF(*l)--;
}
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

    // KAMUS LOKAL
    // ALGORITMA
    *val = ELMT(*l, getLastIdx(*l));
    EFF(*l)--;
}

/* ********** Assignment List ********** */
void copyList(ListStatik lIn, ListStatik *lOut){
/* Melakukan assignment lOut <- lIn */

    // KAMUS LOKAL
    int i;
    // ALGORITMA
    i = 0;
    EFF(*lOut) = EFF(lIn);
    for(i = 0; i <= getLastIdx(lIn); i++){
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

/* ********** Keluaran List ********** */
void displayList(ListStatik l){
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    printf("[");
    for(i = 0; i <= getLastIdx(l); i++){
        printElType(ELMT(l, i));
        if(i != listLength(l) - 1){
            printf(", ");
        }
    }
    printf("]");
}