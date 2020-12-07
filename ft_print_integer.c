#include "ft_printf.h"

static int ft_print_padd(int end, char c, int *count)
{
    int i;

    i = 0;
    while(i < end) {
        ft_putchar(c);
        (*count)++;
        i++;
    }
	return (*count);
}

static void ft_check_padd(t_options p, char *str, int sign, int *count)
{
    (void)str;
    ft_print_padd(p.padd_size - p.field_size - ((sign == -1) ? 1 : 0), p.padd_char, count);
}

static int ft_putstr_r(char *str) 
{
    int i;
    
    i = 0;
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    return (i);
}

int ft_print_integer(t_options print, int nbr)
{
    char *nb;
    int sign;
    int count;

    count = 0;
    if(nbr == 0 && print.field_size == 0)
        return (ft_print_padd(print.padd_size, ' ', &count));
    sign = 1;
    nb = ft_itoa(nbr);
    if(nb[0] == '-')
    {
        nb = ft_substr(nb, 1, ft_strlen(nb));
        sign *= -1; 
    }
    if(print.field_size < ft_strlen(nb))
        print.field_size = ft_strlen(nb);
    if(!print.reverse_padd)
        ft_check_padd(print, nb, sign, &count);
    if(sign == -1)
        ft_putchar('-');
    ft_print_padd(print.field_size - ft_strlen(nb), '0', &count);
    count = ft_putstr_r(nb);
    if(print.reverse_padd)
        ft_check_padd(print, nb, sign, &count);
    return (count);
}

