#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

# define false  0
# define true  1
typedef int bool;

typedef struct s_options {
    bool reverse_padd;
    bool get_sign;
    char padd_char;
    int field_size;
    int padd_size;
    char type;
} t_options;

int ft_printf(const char *, ...);
int ft_parsing(va_list *args, char *s);
void ft_init(t_options *print);
void ft_get_flag(char *str, t_options *print, int *main_loop, va_list *args);
int is_type(char t);
void digit_getter(char *str, int *size, int *main_loop, va_list *args);
void ft_print_flag(t_options print, va_list *args, int *count);
int ft_print_str(t_options print, char *str);
int ft_print_number(t_options print, long long nbr);
int ft_print_char(t_options print, char c);
char *ft_itoa_max(long long n);
char *ft_get_hex(char type, unsigned long nb);
char *ft_malloc_zero(void);


#endif