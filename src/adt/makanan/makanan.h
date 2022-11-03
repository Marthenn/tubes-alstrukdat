/* File : makanan.h */
/* ADT makanan berisi ID, Nama, Waktu kedaluarsa, lokasi aksi, dan lama pengiriman */

#ifndef MAKANAN_H
#define MAKANAN_H

/* ADT */
#include "../wordmachine/wordmachine.h"
#include "../waktu/waktu.h"
#include "../point/point.h"

typedef struct {
    int Id;
    Word Nama; 
    Waktu Kedaluarsa, WaktuAksi;
    Word Aksi;
    Point LokasiAksi;
    int SizeX, SizeY;
} Makanan;

/* *** KONSTRUKTOR *** */
void CreateMakanan(Makanan *m, int id, Word nama, Waktu kedaluarsa, 
                    Waktu pengiriman, Word aksi, Point lokasiAksi, int sizeX, int sizeY);
/* I.S. m sembarang. ID, Nama, Kedaluarsa, LokasiAksi, Pengiriman terdefinisi */
/* F.S. terbentuk makanan m */

/* *** GETTER *** */
int GetIDMakanan(Makanan m);
Word GetNama(Makanan m);
Waktu GetKedaluarsa(Makanan m);
Waktu GetPengiriman(Makanan m);
Point GetLokasiAksi(Makanan m);
Word GetAksi(Makanan m);
int GetSizeX(Makanan m);
int GetSizeY(Makanan m);
void DisplayMakanan(Makanan m);

#endif
