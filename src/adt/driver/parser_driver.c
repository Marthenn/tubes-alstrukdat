// C libraries
#include <stdio.h>

// headers
#include "../headers/boolean.h"
#include "../headers/parser.h"

// implementations
#include "../implementasi/parser.c"
#include "../implementasi/wordmachine.c"

/* State Mesin Word */


int  main(){

    // KAMUS
	int i, res;

    // ALGORITMA

	STARTWORD();

	while (EndWord == false) {

		printf("input sebenarnya (case-sensitive) : ");
		DisplayWord(currentWord);
		printf("\n");
		
        if (IsWordEqual(START_WORD) == true)
		{
			printf("input command START\n");
		}

		else if (IsWordEqual(EXIT_WORD) == true)
		{
			printf("input command EXIT\n");
		}

		else if (IsWordEqual(BUY_WORD) == true)
		{
			printf("input command BUY\n");
		}

		else if (IsWordEqual(DELIVERY_WORD) == true)
		{
			printf("input command DELIVERY\n");
		}

		else if (IsWordEqual(MOVE_NORTH_WORD) == true)
		{
			printf("input command MOVE NORTH\n");
		}

		else if (IsWordEqual(MOVE_EAST_WORD) == true)
		{
			printf("input command MOVE EAST\n");
		}

		else if (IsWordEqual(MOVE_WEST_WORD) == true)
		{
			printf("input command MOVE WEST\n");
		}
		else if (IsWordEqual(MOVE_SOUTH_WORD) == true)
		{
			printf("input command MOVE SOUTH\n");
		}
		
		else if (IsWordEqual(MIX_WORD) == true)
		{
			printf("input command MIX\n");
		}
		
		else if (IsWordEqual(CHOP_WORD) == true)
		{
			printf("input command CHOP\n");
		}
		
		else if (IsWordEqual(FRY_WORD) == true)
		{
			printf("input command FRY\n");
		}
		
		else if (IsWordEqual(BOIL_WORD) == true)
		{
			printf("input command BOIL\n");
		}
		
		else if (IsWordEqual(WAIT_WORD) == true)
		{
			printf("input command WAIT\n");
		}
		
		else if (IsWordEqual(UNDO_WORD) == true)
		{
			printf("input command UNDO\n");
		}
		
		else if (IsWordEqual(REDO_WORD) == true)
		{
			printf("input command REDO\n");
		}
		
		else if (IsWordEqual(CATALOG_WORD) == true)
		{
			printf("input command CATALOG\n");
		}
		
		else if (IsWordEqual(COOKBOOK_WORD) == true)
		{
			printf("input command COOKBOOK\n");
		}
		
		else {
			printf("Input command tidak valid\n");
		}

		res =  WordToInt(currentWord);
		printf("representasi integer dari input : %d", res);

		if (res == NUM_UNDEF) {
			printf(" (input is not number)");
		}

		printf("\n");
		ADVWORD();
	}

	return 0;
}