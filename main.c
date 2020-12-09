#include "ft_printf.h"

int main(void) {


    int a = ft_printf("%.*s\n", -3, "hello");
    int b = printf("%.*s\n", -3, "hello");

    printf("%d\n%d\n", a, b);

    return (0);
}