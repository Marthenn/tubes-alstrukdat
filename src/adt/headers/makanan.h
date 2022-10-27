/* File : makanan.h */
/* ADT makanan berisi ID, Nama, Waktu kedaluarsa, lokasi aksi, dan lama pengiriman */

#ifndef MAKANAN_H
#define MAKANAN_H

#include "wordmachine.h"
#include "waktu.h"
#include "point.h"

typedef struct makanan {
    int ID;
    Word Nama; 
    waktu Kedaluarsa, Pengiriman;
    point LokasiAksi;
} makanan;

/* *** KONSTRUKTOR *** */
void createMakanan(makanan *m, int ID, Word Nama, waktu Kedaluarsa, 
                    waktu Pengiriman, point LokasiAksi);
/* I.S. m sembarang. ID, Nama, Kedaluarsa, LokasiAksi, Pengiriman terdefinisi */
/* F.S. terbentuk makanan m */

/* *** GETTER *** */
int getIDMakanan(makanan m);
Word getNama(makanan m);
waktu getKedaluarsa(makanan m);
point getLokasiAksi(makanan m);
waktu getPengiriman(makanan m);
void displayMakanan(makanan m);

#endif
