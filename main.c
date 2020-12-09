#include "ft_printf.h"

int main(void) {

    int a = 10;
    ft_printf("%020.17p\n", &a);

    return (0);
}