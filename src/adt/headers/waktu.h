/* File : waktu.h */
/* ADT waktu berisi satu integer menandakan jumlah menit setelah
   hari ke-0 jam 0:0 */

#ifndef waktu_H
#define waktu_H

#include "boolean.h"

typedef int waktu;

/* *** KONSTRUKTOR *** */
void createWaktu(waktu *t, int Hari, int Jam, int Menit);
/* I.S. t sembarang; Hari, Jam, Menit terdefinisi; 
   Jam pada range [0..23]; Menit pada range [0..59]*/
/* F.S. terbentuk waktu t yang merepresentasikan Hari, Jam, dan Menit
   sesuai definisi (lihat di header) */

/* *** GETTER & SETTER *** */
int getMenit(waktu t);
/* Mengembalikan elemen menit pada t, yaitu t % 60 */
int getJam(waktu t);
/* Mengembalikan elemen jam pada t, yaitu (t % 1440) / 60 */
int getHari(waktu t);
/* Mengembalikan elemen hari pada t, yaitu t / 1440 */

/* *** OPERASI ARITMATIKA PADA WAKTU *** */
void tambahWaktu(waktu *t, int Hari, int Jam, int Menit);
/* I.S. t dan Hari terdefinisi, Jam pada rentang [0..23], Menit pada rentang [0..59] */
/* F.S. waktu t ditambah(maju) selama Hari, Jam, dan Menit */
waktu selisihWaktu(waktu t1, waktu t2);
/* Mengembalikan waktu bernilai t2 - t1 */
boolean isWaktuGreaterEqual(waktu t1, waktu t2);
/* Mengembalikan true jika t1 >= t2 */

/* *** OPERASI LAIN *** */
void cetakWaktuJJMM(waktu t);
/* I.S. t terdefinisi */
/* F.S. elemen jam dan menit t dicetak ke layar dalam format jj.mm */
void cetakWaktuLengkap(waktu t);
/* I.S. t terdefinisi */
/* F.S. t dicetak ke layar dalam format h hari j jam m menit, atau 0 jika waktu = 0
   Ada spasi di akhir */
#endif