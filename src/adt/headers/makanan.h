/* File : makanan.h */
/* ADT makanan berisi ID, Nama, Waktu kedaluarsa, lokasi aksi, dan lama pengiriman */

#ifndef MAKANAN_H
#define MAKANAN_H

#include "wordmachine.h"
#include "waktu.h"
#include "point.h"

typedef struct {
    int id;
    Word nama; 
    Waktu kedaluarsa, pengiriman;
    Point lokasiAksi;
} Makanan;

/* *** KONSTRUKTOR *** */
void CreateMakanan(Makanan *m, int ID, Word Nama, Waktu Kedaluarsa, 
                    Waktu Pengiriman, Point LokasiAksi);
/* I.S. m sembarang. ID, Nama, Kedaluarsa, LokasiAksi, Pengiriman terdefinisi */
/* F.S. terbentuk makanan m */

/* *** GETTER *** */
int GetIDMakanan(Makanan m);
Word GetNama(Makanan m);
Waktu GetKedaluarsa(Makanan m);
Waktu GetPengiriman(Makanan m);
Point GetLokasiAksi(Makanan m);
void DisplayMakanan(Makanan m);

#endif
