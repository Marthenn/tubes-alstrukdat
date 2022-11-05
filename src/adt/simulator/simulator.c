/* File: simulator.c */
/* Body ADT simulator */

/* C libraries */
#include <stdio.h>

/* ADT */
#include "simulator.h"

/* APP */
#include "../../app/parser/parser.h"

/* *** KONSTRUKTOR *** */
void CreateEmptySimulator(Simulator *sim, Word NamaPengguna)
/* I.S. sim bebas, NamaPengguna terdefinisi */
/* F.S. terbentuk Simulator sim dengan Lokasi = (0, 0) dan Inventory kosong */
{
    Waktu newTime;

    CreateWaktu(&newTime, 0, 0, 0);

    sim->NamaPengguna = NamaPengguna;
    CreatePoint(&(sim->Lokasi), 0, 0);
    CreateEmptyPQ(&(sim->Inventory));
    CreateEmptyPQ(&(sim->Delivery));
    SetTime(sim, newTime);

    SetNotif(sim, EMPTY_NOTIF);
}

/* *** SETTER / GETTER *** */
void SetLokasi(Simulator *sim, Point Lokasi)
/* I.S. sim telah dibentuk, Lokasi terdefinisi */
/* F.S. Mengubah Lokasi sim */
{
    sim->Lokasi.x = GetAbsis(Lokasi);
     sim->Lokasi.y = GetOrdinat(Lokasi);
}

/* NamaPengguna dan Inventory tidak ada setter manual */

Point GetLokasi(const Simulator *sim)
/* Mengembalikan Point berisi lokasi pengguna */
{
    Point currentPoint;

    currentPoint.x = GetAbsis(sim->Lokasi);
    currentPoint.y = GetOrdinat(sim->Lokasi);
    return currentPoint;
}
Word GetNamaPengguna(const Simulator *sim)
/* Mengembalikan Word berisi NamaPengguna */
{
    return sim->NamaPengguna;
}

Waktu GetTime(const Simulator *sim)
/* Mengembalikan waktu saat ini*/
{
    return sim->Time;
}

void SetTime(Simulator *sim, Waktu newTime)
/* I.S. sim telah dibentuk, newTime terdefinisi */
/* F.S. Mengubah waktu sim */
{
    sim->Time = newTime;
}

Word GetNotif(const Simulator *sim)
/* Mengembalikan notifikasi saat ini*/
{
    return sim->Notification;
}

void SetNotif(Simulator *sim, Word newNotification)
/* I.S. sim telah dibentuk, newNotification terdefinisi */
/* F.S. Mengubah notifikasi sim */
{
    sim->Notification = newNotification;
}

/* *** OPERASI TERHADAP LOKASI *** */
/* Ada di ADT Point */

/* *** OPERASI TERHADAP INVENTORY *** */
boolean DeleteMakanan(Simulator *sim, int ID)
/* Jika ada makanan ID, Menghapus kemunculan pertama dari ID dan return true */
/* Jika tidak, return false */
{
    int tmp;
    Waktu time;
    int idx = IndexOfPQ(sim->Inventory, ID);
    if(idx == -1) return false;
    DeleteAtPQ(&(sim->Inventory), &tmp, &time, ID);
    return true;
}

void InsertMakanan(Simulator *sim, int ID, Waktu kedaluarsa)
/* I.S. sim terdefinisi. kedaluarsa = waktu sekarang + waktu kedaluarsa makanan */
/* F.S. sim->Inventory ditambahkan makanan */
{
    Enqueue(&(sim->Inventory), ID, kedaluarsa);
}

void HapusDelivery(Simulator *sim, ListStatik foods)
/* I.S. sim terdefinisi */
/* F.S. makanan dengan waktu delivery yang melewati waktu saat ini dimasukkan ke inventory */
{
    int id, idx;
    Waktu time, now;

    now = GetTime(sim);

    while(!(IsEmptyPQ(sim->Delivery)) && GetHeadTime(sim->Delivery) <= now) {
        Dequeue(&(sim->Delivery), &id, &time);
        
        idx = ListIndexOf(foods, NewElType(0, (union Data){.i=id}));

        Enqueue(&sim->Inventory, id, GetVal(foods.contents[idx]).m.Kedaluarsa + time);
    }

}

void HapusMakananKedaluarsa(Simulator *sim)
/* I.S. sim, now terdefinisi */
/* F.S. seluruh isi inventory yang kedaluarsa dihapus */
{
    int tmp;
    Waktu time, now;

    now = GetTime(sim);

    while(!(IsEmptyPQ(sim->Inventory)) && GetHeadTime(sim->Inventory) <= now) {
        Dequeue(&(sim->Inventory), &tmp, &time);
    }
}

void TakeTime(Simulator *sim, int Hari, int Jam, int Menit, ListStatik foods){
/* I.S. sim terdefinisi */
/* F.S. waktu bertambah, dengan default bertambah selama 1 menit { TakeTime(&sim, 0, 0, 1) }
   Makanan kedaluarsa dihapus */

    // KAMUS LOKAL
    Waktu now;
    // ALGORITMA
    now = GetTime(sim);
    TambahWaktu(&now, Hari, Jam, Menit);
    SetTime(sim, now);
    HapusDelivery(sim, foods);
    HapusMakananKedaluarsa(sim);
}

void Wait(Simulator *sim, int Jam, int Menit, ListStatik foods){
/* I.S. sim terdefinisi, command WAIT x y dilakukan */
/* F.S. waktu bertambah selama x jam dan y menit
   Makanan kedaluarsa dihapus */

    // KAMUS LOKAL
    // ALGORITMA
    TakeTime(sim, 0, Jam, Menit, foods);
}

void DisplayInventory(Simulator sim){
/* Keluaran data inventory dengan ID Makanan
   dan waktu expirednya */
   
    // Kamus Lokal
    int i;
    PQInfoType elmt;
    Waktu currentTime;

    // ALGORITMA
;
    currentTime = GetTime(&sim);
    printf("--------------\n");
    if (!IsEmptyPQ(sim.Inventory)){
        for (i = sim.Inventory.Head;i <= sim.Inventory.Tail;i++){
            
            elmt.Info = (sim.Inventory).Tab[i].Info;
            elmt.Time = (sim.Inventory).Tab[i].Time - currentTime;
            DisplayInfoTypePQ(elmt);
            printf("\n");
        }
    }
    printf("--------------\n");
}
