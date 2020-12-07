#include "ft_printf.h"

int main(void) {

    int a = ft_printf("%.5d",2);
    printf("\n");
    int b = printf("%.5d",2);
    printf("\n");
    printf("%d\n",a);
    printf("%d\n",b);

    return (0);
}