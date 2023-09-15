#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct queue{
    int front;
    int rear;
    int data[MAX];
}typedef QUEUE;

void enqueue(QUEUE *q){
    int ele;
    if(q->rear == MAX -1){
        printf("QUEUE OVERFLOW!!\n");
        return;
    }
    printf("Enter the Element:");
    scanf("%d", &ele);
    if(q->front == -1 && q->rear == -1){
        q->front++;
    }
    q->data[++q->rear] = ele;
    printf("%d was inserted at the queue position, %d.\n", q->data[q->rear], q->rear);
}

void dequeue(QUEUE *q){
    if(q->front == -1 && q->rear == -1){
        printf("QUEUE UNDERFLOW!!\n");
        return;
    }
    printf("%d was removed from the position, %d\n", q->data[q->front], q->front);
    q->front++;
}

void display(QUEUE q){
    if(q.front == -1 && q.rear == -1){
        printf("Queue Underflow!!\n");
        return;
    }
    for(int i = q.front; i <= q.rear; i++){
        printf("[%d] %d  ", i, q.data[i]);
    }
    printf("\n");
}

void menu(){
    system("cls");
    printf("      +---------------------+\n");
    printf("      |  QUEUE OPERATIONS   |\n");
    printf("      +---------------------+\n");
    printf("      |   1. Enqueue.       |\n");
    printf("      |   2. Dequeue.       |\n");
    printf("      |   3. Display Queue. |\n");
    printf("      |   4. Exit.          |\n");
    printf("      +---------------------+\n");
    printf("Enter your Choice:");
}

int main(){
    QUEUE q;
    q.front = -1;
    q.rear = -1;
    int choice;
    while (1){
        menu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                enqueue(&q);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default: printf("Invalid Choice!!\n");
        }
        getchar();
        printf("Press Any Key:");
        getchar();
    }
    


    return 0;
}