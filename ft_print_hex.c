#include "ft_printf.h"

void ft_print_hex(t_options print, unsigned long nb)
{
    char base[16] = "0123456789abcdef";
    char buf[20];
    int pos;

    pos = 0;
    while(nb > 0)
    {
        buf[pos] = base[nb % 16];
        pos++;
        nb /= 16;
    }
    buf[pos] = '\0';
    while(pos >= 0) {
        ft_putchar(buf[pos--]);
    }
}