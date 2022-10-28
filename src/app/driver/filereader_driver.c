// C libraries

/* ADT */
// headers
#include "../../adt/headers/boolean.h"
#include "../../adt/headers/map.h"

/* APP */

// headers
#include "../headers/filereader.h"

// implementations
#include "../implementasi/filereader.c"

/* State Mesin Word */


int  main(){

    // KAMUS
	int i;
	Map map;
	ListStatik foods, recipes;
	
    // ALGORITMA
	ReadAllConfig(&map, &foods, &recipes);

	// DisplayMatriks(map);
	DisplayList(foods);

	return 0;
}