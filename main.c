#include "ft_printf.h"

int main(void) {


    int a = ft_printf("%-*.*s\n",-7, -3, "yolo");
    int b = printf("%-*.*s\n",-7, -3, "yolo");

    printf("%d\n%d\n", a, b);

    return (0);
}