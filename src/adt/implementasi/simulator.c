/* File: simulator.c */
/* Body ADT simulator */

#include <stdio.h>
#include "../headers/simulator.h"

/* *** KONSTRUKTOR *** */
void CreateEmptySimulator(Simulator *sim, Word NamaPengguna)
/* I.S. sim bebas, NamaPengguna terdefinisi */
/* F.S. terbentuk Simulator sim dengan Lokasi = (0, 0) dan Inventory kosong */
{
    sim->NamaPengguna = NamaPengguna;
    CreatePoint(&(sim->Lokasi), 0, 0);
    CreateEmptyPQ(&(sim->Inventory));
}

/* *** SETTER / GETTER *** */
void SetLokasi(Simulator *sim, Point Lokasi)
/* I.S. sim telah dibentuk, Lokasi terdefinisi */
/* F.S. Mengubah Lokasi sim */
{
    sim->Lokasi = Lokasi;
}

/* NamaPengguna dan Inventory tidak ada setter manual */

Point GetLokasi(const Simulator *sim)
/* Mengembalikan Point berisi lokasi pengguna */
{
    return sim->Lokasi;
}
Word GetNamaPengguna(const Simulator *sim)
/* Mengembalikan Word berisi NamaPengguna */
{
    return sim->NamaPengguna;
}

/* *** OPERASI TERHADAP LOKASI *** */
/* Ada di ADT Point */

/* *** OPERASI TERHADAP INVENTORY *** */
boolean DeleteMakanan(Simulator *sim, int ID)
/* Jika ada makanan ID, Menghapus kemunculan pertama dari ID dan return true */
/* Jika tidak, return false */
{
    int tmp;
    int idx = IndexOfPQ(sim->Inventory, ID);
    if(idx == -1) return false;
    DeleteAtPQ(&(sim->Inventory), &tmp, ID);
    return true;
}

void InsertMakanan(Simulator *sim, int ID, Waktu kedaluarsa)
/* I.S. sim terdefinisi. kedaluarsa = waktu sekarang + waktu kedaluarsa makanan */
/* F.S. sim->Inventory ditambahkan makanan */
{
    Enqueue(&(sim->Inventory), ID, kedaluarsa);
}

void HapusMakananKedaluarsa(Simulator *sim, Waktu now)
/* I.S. sim, now terdefinisi */
/* F.S. seluruh isi inventory yang kedaluarsa dihapus */
{
    int tmp;
    while(!(IsEmptyPQ(sim->Inventory)) && GetHeadTime(sim->Inventory) <= now) {
        Dequeue(&(sim->Inventory), &tmp);
    }
}