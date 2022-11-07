/* File: simulator.h */
/* ADT berisi nama pengguna, lokasi, dan inventory */

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../wordmachine/wordmachine.h"
#include "../point/point.h"
#include "../prioqueue/prioqueue.h"
#include "../../boolean.h"
#include "../waktu/waktu.h"
#include "../liststatik/liststatik.h"
#include "../listdineltype/listdineltype.h"
#include "../matriks/matriks.h"
#include "../makanan/makanan.h"

typedef struct Simulator {
    Word NamaPengguna;
    Point Lokasi;
    PrioQueue Inventory;
    PrioQueue Delivery;
    Waktu Time;
    ListDinElType Notification;
    ListDinElType InverseNotif;
    ListDinElType MakananKulkas;
    Matriks Kulkas;
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

ListDinElType GetNotif(const Simulator *sim);
/* Mengembalikan notifikasi saat ini*/

void SetNotif(Simulator *sim, ListDinElType newNotification, ListDinElType inverseNotif);
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

void HapusDelivery(Simulator *sim, ListStatik foods);
/* I.S. sim terdefinisi */
/* F.S. makanan dengan waktu delivery yang melewati waktu saat ini dimasukkan ke inventory */
void HapusMakananKedaluarsa(Simulator *sim, ListStatik foods);
/* I.S. sim, now terdefinisi */
/* F.S. seluruh isi inventory yang kedaluarsa dihapus */

void TakeTime(Simulator *sim, int Hari, int Jam, int Menit, ListStatik foods);
/* I.S. sim terdefinisi */
/* F.S. waktu bertambah, dengan default bertambah selama 1 menit
   Makanan kedaluarsa dihapus */

void Wait(Simulator *sim, int Jam, int Menit, ListStatik foods);
/* I.S. sim terdefinisi, command WAIT x y dilakukan */
/* F.S. waktu bertambah selama x jam dan y menit
   Makanan kedaluarsa dihapus */

void ClearAllIdKulkas(Simulator *sim, int id);
/* I.S. sim terdefinisi, id bisa tidak ada di kulkas */
/* F.S> semua elemen dengan nilai id pada kulkas akan menjadi nol */

boolean CheckSizeKulkas(Simulator sim, Makanan food, int X, int Y, boolean rotated);
/* I.S. sim terdefinisi dengan kulkas */
/* F.S. mengembalikan apakah makanan muat di kulkas pada posisi (X,Y) */

void PutFood(Simulator *sim, int idx, int X, int Y, boolean rotated, ListStatik foods, boolean *success);
/* I.S. sim terdefinisi */
/* F.S. apabila makanan muat pada koordinat (X,Y), maka akan masuk ke kulkas */

void TakeFood(Simulator *sim, int id);
/* I.S. sim terdefinisi, id pasti ada di kulkas */
/* F.S. bila ada pada kulkas ada makanan dengan IdMakananKulkas maka diambil */

boolean IsKulkasEmpty(Simulator sim);
/* I.S. sim terdefinisi */
/* F.S. mengembalikan apakah kulkas kosong */

#endif
