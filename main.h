#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>
int print_string(char *str);
int _printf(const char *format, ...);
int functions(char spec, va_list parm);
#endif
