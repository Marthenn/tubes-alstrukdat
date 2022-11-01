// C libraries

/* ADT */
#include "../../adt/map/map.h"
#include "../../adt/liststatik/liststatik.h"

/* APP */
#include "filereader.h"


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