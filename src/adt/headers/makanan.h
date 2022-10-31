/* File : makanan.h */
/* ADT makanan berisi ID, Nama, Waktu kedaluarsa, lokasi aksi, dan lama pengiriman */

#ifndef MAKANAN_H
#define MAKANAN_H

/* ADT */
#include "wordmachine.h"
#include "waktu.h"
#include "point.h"

typedef struct {
    int Id;
    Word Nama; 
    Waktu Kedaluarsa, Pengiriman;
    Word Aksi;
    Point LokasiAksi;
} Makanan;

/* *** KONSTRUKTOR *** */
void CreateMakanan(Makanan *m, int id, Word nama, Waktu kedaluarsa, 
                    Waktu pengiriman, Word aksi, Point lokasiAksi);
/* I.S. m sembarang. ID, Nama, Kedaluarsa, LokasiAksi, Pengiriman terdefinisi */
/* F.S. terbentuk makanan m */

/* *** GETTER *** */
int GetIDMakanan(Makanan m);
Word GetNama(Makanan m);
Waktu GetKedaluarsa(Makanan m);
Waktu GetPengiriman(Makanan m);
Point GetLokasiAksi(Makanan m);
Word GetAksi(Makanan m);
void DisplayMakanan(Makanan m);

#endif
