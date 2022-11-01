/* File : driverWaktu.c */
/* Driver untuk ADT waktu */

/* C libraries */
#include <stdio.h>

/* ADT */
#include "waktu.h"
#include "../../boolean.h"

void _assert(boolean x, char ID[]) 
/* I.S. x, ID terdefinisi */
/* F.S. Mengeluarkan pesan jika x false */
{
    if(!x) printf("ASSERT FAILED AT ID : %s\n", ID);
}

int main() {
    Waktu t, t2, t0;
    CreateWaktu(&t, 5, 2, 10);
    _assert(GetHari(t) == 5, "HARI");
    _assert(GetJam(t) == 2, "JAM");
    _assert(GetMenit(t) == 10, "MENIT");

    CreateWaktu(&t2, 6, 2, 11);
    _assert(SelisihWaktu(t, t2) == 1441, "SELISIH");

    TambahWaktu(&t, 0, 23, 0);
    _assert(GetHari(t) == 6, "TAMBAH_HARI");
    _assert(GetJam(t) == 1, "TAMBAH_JAM");
    _assert(!IsWaktuGreaterEqual(t,t2), "COMPARE");

    CetakWaktuJJMM(t); puts("");
    CetakWaktuLengkap(t); puts("");

    CreateWaktu(&t0, 0, 0, 0);
    CetakWaktuJJMM(t0); puts("");
    CetakWaktuLengkap(t0); puts("");

    puts("Seluruh tes berhasil dijalankan. Waktu di atas seharusnya menunjukkan: \n01.10, 6 hari 1 jam 10 menit, 00.00, 0");

    return 0;
}