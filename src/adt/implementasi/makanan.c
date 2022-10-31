/* File : makanan.c */
/* Body ADT makanan */

/* C libraries */
#include <stdio.h>

/* ADT */
#include "../headers/makanan.h"

/* APP */
#include "../../app/headers/parser.h"

/* *** KONSTRUKTOR *** */
void CreateMakanan(Makanan *m, int id, Word nama, Waktu kedaluarsa, 
                    Waktu pengiriman, Word aksi, Point lokasiAksi)
/* I.S. m sembarang. ID, Nama, Kedaluarsa, LokasiAksi, Pengiriman terdefinisi */
/* F.S. terbentuk makanan m */
{
    m->Id = id;
    m->Nama = nama;
    m->Kedaluarsa = kedaluarsa;
    m->Aksi = aksi;
    m->LokasiAksi = lokasiAksi;
    m->Pengiriman = pengiriman;
}

/* *** GETTER *** */
int GetIDMakanan(Makanan m){
    return m.Id;
}
Word GetNama(Makanan m) {
    return m.Nama;
}
Waktu GetKedaluarsa(Makanan m) {
    return m.Kedaluarsa;
}
Point GetLokasiAksi(Makanan m) {
    return m.LokasiAksi;
}
Waktu GetPengiriman(Makanan m) {
    return m.Pengiriman;
}

Word GetAksi(Makanan m) {
    return m.Aksi;
}

void DisplayMakanan(Makanan m)
{
    DisplayWord(m.Nama);
    printf(" - ");

    CetakWaktuLengkap(m.Kedaluarsa);

    printf(" - ");

    DisplayWord(m.Aksi);

    printf(" - ");

    CetakWaktuLengkap(m.Pengiriman);
}
