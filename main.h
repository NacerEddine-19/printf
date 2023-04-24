#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format
 * @fn: The function associated
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format
 * @fm_t: The function associated
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[]);

/* FUNCTIONS */

/* Functions to print characters and strings */
int print_char(va_list types, char buffer[]);
int print_string(va_list types, char buffer[]);
int print_percent(va_list types, char buffer[]);

/* Functions to print numbers */
int print_int(va_list types, char buffer[]);

/* Function to handle width */
int handle_write_char(char c, char buffer[]);
int write_number(int is_positive, int ind, char buffer[]);
int write_num(int ind, char bff[], char padd, char extra_c);

/* UTIL */
long int convert_size_number(long int num, int size);

#endif /* MAIN_H */
