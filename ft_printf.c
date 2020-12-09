#include "ft_printf.h"

/*
-types : c s p d i u x X %
-flags :

    - : padding sur la droit
blank : start with space
  0's : set the padding caractere to zero
    + : show the sign number
 .0's : width of string
   8. : padding for string
*/

int ft_printf(const char *str, ...)
{
    va_list list;
    va_start(list, str);
    return(ft_parsing(&list, (char *)str));
}

void ft_init(t_options *print)
{
    print->get_sign = false;
    print->reverse_padd = false;
    print->padd_size = 0;
    print->field_size = -1;
    print->padd_char = ' ';
}


int is_type(char t)
{
    if(t == 'd' ||
     t == 'p' ||
     t == 'u' ||
     t == 'x' ||
     t == '%' ||
     t == 'i' ||
     t == 's' ||
     t == 'c' ||
     t == 'X')
        return (1);
    return (0);
}





