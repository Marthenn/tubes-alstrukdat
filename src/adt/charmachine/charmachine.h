/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

/* ADT */
#include "../../boolean.h"

#define MARK '\0'

/* State Mesin */
extern char currentChar, currentFileChar;
extern boolean EOP, FILE_EOP;

void START_INPUT();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void START_FILE(char* path);

       /* Mesin siap dioperasikan. Pita berupa file txt disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentFileChar adalah karakter pertama pada pita. Jika tidak EOF maka FILE_EOP akan padam (false).
                 Jika EOF maka FILE_EOP akan menyala (true) */

       /* Algoritma */

void ADV_FILE();

       /* Pita file txt dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentFileChar,
          F.S. : currentFileChar adalah karakter berikutnya dari currentFileChar yang lama,
                 Proses pembacaan mungkin mencapai EOF
                       Jika  EOF maka FILE_EOP akan menyala (true) */

#endif
