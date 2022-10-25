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
	int i;

    // ALGORITMA

	STARTWORD();

	while (EndWord == false) {

		printf("input sebenarnya (case-sensitive) : ");
		DisplayWord(currentWord);
		printf("\n");
		
        if (IsPrefixEqual(START_WORD) == true)
		{
			printf("input command START\n");
		}

		else if (IsPrefixEqual(EXIT_WORD) == true)
		{
			printf("input command EXIT\n");
		}

		else if (IsPrefixEqual(BUY_WORD) == true)
		{
			printf("input command BUY\n");
		}

		else if (IsPrefixEqual(DELIVERY_WORD) == true)
		{
			printf("input command DELIVERY\n");
		}

		else if (IsPrefixEqual(MOVE_NORTH_WORD) == true)
		{
			printf("input command MOVE NORTH\n");
		}

		else if (IsPrefixEqual(MOVE_EAST_WORD) == true)
		{
			printf("input command MOVE EAST\n");
		}

		else if (IsPrefixEqual(MOVE_WEST_WORD) == true)
		{
			printf("input command MOVE WEST\n");
		}
		else if (IsPrefixEqual(MOVE_SOUTH_WORD) == true)
		{
			printf("input command MOVE SOUTH\n");
		}
		
		else if (IsPrefixEqual(MIX_WORD) == true)
		{
			printf("input command MIX\n");
		}
		
		else if (IsPrefixEqual(CHOP_WORD) == true)
		{
			printf("input command CHOP\n");
		}
		
		else if (IsPrefixEqual(FRY_WORD) == true)
		{
			printf("input command FRY\n");
		}
		
		else if (IsPrefixEqual(BOIL_WORD) == true)
		{
			printf("input command BOIL\n");
		}
		
		else if (IsPrefixEqual(WAIT_WORD) == true)
		{
			printf("input command WAIT\n");
		}
		
		else if (IsPrefixEqual(UNDO_WORD) == true)
		{
			printf("input command UNDO\n");
		}
		
		else if (IsPrefixEqual(REDO_WORD) == true)
		{
			printf("input command REDO\n");
		}
		
		else if (IsPrefixEqual(CATALOG_WORD) == true)
		{
			printf("input command CATALOG\n");
		}
		
		else if (IsPrefixEqual(COOKBOOK_WORD) == true)
		{
			printf("input command COOKBOOK\n");
		}
		
		else {
			printf("Input command tidak valid\n");
		}

		ADVWORD();
	}

	return 0;
}