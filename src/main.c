#include <stdio.h>

/* ADT */
/* APP */

#include "app/commands/commands.h"

int main(){

    // KAMUS
    Simulator simulator;
    Map map;
    ListStatik foods, recipes; 
    Word n;
    ListDinElType buyFoods,mixFoods,chopFoods,fryFoods,boilFoods, wordList;
    Stack undoStack, redoStack;

	// NOTE : inventoryRecord dan deliveryRecord BUKAN inventory dan delivery yang di ada di dalam simulator
	PrioQueue inventoryRecord, deliveryRecord;

	boolean isStarted, isUndo;
    int x, y;
    
    // ALGORITMA

	isStarted = false;
	isUndo = false;

	CreateEmptyPQ(&inventoryRecord);
    StartScreen();

	printf("Enter Command: ");
	STARTWORD();

    while(true)
    {
		if (isStarted == false)
		{	
			if (IsInputEqual(START_WORD))
			{
				Start(&simulator, &foods, &recipes, &map, &buyFoods, &mixFoods, &chopFoods, &fryFoods, &boilFoods, &undoStack, &redoStack);

				isStarted = true;
			}

			else if (IsInputEqual(EXIT_WORD))
			{
				printf("Exiting the simulator...\n");
				return 0;
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

			if (IsInputEqual(BUY_WORD))
			{
				Buy(&simulator, foods, recipes, map, buyFoods, &undoStack);
			}

			else if (IsInputEqual(DELIVERY_WORD))
			{
				DisplayDelivery(foods, simulator);
			}

			else if (IsInputEqual(MOVE_EAST_WORD))
			{
				Move(&simulator, &map, 0, foods);
			}

			else if (IsInputEqual(MOVE_WEST_WORD))
			{
				Move(&simulator, &map, 1, foods);
			}

			else if (IsInputEqual(MOVE_NORTH_WORD))
			{
				Move(&simulator, &map, 2, foods);
			}
			else if (IsInputEqual(MOVE_SOUTH_WORD))
			{
				Move(&simulator, &map, 3, foods);
			}
			
			else if (IsInputEqual(MIX_WORD))
			{
				Mix(&simulator,foods,recipes,map,mixFoods,&undoStack);
			}
			
			else if (IsInputEqual(CHOP_WORD))
			{
				Chop(&simulator,foods,recipes,map,chopFoods,&undoStack);
			}
			
			else if (IsInputEqual(FRY_WORD))
			{
				Fry(&simulator,foods,recipes,map,fryFoods,&undoStack);
			}
			
			else if (IsInputEqual(BOIL_WORD))
			{
				Boil(&simulator,foods,recipes,map,boilFoods,&undoStack);
			}
			
			else if (IsInputEqual(UNDO_WORD))
			{
				isUndo = true;
				printf("input command UNDO\n");
			}
			
			else if (IsInputEqual(REDO_WORD))
			{
				printf("input command REDO\n");
			}
			
			else if (IsInputEqual(CATALOG_WORD))
			{
				Catalog(foods);
			}
			
			else if (IsInputEqual(COOKBOOK_WORD))
			{
				CookBook(foods, recipes, mixFoods, chopFoods, fryFoods, boilFoods);
			}

			else if (IsInputEqual(HELP_WORD)) 
			{
				Help();
			}

			else if(IsInputEqual(INVENTORY_WORD))
			{
				DisplayInventory(simulator);
			}
			
			else if (IsInputPrefixEqual(WAIT_WORD) && ListDinElTypeLength(wordList) == 3)
			{
				x = WordToInt(GetVal(wordList.buffer[1]).w);
				y = WordToInt(GetVal(wordList.buffer[2]).w);

				if (x != NUM_UNDEF && y != NUM_UNDEF)
				{
					Wait(&simulator, x, y, foods);
				}

				else {
					printf("Command tidak valid!\n");
					printf("(Masukkan command 'help' untuk melihat semua perintah yang valid)\n");
				}
			}

			else if (IsInputEqual(EXIT_WORD))
			{
				printf("Exiting the simulator...\n");
				return 0;
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
			// 	UpdateStack(simulator, inventoryRecord, deliveryRecord, &undoStack);
			// 	CreateEmptyStack(&redoStack);
			// }
		}
    }

    return 0;
}