/*Hello. This program here illustrates the working of the Tower of Hanoi, using 
Recursion - method of solving a computational problem where the solution depends on solutions to smaller instances of the same problem.*/

#include<stdio.h>

void transfer(int n, char s, char t, char d){
    if(n == 0){
        return;
    }
    transfer(n-1, s, d, t);
    printf("MOVE DISK %d FROM %c TO %c\n", n, s, d);
    transfer(n-1, t, s, d);
}

int main(void){
    system("cls");
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    transfer(n, 'S', 'T', 'D');
    return 0;
}