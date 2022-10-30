/* C libraries */
#include <stdio.h>
#include <stdlib.h>
/* APP */
#include "../headers/commands.h"

void Start(Map* map, ListStatik* foods,  ListStatik* recipes, Simulator* simulator){
    ReadAllConfig(map, foods, recipes);
    printf("Masukkan nama Anda: ");STARTWORD();(*simulator).NamaPengguna = currentWord;
    printf("Selamat datang ");DisplayWord((*simulator).NamaPengguna);printf("!\n");
}

void Exit(){
    printf("Exiting the simulator...\n");
    exit(0);
}

void Buy(Simulator* simulator, ListStatik foods, ListStatik recipes, Map map){
    if(!(IsAdjacent((*simulator).Lokasi,T(map)))){
        DisplayWord((*simulator).NamaPengguna);
        printf(" tidak berada di area telepon!\n");
    } else {
        BuyMenu(foods, recipes);
    }
}