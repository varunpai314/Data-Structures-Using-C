#include<stdio.h>

int main(){
    FILE *fp;
    fp = fopen("C:\\Users\\paiva\\OneDrive\\Documents\\GitHub\\Data-Structures-Using-C\\file handling\\file1.txt", "w");
    fprintf(fp, "Hello, World!\n");
    fclose(fp);
    return 0;
}