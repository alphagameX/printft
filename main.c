#include "ft_printf.h"

int main(void) {


    ft_printf("%-*.10s.\n",10, "salut");
    printf("%-*.10s.\n",10, "salut");

    return (0);
}