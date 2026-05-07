#include "../drivers/vga.h"
#include "../drivers/keyboard.h"

int strcmp(const char *a, const char *b)
{
    while (*a && *b) {
        if (*a != *b)
            return *a - *b;
        a++;
        b++;
    }
    return *a - *b;
}

void start() {
  printc("starting game");
}
