#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<Windows.h>
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct{
    int day;
    int month;
    int year;
}Date;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Date dob;
    char address[MAX_ADDRESS_LENGTH];
    
} Student;

// Function prototypes
void add_student();
void print_students();
void save_students();
void load_students();

void menu(){
    
}


int main(){

    Student *students = (Student *) malloc();
    return 0;
}
