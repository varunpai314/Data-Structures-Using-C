#include<stdio.h>
#include<stdlib.h>

#define MAX 5
#define ASC "      | ASCENDING PRIORITY QUEUE OPERATIONS  |\n"
#define DESC "      | DESCENDING PRIORITY QUEUE OPERATIONS |\n"

struct queue{
    int front;
    int rear;
    int data[MAX];
}typedef QUEUE;

void enqueue(QUEUE *q, char order){
    int ele;
    int pos;
    if(q->rear == MAX -1){
        printf("QUEUE OVERFLOW!!\n");
        return;
    }
    printf("Enter the Element:");
    scanf("%d", &ele);
    if(q->front == -1 && q->rear == -1){
        q->front++;
    }
    pos = q->rear++;
    while(((order=='A'||order=='a')? ele<q->data[pos] : ele>q->data[pos]) && pos >= 0){
        q->data[pos + 1] = q->data[pos--];
    }
    q->data[++pos] = ele;
    printf("%d was enqueued to the position %d.\n", q->data[pos], pos);
}

void dequeue(QUEUE *q){
    if((q->front == -1 && q->rear == -1) || q->front > q->rear){
        printf("QUEUE UNDERFLOW!!\n");
        return;
    }

    printf("%d was dequeued from the position, %d\n", q->data[q->front], q->front);
    q->front++;
}

void display(QUEUE q){
    if(q.front == -1 && q.rear == -1 || q.front > q.rear){
        printf("Queue Empty!!\n");
        return;
    }
    for(int i = q.front; i <= q.rear; i++){
        printf("  %2d", i);
    }printf("\n ");
    for(int i = q.front; i <= q.rear; i++){
        printf(" %3.0d", q.data[i]);
    }
    printf("\n");
}


void choose(){
    system("cls");
    printf("      +------------------------------+\n");
    printf("      |      PRIORITY QUEUE TYPE     |\n");
    printf("      +------------------------------+\n");
    printf("      |   A. Ascending.              |\n");
    printf("      |   B. Descending.             |\n");
    printf("      +------------------------------+\n");
    printf("Enter your Choice:");
}

void menu(char order){
    system("cls");
    printf("      +--------------------------------------+\n");
    printf(order=='A'||order=='a'?ASC:DESC);
    printf("      +--------------------------------------+\n");
    printf("      |       1. Enqueue.                    |\n");
    printf("      |       2. Dequeue.                    |\n");
    printf("      |       3. Display Queue.              |\n");
    printf("      |       4. Exit.                       |\n");
    printf("      +--------------------------------------+\n");
    printf("Enter your Choice:");
}

int main(){
    QUEUE q;
    q.front = -1;
    q.rear = -1;
    int choice;
    char order;
    do{
        choose();
        scanf(" %c", &order);
        if(order == 'A' || order == 'a'){
            printf("Ascending Priority Queue Selected!!\n");
            break;
        }else if(order == 'B' || order == 'b'){
            printf("Descending Priority Queue Selected!!\n");
            break;
        }else{
            printf("Invalid Choice!!\n");
            getchar();
            printf("Press Any Key:");
            getchar();
        }
    }while(order != 'A' && order != 'a' && order != 'B' && order != 'b');
    getchar();
    printf("Press enter to continue:");
    getchar();
    while (1){
        menu(order);
        scanf("%d", &choice);
        switch(choice){
            case 1:
                enqueue(&q, order);
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
    getchar();
    return 0;
}
