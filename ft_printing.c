#include "ft_printf.h"

static int ft_print_padd(char type, int padd_size, int field_size, char c)
{
    (void)type;
    int count;

    count = 0;
    while(padd_size - field_size > 0)
    {
        ft_putchar(c);
        padd_size--;
        count++;
    }
    return (count);
}

void ft_print_flag(t_options print, va_list *args, int *count)
{
    if(print.type == 'd' || print.type == 'i')
       *count += ft_print_number(print, va_arg(*args, int));
    else if(print.type == 'u' || print.type == 'x' || print.type == 'X')
        *count += ft_print_number(print, va_arg(*args, unsigned int));
    else if(print.type == 's')
        *count += ft_print_str(print, va_arg(*args, char *));
    else if(print.type == 'c' || print.type == '%')
        *count += ft_print_char(print, va_arg(*args, int));
    else if(print.type == 'p')
        write(1, "en cours", 8);
    //printf("type: %c, reverse_padd: %i, get_sign: %d, padd_char: %c, padd_size: %d, field_size: %d\n", print.type, print.reverse_padd, print.get_sign, print.padd_char, print.padd_size, print.field_size);
}

int ft_print_char(t_options print, char c)
{
    int count;

    count = 0;
    if(!print.reverse_padd)
        count += ft_print_padd(print.type, print.padd_size, 1, print.padd_char);
    if(print.type == '%')
        ft_putchar('%');
    else
        ft_putchar(c);
    count++;
    if(print.reverse_padd)
        count += ft_print_padd(print.type, print.padd_size, 1, ' ');
    return (count);
}


