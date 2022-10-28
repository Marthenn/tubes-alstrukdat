/* C libraries*/
#include <stdio.h>

/* ADT */
#include "../headers/boolean.h"
#include "../headers/charmachine.h"
#include "../headers/wordmachine.h"

/* APP */
#include "../../app/headers/parser.h"

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