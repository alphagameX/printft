#include "ft_printf.h"

static char *revert_hex(char *str, int len)
{
    char *buf;
    int i; 

    if(!(buf = (char *)malloc(sizeof(char) * 20)))
        return (ft_malloc_zero());
    i = 0;
    while(len >= 0)
        buf[i++] = str[len--];
    return (buf);
}

char *ft_get_hex(char type, unsigned long nb)
{
    char *base;
    char buf[20];
    int pos;

    if(type == 'x' || type == 'p')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    pos = 0;
    if(nb == 0)
        return (ft_malloc_zero());
    while(nb > 0)
    {
        buf[pos] =  base[nb % 16] ;
        pos++;
        nb /= 16;
    }
    buf[pos] = '\0';
    return (revert_hex(buf, pos - 1));
}

int ft_addr_zero(t_options p) {
    int count;

    count = 0;
    if(!p.reverse_padd)
        count += ft_print_padd(p.padd_size - 2, ' ');
    ft_putstr("0x");
    if(p.reverse_padd)
        count += ft_print_padd(p.padd_size - 2, ' ');
    return (count + 2);
}

int on_sen_fout(t_options p, char *addr) {
    int count;

    count = 0;
    ft_putstr("0x");
    count += ft_print_padd(p.field_size - ft_strlen(addr), '0');
    count += ft_putstr_r(addr);
    return (count + 2);
}

int ft_print_addr(t_options p, unsigned long nbr)
{
    char *addr;
    int count;

    count = 0;
    if(nbr == 0 && p.field_size == 0)
        return (ft_addr_zero(p));
    addr = ft_get_hex(p.type, nbr);

    if(p.reverse_padd)
        count += on_sen_fout(p, addr);
    count += ft_print_padd(p.padd_size - (ft_strlen(addr) + 2), ' '); 
    if(!p.reverse_padd)
        count += on_sen_fout(p, addr);    

    return (count);
}