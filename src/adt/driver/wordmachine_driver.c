/* File: wordmachine.c */
/* Definisi Word Machine: Model Akuisisi Versi I */

// C libraries
#include <stdio.h>

// headers
#include "../headers/boolean.h"

// implementations
#include "../implementasi/wordmachine.c"

/* State Mesin Word */

int  main(){

    // KAMUS
	int i;

    // ALGORITMA

	STARTWORD();

	while (EndWord == false) {

        printf("input : ");
        
		for (i=0;i<currentWord.Length;i++) {

			printf("%c", currentWord.TabWord[i]);

		}

		printf("\n");
		ADVWORD();
	}

	return 0;
}