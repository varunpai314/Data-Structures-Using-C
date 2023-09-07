/*Hello, Varun Here. So, this is a menu-driven program to show the  of stack operation:
1. Push an Element
2.Pop an element
3.Display Stack ELements.
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack 
{
    int top;
    int data[MAX];
} typedef STACK;

void push(STACK *s, int ele){
    s->data[++s->top] = ele;
    printf("%d, pushed to the Stack position %d\n", s->data[s->top], s->top);
}

void pop(STACK *s){
    printf("%d at the position %d was popped from the stack.\n",s->data[s->top], s->top);
    s->data[s->top] = INT_MIN;
    s->top--;
}

void display(STACK s){
    if(s.top==-1){
        printf("Array is Empty! Push a few elements to the Array.\n");
    }else{
        printf("  +-----+\n");
        for(int i=s.top; i >= 0; i--){
            printf("  | %-3d | \n  +-----+\n", s.data[i]);
        }
    }
}

void menu(){
    printf("-----STACK OPERATIONS-----\n");
    printf("  1. Push an Element.\n  2. Pop an Element.\n  3. Display the Stack.\n  4. Exit.\n");
    printf("Enter your choice:  ");
}

int main(void){
    STACK s;
    s.top = -1;
    int choice, ele;
    while(1){
        system("cls");
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (s.top==MAX - 1){
                printf("Stack Overflow!\n");
            }else{
                printf("Enter the Element:  ");
                scanf("%d", &ele);
                push(&s, ele);
            }
            break;
        case 2:
            if(s.top==-1)
                printf("Stack Underflow!\n");
            else{
                pop(&s);
            }
            break;
        case 3:
            display(s);
            break;
        case 4:
            printf("Bye! Hope you had fun...");
            exit(0);
        default:
            printf("Invalid choice!");
        }
        getchar();
        printf("\nPress any Key: ");
        getchar();
    }

    return 0;
}