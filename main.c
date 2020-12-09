#include "ft_printf.h"

int main(void) {


    int a = ft_printf("%s", NULL);
    int b = printf("%s", NULL);

    printf("%d\n%d\n", a, b);

    return (0);
}