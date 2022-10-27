/* File : driverWaktu.c */
/* Driver untuk ADT waktu */

#include <stdio.h>
#include "../headers/waktu.h"
#include "../headers/boolean.h"

void _assert(boolean x, char ID[]) 
/* I.S. x, ID terdefinisi */
/* F.S. Mengeluarkan pesan jika x false */
{
    if(!x) printf("ASSERT FAILED AT ID : %s\n", ID);
}

int main() {
    Waktu t, t2, t0;
    createWaktu(&t, 5, 2, 10);
    _assert(getHari(t) == 5, "HARI");
    _assert(getJam(t) == 2, "JAM");
    _assert(getMenit(t) == 10, "MENIT");

    createWaktu(&t2, 6, 2, 11);
    _assert(selisihWaktu(t, t2) == 1441, "SELISIH");

    tambahWaktu(&t, 0, 23, 0);
    _assert(getHari(t) == 6, "TAMBAH_HARI");
    _assert(getJam(t) == 1, "TAMBAH_JAM");
    _assert(!isWaktuGreaterEqual(t,t2), "COMPARE");

    cetakWaktuJJMM(t); puts("");
    cetakWaktuLengkap(t); puts("");

    createWaktu(&t0, 0, 0, 0);
    cetakWaktuJJMM(t0); puts("");
    cetakWaktuLengkap(t0); puts("");

    return 0;
}