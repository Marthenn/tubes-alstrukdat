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
	Word kalimat, copyResult;

    // ALGORITMA

	STARTWORD();
	kalimat = EMPTY_WORD;
	while (EndWord == false) {

		printf("input sebenarnya (case-sensitive) : ");
		DisplayWord(currentWordParser);
		printf("\n");
		
        if (IsInputEqual(START_WORD) == true)
		{
			printf("input command START\n");
		}

		else if (IsInputEqual(EXIT_WORD) == true)
		{
			printf("input command EXIT\n");
		}

		else if (IsInputEqual(BUY_WORD) == true)
		{
			printf("input command BUY\n");
		}

		else if (IsInputEqual(DELIVERY_WORD) == true)
		{
			printf("input command DELIVERY\n");
		}

		else if (IsInputEqual(MOVE_NORTH_WORD) == true)
		{
			printf("input command MOVE NORTH\n");
		}

		else if (IsInputEqual(MOVE_EAST_WORD) == true)
		{
			printf("input command MOVE EAST\n");
		}

		else if (IsInputEqual(MOVE_WEST_WORD) == true)
		{
			printf("input command MOVE WEST\n");
		}
		else if (IsInputEqual(MOVE_SOUTH_WORD) == true)
		{
			printf("input command MOVE SOUTH\n");
		}
		
		else if (IsInputEqual(MIX_WORD) == true)
		{
			printf("input command MIX\n");
		}
		
		else if (IsInputEqual(CHOP_WORD) == true)
		{
			printf("input command CHOP\n");
		}
		
		else if (IsInputEqual(FRY_WORD) == true)
		{
			printf("input command FRY\n");
		}
		
		else if (IsInputEqual(BOIL_WORD) == true)
		{
			printf("input command BOIL\n");
		}
		
		else if (IsInputEqual(WAIT_WORD) == true)
		{
			printf("input command WAIT\n");
		}
		
		else if (IsInputEqual(UNDO_WORD) == true)
		{
			printf("input command UNDO\n");
		}
		
		else if (IsInputEqual(REDO_WORD) == true)
		{
			printf("input command REDO\n");
		}
		
		else if (IsInputEqual(CATALOG_WORD) == true)
		{
			printf("input command CATALOG\n");
		}
		
		else if (IsInputEqual(COOKBOOK_WORD) == true)
		{
			printf("input command COOKBOOK\n");
		}
		
		else {
			printf("Input command tidak valid\n");
		}

		res =  WordToInt(currentWordParser);
		printf("representasi integer dari input : %d", res);

		if (res == NUM_UNDEF) {
			printf(" (input is not number)");
		}
		
		printf("\n");

		CopyDefinedWord(&copyResult, currentWordParser);
		
		printf("Hasil copy dari currentWord : ");
		DisplayWordLine(copyResult);

		ConcatWord(&kalimat, currentWordParser);
		ConcatWord(&kalimat, BLANK_WORD);
		printf("Kata gabungan dari awal : ");
		DisplayWordLine(kalimat);

		if (kalimat.Length >= NMax)
		{
			printf("[KALIMAT PENUH!]\n");

		}
		ADVWORD();
	}

	return 0;
}