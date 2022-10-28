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

	DisplayCharMatriks(TAB(map));
	DisplayList(foods);

	return 0;
}