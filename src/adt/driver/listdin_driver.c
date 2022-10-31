/* C libraries */
#include "stdio.h"

/* ADT */
#include "../headers/listdin.h"

int main() {

    // KAMUS LOKAL
    ListDin l, l2;
    int input, val, idx, cap;

    // ALGORITMA

    CreateListDin(&l, 2);

    while (true)
    {

        printf("======MENU======\n");
        printf("[0] create new list din\n");
        printf("[1] deallocate\n");
        printf("[2] last idx\n");
        printf("[3] copy list\n");
        printf("[4] count val\n");
        printf("[5] sort\n");
        printf("[6] insert first\n");
        printf("[7] insert at\n");
        printf("[8] insert last\n");
        printf("[9] delete first\n");
        printf("[10] delete at\n");
        printf("[11] delete last\n");
        printf("[12] compress\n");
        printf("current list : ");
        PrintListDin(l);
        printf("\n");
        printf("current list length : %d\n", ListDinLength(l));
        printf("current list capacity : %d\n", LISTDIN_CAP(l));
        printf("\n");
        printf("input : ");

        scanf("%d", &input);

        if (input == 0)
        {
            scanf("%d", &cap);
            DealocateListDin(&l);
            CreateListDin(&l, cap);
        }

        else if (input == 1)
        {
            DealocateListDin(&l);
        }

        else if (input == 2)
        {
            printf("last idx : %d\n", GetListDinLastIdx(l));
        }

        else if (input == 3)
        {
            CopyListDin(l, &l2);
            printf("l2 : ");
            PrintListDin(l2);
            printf("\n");
        }

        else if (input == 4)
        {
            scanf("%d", &val);
            printf("Count val : %d\n", CountListDinVal(l, val));
        }

        else if (input == 5)
        {
            scanf("%d", &input);
            SortListDin(&l, input);
        }

        else if (input == 6)
        {
            scanf("%d", &val);
            InsertFirstListDin(&l, val);
        }

        else if (input == 7)
        {
            scanf("%d %d", &val, &idx);
            InsertAtListDin(&l, val, idx);
        }

        else if (input == 8)
        {   
            scanf("%d", &val);
            InsertLastListDin(&l, val);
        }

        else if (input == 9)
        {
            DeleteFirstListDin(&l, &val);
            printf("deleted element : %d\n", val);
        }

        else if (input == 10)
        {
            scanf("%d", &idx);
            DeleteAtListDin(&l, &val, idx);
            printf("deleted element : %d\n", val);
        }

        else if (input == 11)
        {
            DeleteLastListDin(&l, &val);
            printf("deleted element : %d\n", val);
        }

        else if (input == 12)
        {
            CompressListDin(&l);
        }

        else {
            break;
        }
    }
    return 0;

}