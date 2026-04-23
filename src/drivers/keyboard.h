#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>
#include <stdbool.h>

#define KEYBOARD_BUFFER_SIZE 256

void keyboard_init();
void keyboard_handler();

bool keyboard_line_ready();
char* keyboard_get_line();

#endif