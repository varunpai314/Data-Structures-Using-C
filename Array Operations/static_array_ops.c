/*Hello, World. This is a menu-driven program in C language to demonstrate the various operations we can perform on an array.
  Various array (collection of similar [of the same data type] elements) operations are:
  1. Creation of an Array.
  2. Insertion of an element at a specific position in the Array.
  3. Deletion of an element at a specific position of the Array.
  4. Displaying the content of the Array created.
*/

#include<stdio.h>
#include<stdlib.h>/*Included as it contains the definition for the exit(0) function used in the program*/
#define SIZE 0xff/*Just the hexadecimal form of the value 255; Be aware that this is static allocation, things will be different in dynamic allocation.*/
/*Thought of declaring the array globally, but its not a good practice it seems;
We can't keep track of what changes the variable undergoes, as all the functions can acces it/them*/

void create_array(int *arr_p, int *n){
  puts("Enter the Array size: ");
  scanf("%d", *n);
}

void insert_element(int *arr_p, int *n, int ele, int pos){

}

void delete_element(int *arr_p, int *n, int pos){

}

void display_array(){

}

void menu(){
  system("cls");
  puts("-----------ARRAY OPERATIONS-----------\n");
  puts(" 1. Create an Array.\n");
  puts(" 2. Insert an Element to the Array.\n");
  puts(" 3. Delete an Element from the Array.\n");
  puts(" 4. Display the Array.\n");
  puts(" 5. Exit.\n");
  puts("Enter your Choice: \n");
}

int main(void){
  system("cls");
  int array[0xff], n = 0, ele, pos;
  puts("Hello, and welcome!");
  _sleep(2200);
  while(1){
    menu();
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1: if(n > 0){
          puts("There exists an Array of size %d. Do you want to create another Array? (y/n)\n", n);
          char ch;
          scanf("%c", ch);
          if(ch == 'n' && ch != 'y')
            break;
        }
        create_array(array, &n);
        break;
        case 2: if(n <= 0){
          puts("Create an Array first!!!\n");
        }else{
          puts("Enter the element and its position: \n\t");
          scanf("%d %d", &ele, &pos);
          insert_element(array, &n, ele, pos);
        }
        break;
        case 3: if(n <= 0){
          puts("Array is empty/ Array not created!\n");
        }
        else{
          puts("Enter the position of the Element:\n\t");
          scanf("%d", &pos);
        }
        break;
        case 4: if(n <= 0){
          puts("Create an array first!!!\n");
        }
        else{
          display_array(array);
        }
        break;
        case 5: puts("Byeee! Hope you enjoyed fiddling with Arrays...\n");
          exit(0);
        default:
          puts("Invalid Choice!!!\n");
    }
    puts("Press any key: ");
    getchar();
  }
  
  return 0;
}