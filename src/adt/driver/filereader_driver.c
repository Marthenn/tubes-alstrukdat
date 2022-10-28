// C libraries

// headers
#include "../headers/boolean.h"
#include "../headers/filereader.h"


// implementations
#include "../implementasi/filereader.c"

/* State Mesin Word */


int  main(){

    // KAMUS
	int i;
	Matriks map;
	ListStatik foods;
	
    // ALGORITMA
	ReadAllConfig(&map, &foods);

	DisplayMatriks(map);
	DisplayList(foods);

	return 0;
}