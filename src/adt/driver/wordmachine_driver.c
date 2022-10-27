// C libraries
#include <stdio.h>

// headers
#include "../headers/boolean.h"

// implementations
#include "../implementasi/wordmachine.c"
#include "../implementasi/parser.c"

/* State Mesin Word */

int  main(){

    // KAMUS
	int i;

    // ALGORITMA

	STARTWORD();

	i = 0;

	// test from input
	while (EndWord == false && i < 10) {

        printf("input : ");
        
		DisplayWord(currentWord);

		printf("\n");

		ADVWORD();

		i++;
	}

	//test from file

	STARTFILEWORD("../../config/food_config.txt");

    while (EndFileWord == false)
    {
        DisplayWord(currentFileWord);
        printf("\n");

		if (currentFileChar == '\n')
		{
			ADV_FILE();
		}
		
        ADVFILEWORD();
    }
	
	return 0;
}