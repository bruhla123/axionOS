#include "../drivers/vga.h"
#include "../drivers/pic.h"
#include "../drivers/idt.h"
#include "../drivers/io.h"
#include "../drivers/gdt.h"
#include "../drivers/keyboard.h"
#include "../drivers/timer.h"
#include "../userland/fastfetch.h"

#define INPUT_BUF 128

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

void kernel_main(void)
{
    vga_init();
	timer_init();
    gdt_init();
    idt_init();
    pic_remap();
    keyboard_init();

    pic_clear_mask(0);
    pic_clear_mask(1);
    __asm__ volatile ("sti");

    printc("\n \n \n \n \n \n \n \n \n \n \n");
	printc("                             booting axoinOS");
	timer_sleep(4000);
    vga_clear();

    //color output
    vga_set_color(VGA_COLOR_GREEN, VGA_COLOR_BLACK);
    printc("[  OK  ] ");
    vga_set_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    printc("Memory subsystem initialised\n");

    vga_set_color(VGA_COLOR_YELLOW, VGA_COLOR_BLACK);
    printc("[ WARN ] ");
    vga_set_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    printc("No ACPI tables found\n");

    vga_set_color(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK);
    printc("[  ERR ] ");
    vga_set_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    printc("Example error message\n\n");

    //numbers
    vga_set_color(VGA_COLOR_CYAN, VGA_COLOR_BLACK);
    printc("Kernel base address : ");
    printc_hex(0xFFFFFFFF80000000ULL);
    printc("\n");

    //reset colors
    vga_set_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    printc("Kernel initialisation complete.\n");

	timer_sleep(1500);
	vga_clear();

    char usrinput[INPUT_BUF];
    int idx = 0;

    printc("axoin> ");

    while (1) 
    {
	    if (keyboard_available()) {
	        char c = keyboard_getchar();
            char str[] = { c, '\0' };
            printc(str);

            if (c == '\n') {
                usrinput[idx] = '\0';
                if (strcmp(usrinput, "help") == 0) {
                    printc("commands:\n");
                    printc("help\n");
                    printc("sysinfo\n");
                    printc("userland\n");
                    printc("clear\n");
                }

                if (strcmp(usrinput, "sysinfo") == 0) {
                    printc("version: axoinOS 1.0 beta\n");
                    printc("bootloader: grub multiboot2\n");
                }

                if (strcmp(usrinput, "userland") == 0) {
                    printc("fastfetch\n");
                }

                if (strcmp(usrinput, "clear") == 0) {
                    vga_clear();
                }

                if (strcmp(usrinput, "fastfetch") == 0) {
                    fastfetch();
                    vga_set_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
                }

				if (stcrmp(usrinput, "spam") == 0) {
					while 1
					{
						printf(arg);
					}
				}

                idx = 0;
                printc("axion> ");
            }
            else {
                if (idx < INPUT_BUF - 1) {
                    usrinput[idx++] = c;
                }
            }
	    }
	    else {
	         __asm__ volatile ("hlt");
	    }
    }
   
    //halt
    for (;;) {
        __asm__ volatile ("hlt");
    }
}

void _start() 
{
    kernel_main();
}
