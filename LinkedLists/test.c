/*
 * This program demonstrates the implementation of a singly linked list in C.
 * It defines a node structure with an integer data field and a pointer to the next node.
 * The program includes functions to insert and delete nodes from the list.
 * The main function creates a linked list, inserts three nodes, deletes one node, and prints the remaining nodes.
 */
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
typedef struct node* Node;
/**
 * Inserts a new node with the given data at the end of the linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @param data The data to be inserted into the new node.
 */
void insert(Node *head, int data){
    Node temp = (Node)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    if(*head == NULL){
        *head = temp;
    }else{
        Node p = *head;
        while(p->link != NULL){
            p = p->link;
        }
        p->link = temp;
    }
}

void delete(Node *head, int data){
    if(*head == NULL){
        printf("List is empty\n");
    }else{
        Node p = *head;
        Node q = NULL;
        while(p != NULL && p->data != data){
            q = p;
            p = p->link;
        }
        if(p == NULL){
            printf("Element not found\n");
        }else if(q == NULL){
            *head = p->link;
            free(p);
        }else{
            q->link = p->link;
            free(p);
        }
    }
}

int count(Node first){
    int cnt = 0;
    Node curr = first;
    while(curr != NULL){
        cnt++;
        curr = curr->link;
    }
    return cnt;
}

Node join(Node l1, Node l2){
    if(l1 == NULL){
        return l2;
    }
    Node p = l1;
    while(p->link != NULL){
        p = p->link;
    }
    p->link = l2;
    return l1;
}

void display(Node p){
    while(p != NULL){
        printf("%d ", p->data);
        p = p->link;
    }
}

Node reverse(Node p){
    if (p == NULL){
        printf("List is empty\n");
        return NULL;
    }
    Node curr = p;
    Node prev = NULL, next = NULL;
    while(curr != NULL){
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void insert_at_pos(Node *first, int pos, int item){
    Node temp = (Node)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = NULL;
    if(pos == 0){
        temp->link = *first;
        *first = temp;
    }else{
        Node p = *first;
        int i = 0;
        while(++i < pos-1 && p != NULL){
            p = p->link;
        }
        if(p == NULL){
            printf("\nInvalid position\n");
        }else{
            temp->link = p->link;
            p->link = temp;
        }
    }
}


void delete_from_pos(Node *first, int pos){
    if(*first == NULL){
        printf("List is empty\n");
    }else{
        Node p = *first;
        Node q = NULL;
        int i = 0;
        while(++i < pos && p != NULL){
            q = p;
            p = p->link;
        }
        if(p == NULL){
            printf("Invalid position\n");
        }else if(q == NULL){
            *first = p->link;
            free(p);
        }else{
            q->link = p->link;
            free(p);
        }
    }
}


void search(Node first, int item){
    Node p = first;
    int pos = 0;
    while(p != NULL){
        if(p->data == item){
            printf("%d found at position %d\n", p->data, pos);
            return;
        }
        pos++;
        p = p->link;
    }
    printf("Element not found\n");
}



void sort(Node first){
    if(first == NULL){
        printf("List is empty\n");
    }else{
        Node p = first;
        Node smallest = p;
        Node largest = p;
        while(p != NULL){
            if(p->data < smallest->data){
                insert_before();
            }
            if(p->data > largest->data){
                largest = p;
            }
            p = p->link;
        }
    }
}


int main(){
    Node head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    printf("\nNo. of nodes: %d\n", count(head));
    delete(&head, 20);
    display(head);
    printf("\nNo. of nodes: %d\n", count(head));

    Node head2 = NULL;
    insert(&head2, 40);
    insert(&head2, 50);
    insert(&head2, 60);
    printf("\nNo. of nodes: %d\n", count(head2));
    delete(&head2, 50);
    display(head2);
    printf("\nNo. of nodes: %d\n", count(head2));
    join(head, head2);
    printf("\nNo. of nodes: %d\n", count(head));
    display(head);
    printf("\n");
    Node rev = reverse(head);
    display(rev);
    
    insert_at_pos(&rev, 2, 24);
    insert_at_pos(&rev, 0, 15);
    insert_at_pos(&rev, 7, 81);
    insert_at_pos(&rev, 9, 15);
    delete_from_pos(&rev, 5);
    printf("\n");
    display(rev);
    printf("\n");
    search(rev, 81);
    return 0;
}