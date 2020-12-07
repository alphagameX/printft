#include "ft_printf.h"

int main(void) {

    int a = ft_printf("this is %d a number\n",10);
    int b = printf("this is %d a number\n",10);
    printf("%d\n",a);
    printf("%d\n",b);

    return (0);
}