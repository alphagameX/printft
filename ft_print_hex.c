#include "ft_printf.h"

void ft_print_hex(t_options print, unsigned long nb)
{
    (void)print;
    char *base;
    char buf[20];
    int pos;

    if(print.type == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    pos = 0;
    if(nb == 0)
    {
        ft_putchar('0');
        return;
    }
    while(nb > 0)
    {
        buf[pos] =  base[nb % 16] ;
        pos++;
        nb /= 16;
    }
    buf[pos] = '\0';
    while(pos >= 0) {
        ft_putchar(buf[pos--]);
    }
}
