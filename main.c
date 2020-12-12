#include "ft_printf.h"

int main(void) {

    int a = 10;
    ft_printf("%*x\n",5, 8);
    printf("%*x\n", 5, 8);

    return (0);
}