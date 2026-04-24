#include "keyboard.h"

#define KEYBOARD_DATA_PORT 0x60

static char keyboard_buffer[KEYBOARD_BUFFER_SIZE];
static int buffer_index = 0;
static bool line_ready = false;

static const char scancode_table[128] =
{
    0,27,'1','2','3','4','5','6','7','8',
    '9','0','-','=', '\b',
    '\t',
    'q','w','e','r','t','y','u','i','o','p','[',']','\n',
    0,
    'a','s','d','f','g','h','j','k','l',';',
    '\'','`',
    0,
    '\\','z','x','c','v','b','n','m',',','.','/',
    0,'*',0,' ',
};

extern unsigned char inb(unsigned short port);

/* This must exist in your IRQ system */
extern void irq_install_handler(int irq, void (*handler)(void));

void keyboard_handler()
{
    unsigned char scancode = inb(KEYBOARD_DATA_PORT);

    if (scancode & 0x80)
        return;

    char c = scancode_table[scancode];

    if (!c)
        return;

    if (c == '\n')
    {
        keyboard_buffer[buffer_index] = '\0';
        buffer_index = 0;
        line_ready = true;
        return;
    }

    if (c == '\b')
    {
        if (buffer_index > 0)
            buffer_index--;
        return;
    }

    if (buffer_index < KEYBOARD_BUFFER_SIZE - 1)
    {
        keyboard_buffer[buffer_index++] = c;
    }
    outb(0x20, 0x20);
}

bool keyboard_line_ready()
{
    return line_ready;
}

char* keyboard_get_line()
{
    line_ready = false;
    return keyboard_buffer;
}

void keyboard_init()
{
    irq_install_handler(1, keyboard_handler);
}
