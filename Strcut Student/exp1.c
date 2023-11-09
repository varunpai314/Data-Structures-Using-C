#include <windows.h>

int main() {
    // Get the handle to the console window
    HWND console = GetConsoleWindow();

    // Get the device context of the console window
    HDC dc = GetDC(console);

    // Create a rectangle
    RECT rect = { 50, 50, 200, 200 };

    // Draw the rectangle
    Rectangle(dc, rect.left, rect.top, rect.right, rect.bottom);

    // Release the device context
    ReleaseDC(console, dc);

    // Force the console window to redraw itself
    InvalidateRect(console, NULL, TRUE);

    return 0;
}
//How to run the program with the visual studio developer command prompt
//cl exp1.c user32.lib gdi32.lib
