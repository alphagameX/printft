#include "ft_printf.h"

int main(void) {

    int a = ft_printf("%010.5d",-216);
    printf("\n");
    int b = printf("%010.5d",-216);
    printf("\n");
    printf("%d\n",a);
    printf("%d\n",b);

    return (0);
}