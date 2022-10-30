#include <stdio.h>
#include "../headers/commands.h"

int main(){
    Map m;ListStatik f,r;Word n;
    Start(&m,&f,&r,&n);
    printf("====MAP====\n");
    DisplayCharMatriks(TAB(m));
    printf("====FOODS LIST====\n");
    DisplayList(f);
    printf("\n");
    printf("====RECIPES LIST====\n");
    DisplayList(r);
    printf("\n");
    Exit();
    printf("This shouldnot be printed\n");
}