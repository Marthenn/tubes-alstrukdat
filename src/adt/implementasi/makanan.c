/* File : makanan.c */
/* Body ADT makanan */

#include "../headers/makanan.h"
#include "../headers/parser.h"

/* *** KONSTRUKTOR *** */
void createMakanan(makanan *m, int ID, Word Nama, waktu Kedaluarsa, 
                    waktu Pengiriman, point LokasiAksi)
/* I.S. m sembarang. ID, Nama, Kedaluarsa, LokasiAksi, Pengiriman terdefinisi */
/* F.S. terbentuk makanan m */
{
    m->ID = ID;
    m->Nama = Nama;
    m->Kedaluarsa = Kedaluarsa;
    m->LokasiAksi = LokasiAksi;
    m->Pengiriman = Pengiriman;
}

/* *** GETTER *** */
int getIDMakanan(makanan m){
    return m.ID;
}
Word getNama(makanan m) {
    return m.Nama;
}
waktu getKedaluarsa(makanan m) {
    return m.Kedaluarsa;
}
point getLokasiAksi(makanan m) {
    return m.LokasiAksi;
}
waktu getPengiriman(makanan m) {
    return m.Pengiriman;
}

void displayMakanan(makanan m)
{
    printf("id : %d\n", getIDMakanan(m));

    printf("nama makanan : ");
    DisplayWordLine(m.Nama);

    printf("Waktu kadaluarsa : ");
    cetakWaktuLengkap(m.Kedaluarsa);
    printf("\n");

    printf("Waktu pengiriman : ");
    cetakWaktuLengkap(m.Pengiriman);
    printf("\n");

    printf("Lokasi aksi : ");
    cetakPoint(m.LokasiAksi);
    printf("\n");

}