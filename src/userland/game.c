#include "\src\drivers\vga.h"
#include "\src\drivers\keyboard.h"

void main(void) 
{
vga_init();
keyboard_init();

printc("starting game");
}