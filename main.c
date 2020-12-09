#include "ft_printf.h"

int main(void) {


    int a = ft_printf("%0*i\n",-7, -54);
    int b = printf("%0*i\n",-7, -54);

    printf("%d\n%d\n", a, b);

    return (0);
}