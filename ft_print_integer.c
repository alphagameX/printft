#include "ft_printf.h"

static void ft_print_padd(char type, int padd_size, int field_size, char c) {
    while(padd_size - field_size > 0)
    {
        ft_putchar(c);
        padd_size--;
    }
}

void ft_print_integer(t_options print, int nbr)
{
    char *nb;

    nb = ft_itoa(nbr);
    if(print.field_size == -1)
    {
        if(!print.reverse_padd)
            ft_print_padd(print.type, print.padd_size, ft_strlen(nb), print.padd_char);
        ft_putstr(nb);
        if(print.reverse_padd)
            ft_print_padd(print.type, print.padd_size, ft_strlen(nb), print.padd_char);
    }
    else
    {
        if(!print.reverse_padd)
            ft_print_padd(print.type, print.padd_size, print.field_size, ' ');
        ft_print_padd(print.type, print.field_size, ft_strlen(nb), '0');
        ft_putstr(nb);
        if(print.reverse_padd)
            ft_print_padd(print.type, print.padd_size, (print.field_size == 0) ? ft_strlen(nb) : print.field_size, ' ');
    }
    free(nb);
}

