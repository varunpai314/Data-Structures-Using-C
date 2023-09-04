#include <conio.h>
#include <stdio.h>

int main() {
    int ch;
    while ((ch = getch()) != 27) { // 27 is the ASCII code for the ESC key
        if (ch == 0 || ch == 224) {
            switch (getch()) {
                case 72:
                    printf("Up arrow key pressed\n");
                    break;
                case 80:
                    printf("Down arrow key pressed\n");
                    break;
                case 75:
                    printf("Left arrow key pressed\n");
                    break;
                case 77:
                    printf("Right arrow key pressed\n");
                    break;
            }
        }
    }
    return 0;
}
