#include "../drivers/vga.h"

void fastfetch() {
    vga_init();
    vga_set_color(VGA_COLOR_GREEN, VGA_COLOR_BLACK);
    printc("######### #########\n");
    printc("######### #########\n");
    printc("######### #########\n");
    printc("####     #     ####\n");
    printc("####     #     ####\n");
    printc("####     #     ####\n");
    printc("####     #     ####\n");
    printc("######### #########\n");
    printc("######### #########\n");
    printc("######### #########\n");
}
