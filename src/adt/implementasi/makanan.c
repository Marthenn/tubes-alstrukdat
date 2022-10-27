/* File : makanan.c */
/* Body ADT makanan */

#include <stdio.h>
#include "../headers/makanan.h"
#include "../headers/parser.h"

/* *** KONSTRUKTOR *** */
void CreateMakanan(Makanan *m, int id, Word nama, Waktu kedaluarsa, 
                    Waktu pengiriman, Point lokasiAksi)
/* I.S. m sembarang. ID, Nama, Kedaluarsa, LokasiAksi, Pengiriman terdefinisi */
/* F.S. terbentuk makanan m */
{
    m->Id = id;
    m->Nama = nama;
    m->Kedaluarsa = kedaluarsa;
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

void DisplayMakanan(Makanan m)
{
    printf("id : %d\n", GetIDMakanan(m));

    printf("nama makanan : ");
    DisplayWordLine(m.Nama);

    printf("Waktu kadaluarsa : ");
    CetakWaktuLengkap(m.Kedaluarsa);
    printf("\n");

    printf("Waktu pengiriman : ");
    CetakWaktuLengkap(m.Pengiriman);
    printf("\n");

    printf("Lokasi aksi : ");
    CetakPoint(m.LokasiAksi);
    printf("\n");

}