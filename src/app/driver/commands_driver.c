#include <stdio.h>
#include "../headers/commands.h"

int main(){
    Simulator s;
    Map m;ListStatik f,r;Word n;
    ListDinElType bf,mf,cf,ff,bof;
    Start(&s,&m,&f,&r,&bf,&mf,&cf,&ff,&bof);
    printf("====MAP====\n");
    DisplayCharMatriks(TAB(m));
    printf("====FOODS LIST====\n");
    DisplayList(f);
    printf("\n");
    printf("====RECIPES LIST====\n");
    DisplayList(r);
    printf("\n");
    printf("====BUY FOODS LIST====\n");
    DisplayListDinElType(bf);
    printf("\n");
    printf("====MIX FOODS LIST====\n");
    DisplayListDinElType(mf);
    printf("\n");
    printf("====CHOP FOODS LIST====\n");
    DisplayListDinElType(cf);
    printf("\n");
    printf("====FRY FOODS LIST====\n");
    DisplayListDinElType(ff);
    printf("\n");
    printf("====BOIL FOODS LIST====\n");
    DisplayListDinElType(bof);
    printf("\n");
    printf("====PROCESS FOODS====\n");
    // proses makanan di sini (cek semuanya)
    Exit();
    printf("This shouldnot be printed\n");
}