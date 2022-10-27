/* File : waktu.c */
/* Body ADT waktu */

#include <stdio.h>
#include "../headers/waktu.h"

/* *** KONSTRUKTOR *** */
void CreateWaktu(Waktu *t, int Hari, int Jam, int Menit)
/* I.S. t sembarang; Hari, Jam, Menit terdefinisi; 
   Jam pada range [0..23]; Menit pada range [0..59]*/
/* F.S. terbentuk waktu t yang merepresentasikan Hari, Jam, dan Menit
   sesuai definisi (lihat di header) */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    *t = Hari * 1440 + Jam * 60 + Menit;
}

/* *** GETTER & SETTER *** */
int GetMenit(Waktu t)
/* Mengembalikan elemen menit pada t, yaitu t % 60 */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    return t % 60;
}
int GetJam(Waktu t)
/* Mengembalikan elemen jam pada t, yaitu (t % 1440) / 60 */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    return (t % 1440) / 60;
}
int GetHari(Waktu t)
/* Mengembalikan elemen hari pada t, yaitu t / 1440 */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    return t / 1440;
}

/* *** OPERASI ARITMATIKA PADA WAKTU *** */
void TambahWaktu(Waktu *t, int Hari, int Jam, int Menit)
/* I.S. t dan Hari terdefinisi, Jam pada rentang [0..23], Menit pada rentang [0..59] */
/* F.S. waktu t ditambah(maju) selama Hari, Jam, dan Menit */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    *t = *t + Hari * 1440 + Jam * 60 + Menit;
}
Waktu SelisihWaktu(Waktu t1, Waktu t2)
/* Mengembalikan waktu bernilai t2 - t1 */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    return t2 - t1;
}
boolean IsWaktuGreaterEqual(Waktu t1, Waktu t2)
/* Mengembalikan true jika t1 >= t2 */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    return t1 >= t2;
}

/* *** OPERASI LAIN *** */
void CetakWaktuJJMM(Waktu t)
/* I.S. t terdefinisi */
/* F.S. elemen jam dan menit t dicetak ke layar dalam format jj.mm */
{   /* KAMUS LOKAL */
    /* ALGORITMA */
    printf("%02d.%02d", GetJam(t), GetMenit(t));
}
void CetakWaktuLengkap(Waktu t)
/* I.S. t terdefinisi */
/* F.S. t dicetak ke layar dalam format h hari j jam m menit, atau 0 jika waktu = 0
   Ada spasi di akhir */
{   /* KAMUS LOKAL */
    int Hari, Jam, Menit;
    /* ALGORITMA */
    Hari = GetHari(t);
    Jam = GetJam(t);
    Menit = GetMenit(t);
    if(Hari) printf("%d hari ", Hari);
    if(Jam) printf("%d jam ", Jam);
    if(Menit) printf("%d menit ", Menit);
    if(!t) printf("0 ");
}