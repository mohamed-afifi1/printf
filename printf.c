#include "main.h"

/**
* print_digit - to print digit
* @num: intger number.
* Return: print number and return number of digits.
*/
int print_digit(int num)
{
	int count = 0;

	if (num < 0)
	{
		putchar('-');
		count++;
		num = -num;
	}
	if (num == 0)
	{
		putchar('0');
		return (1);
	}
	while (num > 0)
	{
		putchar('0' + num % 10);
		num = num / 10;
		count++;
	}
	return (count);
}

/**
* print_string - to print string
* @str: string.
* Return: print string and return number of letters.
*/
int print_string(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		count += write(1, *str, 1);
		str++;
	}
	return (count);
}

/**
* functions - decide which function
* @spec: specifier.
* @parm: parameter.
* Return: which function will use.
*/
int functions(char spec, va_list parm)
{
	int count = 0;

	if (spec == 'c')
	{
		count += write(1, va_arg(parm, int), 1);
	}
	else if (spec == 's')
	count += print_string(va_arg(parm, char*));
	else if (spec == '%')
	count += write(1, spec, 1);
	else if (spec == 'd' || spec == 'i')
	count += print_digit(va_arg(parm, int));
	else if (spec == 'b')
	count += print_binary(va_arg(parm, unsigned int));

	return (count);

}

/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/

int _printf(const char *format, ...)
{
	va_list parm;
	int count = 0;


	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(parm, format);
	while (*format != '\0')
	{
		if (*format == '%')
		count += functions(*(format++), parm);
		else
		{
			count += write(1, *format, 1);
		}
	}
	va_end(parm);
	return (count);
}
