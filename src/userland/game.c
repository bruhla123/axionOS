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
    while 1 {
          if (keyboard_availeble()) {
      	      char c = keyboard_getchar();
              char str[] = { c, '\0' };

              if (c) {
                  if (strcmp(str, "w") == 0) {
                      printc("walking");
                  }
              }
          }
    }
}
