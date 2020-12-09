#include "ft_printf.h"

static int ft_print_padd(int end, char c)
{
    int i;

    i = 0;
    while(i < end) {
        ft_putchar(c);
        i++;
    }
	return (i);
}

static int ft_check_padd(t_options p, char *str, int *sign)
{
    (void)str;
    int temp_sign;

    temp_sign = *sign;
    if(*sign == -1 && p.padd_char == '0')
    {
        ft_putchar('-');
        *sign *= -1;
    }
    return(ft_print_padd(p.padd_size - p.field_size - ((temp_sign == -1) ? 1 : 0), p.padd_char));
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



int ft_print_number(t_options print, long long nbr)
{
    char *nb;
    int sign;
    int count;

    count = 0;
    if(nbr == 0 && print.field_size == 0)
        return (ft_print_padd(print.padd_size, ' '));
    sign = 1;
    nb = ft_itoa(nbr);
    if(nb[0] == '-')
    {
        nb = ft_substr(nb, 1, ft_strlen(nb));
        count++;
        sign *= -1; 
    }
    if(print.field_size < ft_strlen(nb))
        print.field_size = ft_strlen(nb);
    if(!print.reverse_padd)
        count += ft_check_padd(print, nb, &sign);
    if(sign == -1)
        ft_putchar('-');
    count += ft_print_padd(print.field_size - ft_strlen(nb), '0');
    count += ft_putstr_r(nb);
    if(print.reverse_padd)
        count += ft_check_padd(print, nb, &sign);
    return (count);
}

