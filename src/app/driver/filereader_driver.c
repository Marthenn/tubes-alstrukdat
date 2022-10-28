// C libraries

/* ADT */
#include "../../adt/headers/map.h"
#include "../../adt/headers/liststatik.h"

/* APP */
#include "../headers/filereader.h"


/* State Mesin Word */


int  main(){

    // KAMUS
	int i;
	Map map;
	ListStatik foods, recipes;
	
    // ALGORITMA
	ReadAllConfig(&map, &foods, &recipes);

	printf("====MAP====\n");
	DisplayCharMatriks(TAB(map));

	printf("====FOODS LIST====\n");
	DisplayList(foods);
	printf("\n");

	printf("====RECIPES LIST====\n");
	DisplayList(recipes);
	printf("\n");

	return 0;
}