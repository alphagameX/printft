#include "ft_printf.h"

static void ft_print_padd(char type, int padd_size, int field_size, char c) {
    (void)type;
    while(padd_size - field_size > 0)
    {
        ft_putchar(c);
        padd_size--;
    }
}

void ft_print_flag(t_options print, va_list *args, int *count)
{
    if(print.type == 'd' || print.type == 'i' || print.type == 'u')
       *count += ft_print_integer(print, va_arg(*args, int));
    else if(print.type == 's')
        *count += ft_print_str(print, va_arg(*args, char *));
    else if(print.type == 'c')
        ft_print_char(print, va_arg(*args, int));
    else if(print.type == 'x' || print.type == 'X')
        ft_print_hex(print, va_arg(*args, unsigned long));
    else if(print.type == 'p')
        write(1, "en cours", 8);
    //printf("type: %c, reverse_padd: %i, get_sign: %d, padd_char: %c, padd_size: %d, field_size: %d\n", print.type, print.reverse_padd, print.get_sign, print.padd_char, print.padd_size, print.field_size);
}

void ft_print_char(t_options print, char c)
{
    if(!print.reverse_padd)
        ft_print_padd(print.type, print.padd_size, 1, ' ');
    ft_putchar(c);
    if(print.reverse_padd)
        ft_print_padd(print.type, print.padd_size, 1, ' ');
}


