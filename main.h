#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>
int print_digit(va_list parm);
int print_string(va_list parm);
int _printf(const char *format, ...);
/**
 * struct operation - the struct of the printf
 * @specf: the specifier that will in printf
 * @ptr_f: pointer to the functions
 */
typedef struct operation
{
	char specf;
	int (*ptr_f)();
} opp;
#endif
