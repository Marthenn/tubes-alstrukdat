#include <stdio.h>
#include "listdineltype.h"

int main() {

    // KAMUS LOKAL
    ListDinElType l, l2;
    int input, val, idx, cap;
    ElType eltypeVal;

    // ALGORITMA

    CreateListDinElType(&l, 2);

    while (true)
    {

        printf("======MENU======\n");
        printf("[0] create new list din\n");
        printf("[1] deallocate\n");
        printf("[2] insert first\n");
        printf("[3] insert last\n");
        printf("[4] delete first\n");
        printf("[5] delete last\n");
        printf("[6] compress\n");
        printf("current list : ");
        PrintListDinElType(l);
        printf("\n");
        printf("current list length : %d\n", ListDinElTypeLength(l));
        printf("current list capacity : %d\n", LISTDIN_CAP(l));
        printf("\n");
        printf("input : ");

        scanf("%d", &input);

        if (input == 0)
        {
            scanf("%d", &cap);
            DeallocateListDinElType(&l);
            CreateListDinElType(&l, cap);
        }

        else if (input == 1)
        {
            DeallocateListDinElType(&l);
        }

        else if (input == 2)
        {
            scanf("%d", &val);
            eltypeVal = NewElType(0, (union Data){.i=val});
            InsertFirstListDinElType(&l, eltypeVal);
        }

        else if (input == 3)
        {   
            scanf("%d", &val);
            eltypeVal = NewElType(0, (union Data){.i=val});
            InsertLastListDinElType(&l, eltypeVal);
        }

        else if (input == 4)
        {
            DeleteFirstListDinElType(&l, &eltypeVal);
            val = GetVal(eltypeVal).i;
            printf("deleted element : %d\n", val);
        }

        else if (input == 5)
        {
            DeleteLastListDinElType(&l, &eltypeVal);
            val = GetVal(eltypeVal).i;
            printf("deleted element : %d\n", val);
        }

        else if (input == 6)
        {
            CompressListDinElType(&l);
        }

        else {
            break;
        }
    }
    return 0;

}