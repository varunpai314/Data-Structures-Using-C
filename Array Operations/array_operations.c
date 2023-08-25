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

void create_array(){

}

void insert_element(){

}

void delete_element(){

}

void display_array(){

}

int main(void){
    int array[0xff];
    return 0;
}