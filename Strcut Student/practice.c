#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH];
    char *ptr = str;

    printf("Enter a string: ");
    fgets(ptr, MAX_LENGTH, stdin);
    FILE *fp = fopen("hell.txt", "w");
    fprintf(fp, "%s", ptr);
    printf("You entered: %s", ptr);

    return 0;
}
