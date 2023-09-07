/*Hello, World. This is a menu-driven program in C language to demonstrate the various operations we can perform on an array (collection of similar [of the same data type] elements).
  Various array operations are:
  1. Creation of an Array.
  2. Insertion of an element at a specific position in the Array.
  3. Deletion of an element at a specific position of the Array.
  4. Displaying the content of the Array created.
*/

#include<stdio.h>
#include<stdlib.h>/*Included as it contains the definition for the exit(0) function used in the program*/
#define SIZE 0xf/*Just the hexadecimal form of the value 255; Be aware that this is static allocation, things will be different in dynamic allocation.*/
/*Thought of declaring the array globally, but its not a good practice it seems;
We can't keep track of what changes the variable undergoes, as all the functions can acces it/them*/

void create(int array[], int n){
    printf("Enter the array Elements:\n");
    for(int i=0; i < n; i++){
        scanf("%d", &array[i]);
    }
    printf("Array created successfully!\n");
}

void insert(int array[], int *n, int item, int pos){
    if(pos < 0 || pos > *n){
        printf("Invalid position!\n");
        return;
    }
    for(int i=*n-1; i>=pos ; i--){
        array[i+1] = array[i];
    }array[pos] = item;
    (*n)++;
    printf("%d was inserted at the postion %d.\n", array[pos], pos);
}

void delete(int array[], int *n, int pos){
    if(pos < 0 || pos > *n){
        printf("Invalid position!\n");
        return;
    }
    int del = array[pos];
    for(int i=pos; i<*n; i++){
        array[i] = array[i+1];
    }
    (*n)--;
    printf("%d was deleted from the position %d successfully!\n", del, pos);
}

void display(int array[], int n){
    if(n == 0){
        printf("Empty Array!\n");
        return;
    }
    printf("Array Elements:\n");
    for(int i=0; i<n; i++){
        printf("| %d ", array[i]);
    }printf("|\n");
}

void menu(){
    printf("+--------------------------+\n");
    printf("|     ARRAY OPERATIONS     |\n");
    printf("|--------------------------|\n");
    printf("|   1. Create Array.       |\n");
    printf("|   2. Insert an Element   |\n");
    printf("|   3. Delete an Element   |\n");
    printf("|   4. Display the Array   |\n");
    printf("|   5. Exit                |\n");
    printf("+--------------------------+\n");
    printf("Please enter your choice:   \n");
}

int main(){
    int array[SIZE], n;
    int item, pos;
    int choice;
    n = 0;
    while(1){
        system("cls");
        menu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the array size: ");
                scanf("%d", &n);
                if (n <= 0 || n > SIZE) {
                    printf("Invalid size. Please enter a size between 1 and %d.\n", SIZE);
                    break;
                }
                create(array, n);
                break;
            case 2:
                if (n == SIZE) {
                    printf("Array full. Cannot insert.\n");
                    break;
                }
                printf("Enter the value and it likely position:\n");
                scanf("%d %d", &item, &pos);
                insert(array, &n, item, pos);
                break;
            case 3:
                if (n == 0) {
                    printf("Empty array. Cannot delete.\n");
                    break;
                }
                printf("Enter the postion of the element to be deleted:\n");
                scanf("%d", &pos);
                delete(array, &n, pos);
                break;
            case 4:
                display(array, n);
                break;
            case 5:
                system("cls");
                printf("Byeee!\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
        getchar();
        printf("Press any key: ");
        getchar();
    }
    return 0;
}