#include "ft_printf.h"

int main(void) {


    int a = ft_printf("%%\n", 0);
    int b = printf("%%\n", 0);

    printf("%d\n%d\n", a, b);

    return (0);
}