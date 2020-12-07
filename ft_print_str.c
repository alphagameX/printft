#include "ft_printf.h"

static void ft_print_padd(int end) {
    int i;

    i = 0;
    while(i < end) {
        ft_putchar(' ');
        i++;
    }
}

static void ft_check_padd(t_options p, char *str) {
    if(p.field_size < 0 || p.field_size > ft_strlen(str))
        ft_print_padd(p.padd_size - ft_strlen(str));
    else
        ft_print_padd(p.padd_size - p.field_size);
    
}

void ft_print_str(t_options print, char *str)
{
    int i;
    
    i = 0;
    if(print.padd_size == 0)
    {
        while(str[i] && i < print.field_size)
            ft_putchar(str[i++]);
        return;
    }
    if(print.reverse_padd == false)
        ft_check_padd(print, str);
    while(str[i] && (print.field_size != -1 ? i < print.field_size : 1))
        ft_putchar(str[i++]);
    if(print.reverse_padd == true)
        ft_check_padd(print, str);
}
