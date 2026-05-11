#include "../drivers/vga.h"
#include "../drivers/keyboard.h"

#define BUFFER 1024

int x = 10
int y = 1
int tmp = 0;

int jumping_hight = 2;

void draw_world(char[BUFFER] wrld) {
    if (strcmp(wrld, "1") {
        while (tmp > 0) {
            tmp = 20;
            printc_at("#", tmp, 12);
            tmp--;
        }
    }
}

void x_axis() {
    vga_clear();
    while (x > 0) {
        printc("\n");
    }
}

void z_axis() {
    vga_clear();
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
                  if (strcmp(str, "d") == 0) {
                      printc("walking");
                  }

                  if (strcmp(str, "a") == 0) {
                      printc("jumping");
                  }

                  if (strcmp(str, " ") == 0) {
                      x = x - jumping_hight;
                      x_axis;
                      x = x - jumping_hight - 1;
                      x_axis;
                      x = x - jumping_hight - 1;
                      x_axis;
                  }
              }
          }
    }
    else {
        __asm__ volatile("hlt");
    }
}
