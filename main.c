#include "ft_printf.h"

int main(void) {


    int a = ft_printf("%09s\n", "salut");
    int b = printf("%09s\n", "salut");

    printf("%d\n%d\n", a, b);

    return (0);
}