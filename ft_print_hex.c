#include "ft_printf.h"

static char *revert_hex(char *str, int len)
{
    char *buf;
    int i; 

    if(!(buf = (char *)malloc(sizeof(char) * 20)))
        return ("0");
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

    if(type == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    pos = 0;
    if(nb == 0)
        return ("0");
    while(nb > 0)
    {
        buf[pos] =  base[nb % 16] ;
        pos++;
        nb /= 16;
    }
    buf[pos] = '\0';
    return (revert_hex(buf, pos - 1));
}
