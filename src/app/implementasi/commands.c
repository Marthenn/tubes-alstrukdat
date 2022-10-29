/* C libraries */
#include <stdio.h>
#include <stdlib.h>
/* APP */
#include "../headers/commands.h"

void Start(Map* map, ListStatik* foods,  ListStatik* recipes, Word* name){
    ReadAllConfig(map, foods, recipes);
    printf("Masukkan nama Anda: ");STARTWORD();*name = currentWord;
    printf("Selamat datang ");DisplayWord(*name);printf("!\n");
}

void Exit(){
    printf("Exiting the simulator...\n");
    exit(0);
}