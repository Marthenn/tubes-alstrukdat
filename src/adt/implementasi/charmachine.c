/* File: charmachine.c */
/* Implementasi Mesin Karakter */

// C libraries
#include <stdio.h>
#include <stdlib.h>

// headers
#include "../headers/charmachine.h"

char currentChar, currentFileChar;
boolean EOP, FILE_EOP;

static FILE *pita, *file;
static int retval;

void START()
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       pita = stdin;
       ADV();
}

void ADV()
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */

       retval = fscanf(pita, "%c", &currentChar);

       EOP = (!retval);

       if (EOP)
       {
              fclose(pita);
       }
}

void START_FILE(char *path)
{
       /* Mesin siap dioperasikan. Pita berupa file txt disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */

       FILE_EOP = false;

       file = fopen("../../config/food_config.txt", "r");

       if (file)
       {
              printf("Reading file in relative path %s\n", path);
              ADV_FILE();
       }
       
       else{
              FILE_EOP = true;
              printf("Failed to read %s\n", path);
       }
}

void ADV_FILE()
{
       /* Pita file txt dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */

       //printf("%d", FILE_EOP);
       retval = fscanf(file, "%c", &currentFileChar);

       FILE_EOP = (retval == EOF);
     
       if (FILE_EOP)
       {
              fclose(file);
       }
}
