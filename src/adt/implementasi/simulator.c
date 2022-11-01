/* File: simulator.c */
/* Body ADT simulator */

#include <stdio.h>
#include "../headers/simulator.h"
#include "../../app/headers/parser.h"

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

    SetTime(sim, newTime);

    SetNotif(sim, EMPTY_NOTIF);
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

void HapusMakananKedaluarsa(Simulator *sim, Waktu now)
/* I.S. sim, now terdefinisi */
/* F.S. seluruh isi inventory yang kedaluarsa dihapus */
{
    int tmp;
    Waktu time;
    while(!(IsEmptyPQ(sim->Inventory)) && GetHeadTime(sim->Inventory) <= now) {
        Dequeue(&(sim->Inventory), &tmp, &time);
    }
}