/* C libraries */
#include <stdio.h>

/* ADT */
#include "../headers/stack.h"

int main() {

    int input, val;
    Stack s;

    CreateEmptyStack(&s);

    while(true)
    {   
        printf("===MENU===\n");
        printf("[0] is empty\n");
        printf("[1] push\n");
        printf("[2] pop\n");

        PrintListDin(StackTab(s));
        printf("\n");
        if (IsStackEmpty(s) == false)
        {
            printf("stack info top : %d\n", StackInfoTop(s));
        }

        printf("======\n input :");
        scanf("%d", &input);

        if (input == 0)
        {
            if (IsStackEmpty(s))
            {
                printf("stack is empty\n");
            }

            else {
                printf("stack isn't empty\n");
            }
        }

        else if (input == 1)
        {
            scanf("%d", &val);
            PushStack(&s, val);
        }

        else if (input == 2)
        {
            PopStack(&s, &val);
            printf("popped element : %d\n", val);
        }

        else {
            break;
        }
    }
    return 0;
}