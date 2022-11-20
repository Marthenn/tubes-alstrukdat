/* File : driverSimulator.c */
/* Driver untuk ADT Point */

/* C libraries */
#include <stdio.h>

/* ADT */
#include "simulator.h"
#include "../../boolean.h"
#include "../../app/parser/parser.h"

void _assert(boolean x, char ID[]) 
/* I.S. x, ID terdefinisi */
/* F.S. Mengeluarkan pesan jika x false */
{
    if(!x) printf("ASSERT FAILED AT ID : %s\n", ID);
}

int main() {
    Simulator sim;
    Point p; p.x = 5; p.y = 7;
    ListStatik foods;

    CreateEmptySimulator(&sim, NewWord("Bruno Earth", 11));
    DisplayWordLine(GetNamaPengguna(&sim));
    CreateListStatik(&foods);

    SetLokasi(&sim, p);
    CetakPoint(sim.Lokasi);
    puts("");

    InsertMakanan(&sim, 0, 3);
    InsertMakanan(&sim, 1, 5);
    InsertMakanan(&sim, 2, 10);
    InsertMakanan(&sim, 3, 15);
    DisplayPQ(sim.Inventory);

    puts("Sekarang waktu = 5 menit");
    SetTime(&sim, 5);
    HapusMakananKedaluarsa(&sim, foods);
    DisplayPQ(sim.Inventory);

    puts("Hapus makanan dengan ID 3");
    DeleteMakanan(&sim, 3);
    DisplayPQ(sim.Inventory);

    puts("Hapus makanan dengan ID 0");
    DeleteMakanan(&sim, 0);
    DisplayPQ(sim.Inventory); puts("");

    InsertMakanan(&sim, 0, 3);
    InsertMakanan(&sim, 1, 5);
    InsertMakanan(&sim, 3, 15);

    printf("Waktu = ");
    CetakWaktuJJMM(GetTime(&sim));printf("\n");

    TakeTime(&sim, 0, 0, 7, foods);
    printf("Waktu = ");
    CetakWaktuJJMM(GetTime(&sim));printf("\n");
    _assert(GetTime(&sim) == 12, "TIME 1");

    ListDinElType notif;
    notif = GetNotif(&sim);
    puts("Notifikasi:");
    PrintListDinElType(notif); printf("\n");

    printf("\nFungsi terkait kulkas:\n");
    Makanan kentang;
    ListStatik ls;
    CreateListStatik(&ls);
    ElType el;
    el = NewElType(3, (union Data){.m = kentang});
    ListInsertAt(&ls, el, 0);
    CreatePoint(&p, 3, 3);
    CreateMakanan(&kentang, 1, NewWord("Kentang", 7), 1800, 10, NewWord("Chop", 4), p, 4, 3);
    printf("Menaruh makanan di posisi (3,3) sampai (7,6)\n");
    _assert(IsKulkasEmpty(sim), "KULKAS EMPTY 1");
    PutFood(&sim, kentang, 3, 3, 0, ls, 1, 1);
    //DisplayIntMatriks(sim.Kulkas);
    _assert(!IsKulkasEmpty(sim), "KULKAS EMPTY 2");
    
    printf("Seluruh tes berhasil dijalankan.\n");

    return 0;
}
