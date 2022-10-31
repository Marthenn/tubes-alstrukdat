#include <stdio.h>
#include "../headers/commands.h"

int main(){
    Simulator simulator;
    Map map;ListStatik foods, recipes; Word n;
    ListDinElType buyFoods,mixFoods,chopFoods,fryFoods,boilFoods;
    Stack undoRecord, redoRecord;
    
    Start(&simulator, &foods, &recipes, &map, &buyFoods, &mixFoods, &chopFoods, &fryFoods, &boilFoods, &undoRecord, &redoRecord);
    printf("====MAP====\n");
    DisplayCharMatriks(TAB(map));
    printf("====FOODS LIST====\n");
    DisplayList(foods);
    printf("\n");
    printf("====RECIPES LIST====\n");
    DisplayList(foods);
    printf("\n");
    printf("====BUY FOODS LIST====\n");
    PrintListDinElType(buyFoods);
    printf("\n");
    printf("====MIX FOODS LIST====\n");
    PrintListDinElType(mixFoods);
    printf("\n");
    printf("====CHOP FOODS LIST====\n");
    PrintListDinElType(chopFoods);
    printf("\n");
    printf("====FRY FOODS LIST====\n");
    PrintListDinElType(fryFoods);
    printf("\n");
    printf("====BOIL FOODS LIST====\n");
    PrintListDinElType(boilFoods);
    printf("\n");
    printf("====PROCESS FOODS====\n");
    // proses makanan di sini (cek semuanya)
    Exit();
    printf("This should not be printed\n");
}