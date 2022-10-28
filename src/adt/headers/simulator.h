/* File: simulator.h */
/* ADT berisi nama pengguna, lokasi, dan inventory */

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "wordmachine.h"
#include "point.h"
#include "prioqueue.h"
#include "boolean.h"

typedef struct Simulator {
    Word NamaPengguna;
    Point Lokasi;
    PrioQueue Inventory;
} Simulator;

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

#endif