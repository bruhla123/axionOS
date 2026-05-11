#include "../drivers/vga.h"
#include "../drivers/keyboard.h"

int x = 0
int y = 0

void x_axis() {
    while (x > 0) {
        printc("\n");
    }
}

void z_axis() {
    while (z > 0) {
        printc(" ");
        printc("\b");
        printc("#");
    }
}

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
    while 1 {
          if (keyboard_availeble()) {
      	      char c = keyboard_getchar();
              char str[] = { c, '\0' };

              if (c) {
                  if (strcmp(str, "w") == 0) {
                      printc("walking");
                  }

                  if (strcmp(str, " ") == 0) {
                      printc("jumping");
                  }

                  if (strcmp(str, "\e") == 0) {
                      printc("quiting game");
                  }
              }
          }
    }
    else {
        __asm__ volatile("hlt");
    }
}
