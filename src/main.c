#include <stdio.h>
//include semuanya 👍

/* ADT */
/* APP */

#include "app/headers/commands.h"

int main(){

    // KAMUS
    Simulator simulator;
    Map map;
    ListStatik foods, recipes; 
    Word n;
    ListDinElType buyFoods,mixFoods,chopFoods,fryFoods,boilFoods, wordList;
    Stack undoStack, redoStack;
	PrioQueue inventoryRecord, deliveryRecord, delivery;

	boolean isStarted, isUndo;
    int x, y;
    
    // ALGORITMA

	isStarted = false;
	isUndo = false;

	CreateEmptyPQ(&inventoryRecord);
	CreateEmptyPQ(&deliveryRecord);
    StartScreen();

	printf("Enter Command: ");
	STARTWORD();

    while(true)
    {
		if (isStarted == false)
		{	
			if (IsInputEqual(START_WORD))
			{
				Start(&simulator, &foods, &recipes, &map, &buyFoods, &mixFoods, &chopFoods, &fryFoods, &boilFoods, &delivery, &undoStack, &redoStack);

				isStarted = true;
			}

			else if (IsInputEqual(EXIT_WORD))
			{
				Exit();
			}

			else
			{
				printf("Command tidak valid!\n");
				EnterCommand();
			}
			
		}
		
		else
		{
			DisplayMap(map);
			
			printf("BNMO di posisi: ");
			CetakPoint(GetLokasi(&simulator));
			printf("\n");

			printf("Waktu: ");
			CetakWaktuJJMM(GetTime(&simulator));
			printf("\n");

			printf("Notifikasi: ");
			DisplayWordLine(GetNotif(&simulator));

			EnterCommand();

			wordList = SplitWord(currentWord, ' ');

			if (IsInputEqual(BUY_WORD) == true)
			{
				printf("input command BUY\n");
			}

			else if (IsInputEqual(DELIVERY_WORD) == true)
			{
				printf("input command DELIVERY\n");
			}

			else if (IsInputEqual(MOVE_EAST_WORD) == true)
			{
				Move(&simulator, &map, 0);
			}

			else if (IsInputEqual(MOVE_WEST_WORD) == true)
			{
				Move(&simulator, &map, 1);
			}

			else if (IsInputEqual(MOVE_NORTH_WORD) == true)
			{
				Move(&simulator, &map, 2);
			}
			else if (IsInputEqual(MOVE_SOUTH_WORD) == true)
			{
				Move(&simulator, &map, 3);
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
			
			else if (IsInputEqual(UNDO_WORD) == true)
			{
				isUndo = true;
				printf("input command UNDO\n");
			}
			
			else if (IsInputEqual(REDO_WORD) == true)
			{
				printf("input command REDO\n");
			}
			
			else if (IsInputEqual(CATALOG_WORD) == true)
			{
				Catalog(foods);
			}
			
			else if (IsInputEqual(COOKBOOK_WORD) == true)
			{
				CookBook(foods, recipes, mixFoods, chopFoods, fryFoods, boilFoods);
			}

			else if (IsInputEqual(HELP_WORD) == true) 
			{
				Help();
			}
			
			else if (IsInputPrefixEqual(WAIT_WORD) == true && ListDinElTypeLength(wordList) == 3)
			{
				x = WordToInt(GetVal(wordList.buffer[1]).w);
				y = WordToInt(GetVal(wordList.buffer[2]).w);

				if (x != NUM_UNDEF && y != NUM_UNDEF)
				{
					printf("input command WAIT %d %d\n", x, y);
				}

				else {
					printf("Command tidak valid!\n");
					printf("(Masukkan command 'help' untuk melihat semua perintah yang valid)\n");
				}
			}

			else if (IsInputEqual(EXIT_WORD) == true)
			{
				Exit();
			}

			else {
				printf("Command tidak valid!\n");
				printf("(Masukkan command 'help' untuk melihat semua perintah yang valid)\n");
			}

			// if (isUndo)
			// {
			// 	isUndo = false;
			// }

			// else {
			// 	UpdateStack(simulator, delivery, inventoryRecord, deliveryRecord, &undoStack);
			// }


			// else {
			// 	UpdateStack(simulator, delivery, inventoryRecord, deliveryRecord, &undoStack);
			// }
		}
    }

    return 0;
}