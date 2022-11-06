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
	Waktu timeRecord;
	Point locationRecord;

	// NOTE : inventoryRecord dan deliveryRecord BUKAN inventory dan delivery yang di ada di dalam simulator
	PrioQueue inventoryRecord, deliveryRecord;

	boolean isStarted, isUndo, stay, isRedo, success;
    int x, y;
    
    // ALGORITMA

	isStarted = false;
	isUndo = false;
	isRedo = false;
	stay = false;

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

				CreateEmptyPQ(&inventoryRecord);
				CreateEmptyPQ(&deliveryRecord);

				timeRecord = GetTime(&simulator);
				locationRecord = GetLokasi(&simulator);

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
			success = false;

			DisplayMap(map);
			
			printf("BNMO di posisi: ");
			CetakPoint(GetLokasi(&simulator));
			printf("\n");

			printf("Waktu: ");
			CetakWaktuJJMM(GetTime(&simulator));
			printf("\n");

			printf("Notifikasi:\n");
			DisplayNotif(simulator);

			CreateListDinElType(&simulator.Notification, 0);
			CreateListDinElType(&simulator.InverseNotif, 0);
			
			EnterCommand();

			wordList = SplitWord(currentWord, ' ');

			if (IsInputEqual(BUY_WORD))
			{
				Buy(&simulator, foods, recipes, map, buyFoods, &undoStack, &success);
			}

			else if (IsInputEqual(DELIVERY_WORD))
			{
				DisplayDelivery(foods, simulator);
				stay = true;
			}

			else if (IsInputEqual(MOVE_EAST_WORD))
			{
				Move(&simulator, &map, 0, foods, &success);
			}

			else if (IsInputEqual(MOVE_WEST_WORD))
			{
				Move(&simulator, &map, 1, foods, &success);
			}

			else if (IsInputEqual(MOVE_NORTH_WORD))
			{
				Move(&simulator, &map, 2, foods, &success);
			}
			else if (IsInputEqual(MOVE_SOUTH_WORD))
			{
				Move(&simulator, &map, 3, foods, &success);
			}
			
			else if (IsInputEqual(MIX_WORD))
			{
				Mix(&simulator,foods,recipes,map,mixFoods,&undoStack, &success);
			}
			
			else if (IsInputEqual(CHOP_WORD))
			{
				Chop(&simulator,foods,recipes,map,chopFoods,&undoStack, &success);
			}
			
			else if (IsInputEqual(FRY_WORD))
			{
				Fry(&simulator,foods,recipes,map,fryFoods,&undoStack, &success);
			}
			
			else if (IsInputEqual(BOIL_WORD))
			{
				Boil(&simulator,foods,recipes,map,boilFoods,&undoStack, &success);
			}
			
			else if (IsInputEqual(UNDO_WORD))
			{
				isUndo = true;
				Undo(&simulator, inventoryRecord, deliveryRecord, &undoStack, &redoStack, timeRecord, locationRecord, &map);
			}
			
			else if (IsInputEqual(REDO_WORD))
			{
				isRedo = true;
				Redo(&simulator, inventoryRecord, deliveryRecord, &undoStack, &redoStack, timeRecord, locationRecord, &map);
			}
			
			else if (IsInputEqual(CATALOG_WORD))
			{
				Catalog(foods);
				stay = true;
			}
			
			else if (IsInputEqual(COOKBOOK_WORD))
			{
				CookBook(foods, recipes, mixFoods, chopFoods, fryFoods, boilFoods);
				stay = true;
			}

			else if (IsInputEqual(HELP_WORD)) 
			{
				Help();
				stay = true;
			}

			else if(IsInputEqual(INVENTORY_WORD))
			{
				DisplayInventory(foods, simulator);
				stay = true;
			}
			
			else if (IsInputPrefixEqual(WAIT_WORD) && ListDinElTypeLength(wordList) == 3)
			{
				x = WordToInt(GetVal(wordList.buffer[1]).w);
				y = WordToInt(GetVal(wordList.buffer[2]).w);

				if (x != NUM_UNDEF && y != NUM_UNDEF)
				{
					Wait(&simulator, x, y, foods);
					success = true;
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
				stay = true;
			}

			if (isUndo || isRedo)
			{
				isUndo = false;
				isRedo = false;
			}

			else if (stay)
			{
				stay = false;
			}

			else if (success) {
				int i;

				UpdateStack(simulator, inventoryRecord, deliveryRecord, &undoStack, timeRecord, locationRecord);

				if (!IsStackEmpty(redoStack))
				{
					CreateEmptyStack(&redoStack);
				}
			}

			AssignPQ(simulator.Delivery, &deliveryRecord);
			AssignPQ(simulator.Inventory, &inventoryRecord);

			timeRecord = GetTime(&simulator);
			locationRecord = GetLokasi(&simulator);
			
			success = false;
		}
    }
	
    return 0;
}