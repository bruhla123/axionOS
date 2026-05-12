#include "../drivers/vga.h"
#include "../drivers/keyboard.h"
#include "../drivers/timer.h"

#define BUFFER 1024

int x = 11;
int y = 1;
int tmp = 0;

int jumping_hight = 2;

//block variables
int block1_x;
int block1_y;
int block2_x;
int block2_y;

int strcmp2(const char *a, const char *b)
{
    while (*a && *b) {
        if (*a != *b)
            return *a - *b;
        a++;
        b++;
    }
    return *a - *b;
}

void draw_world(char[BUFFER] wrld) {
    vga_clear();
    if (strcmp(wrld, "1") {
        tmp = 60;
        while (tmp > 0) {
            printc_at("#", tmp, 12);
            tmp--;
        }
    }
}

void check_for_blocks(char* wblock) {
        if (x == block1_x - 1 && y == 15) {
            vga_clear
            x = block1_x - 1;
            draw_human();
            draw_world();
        }

        if (strcmp2(wblock, "non_jump_l") == 0) {
            if (y == block1_y - 1 && x == 11) {
                vga_clear();
                y = block1_y - 1;
                draw_human();
                draw_world();
            }
        }

        if (strcmp2(wblock, "non_jump_r") == 0) {
            if (y == block1_y - 1 && x == 11) {
                vga_clear();
                y = block1_y + 1;
                draw_human();
                draw_world();
            }
        }
}

void draw_human() {
    vga_clear();
    printc_at("#", y, x);
    printc_at("#", y, x--);
}

void start() {
  printc("starting game");
    draw_world();
    draw_human();
    while 1 {
          if (keyboard_availeble()) {
      	      char c = keyboard_getchar();
              char str[] = { c, '\0' };

              if (c) {
                  if (strcmp2(str, "d") == 0) {
                      y--;
                      draw_human();
                      draw_world();
                      check_for_blocks();
                  }

                  if (strcmp2(str, "a") == 0) {
                      y++;
                      draw_human();
                      draw_world();
                      check_for_blocks();
                  }

                  if (strcmp2(str, " ") == 0) {
                      x--;
                      draw_human();
                      draw_world();
                      check_for_blocks();
                      timer_sleep(500);
                      x--;
                      draw_human();
                      draw_world();
                      check_for_blocks();
                      timer_sleep(500);
                      x++;
                      draw_human();
                      draw_world();
                      check_for_blocks();
                      timer_sleep(500);
                      x++;
                      draw_human();
                      draw_world();
                      check_for_blocks();
                  }
              }
          }
    }
    else {
        __asm__ volatile("hlt");
    }
}
