/*Hello, Varun Here. So, this is a menu-driven program to show the implementations of stack operation:
1. Push an Element
2.Pop an element
3.Display Stack ELements.
*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 0x7f
struct stack 
{
    int top;
    int data[SIZE];
} typedef STACK;

void push(STACK *s, int ele){
    if (s->top==SIZE - 1){
        printf("Stack Overflow!\n");
    }else{
        s->data[++s->top] = ele;
        printf("%d, pushed to the Stack position %d\n", s->data[s->top], s->top);
    }
}

void pop(STACK *s){
    char ch[3];
    if(s->top==-1){
        printf("Stack Underflow!\n");
    }else{
        printf("Are you sure? (y/n) : ");
        scanf("%s", ch);
        if(ch[0] == 'y'){
            printf("%d at the position %d was popped from the stack.\n",s->data[s->top], s->top);
            s->data[s->top] = INT_MIN;
            s->top--;
        }else{
            printf("Couldn't pop %d.\n", s->data[s->top]);
            return;
        }
    }
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
            printf("Enter the Element:  ");
            scanf("%d", &ele);
            push(&s, ele);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            display(s);
            break;
        case 4:
            printf("Bye! Hope you had fun...");
            exit(0);
        default:
            printf("Invalid choice!");
            break;
        }
        getchar();
        printf("\nPress any Key: ");
        getchar();
    }

    return 0;
}