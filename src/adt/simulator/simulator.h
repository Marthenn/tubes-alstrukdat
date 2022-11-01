/* File: simulator.h */
/* ADT berisi nama pengguna, lokasi, dan inventory */

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../wordmachine/wordmachine.h"
#include "../point/point.h"
#include "../prioqueue/prioqueue.h"
#include "../../boolean.h"
#include "../waktu/waktu.h"

typedef struct Simulator {
    Word NamaPengguna;
    Point Lokasi;
    PrioQueue Inventory;
    Waktu Time;
    Word Notification;
} Simulator;

#define EMPTY_NOTIF NewWord("-", 1)

/* *** KONSTRUKTOR *** */
void CreateEmptySimulator(Simulator *sim, Word NamaPengguna);
/* I.S. sim bebas, NamaPengguna terdefinisi */
/* F.S. terbentuk Simulator sim dengan Lokasi = (0, 0) dan Inventory kosong */

/* *** SETTER / GETTER *** */
void SetLokasi(Simulator *sim, Point Lokasi);
/* I.S. sim telah dibentuk, Lokasi terdefinisi */
/* F.S. Mengubah Lokasi sim */

/* NamaPengguna dan Inventory tidak ada setter manual */

Point GetLokasi(const Simulator *sim);
/* Mengembalikan Point berisi lokasi pengguna */
Word GetNamaPengguna(const Simulator *sim);
/* Mengembalikan Word berisi NamaPengguna */

Waktu GetTime(const Simulator *sim);
/* Mengembalikan waktu saat ini*/

void SetTime(Simulator *sim, Waktu newTime);
/* I.S. sim telah dibentuk, newTime terdefinisi */
/* F.S. Mengubah waktu sim */

Word GetNotif(const Simulator *sim);
/* Mengembalikan notifikasi saat ini*/

void SetNotif(Simulator *sim, Word newNotification);
/* I.S. sim telah dibentuk, newNotification terdefinisi */
/* F.S. Mengubah notifikasi sim */

/* *** OPERASI TERHADAP LOKASI *** */
/* Ada di ADT Point */

/* *** OPERASI TERHADAP INVENTORY *** */
boolean DeleteMakanan(Simulator *sim, int ID);
/* Jika ada makanan ID, Menghapus kemunculan pertama dari ID dan return true */
/* Jika tidak, return false */

void InsertMakanan(Simulator *sim, int ID, Waktu kedaluarsa);
/* I.S. sim terdefinisi. kedaluarsa = waktu sekarang + waktu kedaluarsa makanan */
/* F.S. sim->Inventory ditambahkan makanan */

void HapusMakananKedaluarsa(Simulator *sim, Waktu now);
/* I.S. sim, now terdefinisi */
/* F.S. seluruh isi inventory yang kedaluarsa dihapus */

void TakeTime(Simulator *sim, int Hari, int Jam, int Menit);
/* I.S. sim terdefinisi */
/* F.S. waktu bertambah, dengan default bertambah selama 1 menit
   Makanan kedaluarsa dihapus */

void Wait(Simulator *sim, int Jam, int Menit);
/* I.S. sim terdefinisi, command WAIT x y dilakukan */
/* F.S. waktu bertambah selama x jam dan y menit
   Makanan kedaluarsa dihapus */

void DisplayInventory(Simulator sim);
/* Keluaran data inventory dengan ID Makanan
   dan waktu expirednya */

#endif
