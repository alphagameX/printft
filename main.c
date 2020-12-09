#include "ft_printf.h"

int main(void) {


    int a = ft_printf("%-*.10s.\n",10, "salut");
    int b = printf("%-*.10s.\n",10, "salut");

    printf("%d\n%d\n", a, b);

    return (0);
}