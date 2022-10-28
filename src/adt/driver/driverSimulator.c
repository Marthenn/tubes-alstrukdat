/* File : driverSimulator.c */
/* Driver untuk ADT Point */

/* C libraries */
#include <stdio.h>

/* ADT */
#include "../headers/simulator.h"
#include "../headers/boolean.h"
#include "../../app/headers/parser.h"

void _assert(boolean x, char ID[]) 
/* I.S. x, ID terdefinisi */
/* F.S. Mengeluarkan pesan jika x false */
{
    if(!x) printf("ASSERT FAILED AT ID : %s\n", ID);
}

int main() {
    Simulator sim;
    Point p; p.x = 5; p.y = 7;
    CreateEmptySimulator(&sim, NewWord("Bruno Earth", 11));
    DisplayWordLine(GetNamaPengguna(&sim));

    SetLokasi(&sim, p);
    CetakPoint(sim.Lokasi);
    puts("");

    InsertMakanan(&sim, 0, 3);
    InsertMakanan(&sim, 1, 5);
    InsertMakanan(&sim, 2, 10);
    InsertMakanan(&sim, 3, 15);
    DisplayPQ(sim.Inventory);

    puts("Sekarang waktu = 5 menit");
    HapusMakananKedaluarsa(&sim, 5);
    DisplayPQ(sim.Inventory);

    puts("Hapus makanan dengan ID 3");
    DeleteMakanan(&sim, 3);
    DisplayPQ(sim.Inventory);

    puts("Hapus makanan dengan ID 0");
    DeleteMakanan(&sim, 0);
    DisplayPQ(sim.Inventory);

    printf("Seluruh tes berhasil dijalankan.\n");

    return 0;
}