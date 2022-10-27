/* File : makanan.c */
/* Body ADT makanan */

#include "../headers/makanan.h"
#include "../headers/parser.h"

/* *** KONSTRUKTOR *** */
void CreateMakanan(Makanan *m, int id, Word nama, Waktu kedaluarsa, 
                    Waktu pengiriman, Point lokasiAksi)
/* I.S. m sembarang. ID, Nama, Kedaluarsa, LokasiAksi, Pengiriman terdefinisi */
/* F.S. terbentuk makanan m */
{
    m->id = id;
    m->nama = nama;
    m->kedaluarsa = kedaluarsa;
    m->lokasiAksi = lokasiAksi;
    m->pengiriman = pengiriman;
}

/* *** GETTER *** */
int GetIDMakanan(Makanan m){
    return m.id;
}
Word GetNama(Makanan m) {
    return m.nama;
}
Waktu GetKedaluarsa(Makanan m) {
    return m.kedaluarsa;
}
Point GetLokasiAksi(Makanan m) {
    return m.lokasiAksi;
}
Waktu GetPengiriman(Makanan m) {
    return m.pengiriman;
}

void DisplayMakanan(Makanan m)
{
    printf("id : %d\n", GetIDMakanan(m));

    printf("nama makanan : ");
    DisplayWordLine(m.nama);

    printf("Waktu kadaluarsa : ");
    cetakWaktuLengkap(m.kedaluarsa);
    printf("\n");

    printf("Waktu pengiriman : ");
    cetakWaktuLengkap(m.pengiriman);
    printf("\n");

    printf("Lokasi aksi : ");
    cetakPoint(m.lokasiAksi);
    printf("\n");

}