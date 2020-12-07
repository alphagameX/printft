#include "ft_printf.h"

int main(void) {

    int a = ft_printf("%7d",-14);
    printf("\n");
    int b = printf("%7d",-14);
    printf("\n");
    printf("%d\n",a);
    printf("%d\n",b);

    return (0);
}