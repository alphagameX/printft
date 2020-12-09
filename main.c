#include "ft_printf.h"

int main(void) {


    int a = ft_printf("%s", "hello");
    int b = printf("%s", "hello");

    printf("%d\n%d\n", a, b);

    return (0);
}