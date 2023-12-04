#include "main.h"
#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>
/**
* print_char - to print digit
* @parm: char.
* Return: print character.
*/
int print_char(va_list parm)
{
	int count = 1;
	char c = va_arg(parm, int);

	write(1, &c, 1);
	return (count);

}

/**
* print_digit - to print digit
* @parm: intger number.
* Return: print number and return number of digits.
*/
int print_digit(va_list parm)
{
	int num = va_arg(parm, int);
	int count = 0;
	char new;

	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num > 0)
	{
		new = ('0' + num % 10);
		write(1, &new, 1);
		num = num / 10;
		count++;
	}
	return (count);
}

/**
* print_string - to print string
* @parm: string.
* Return: print string and return number of letters.
*/
int print_string(va_list parm)
{
	char *str = va_arg(parm, char *);
	int count = 0, i = 0;

	while (str[i] != '\0')
	{
		count++;
		write(1, &str[i], 1);
		i++;
	}
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

opp func[] = {{"c", print_char}, {"s", print_string}, {"d", print_digit},
			{"i", print_digit}, {NULL, NULL}};

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(parm, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			*++format;
			for (int i = 0; func[i].specf != NULL; i++)
			{
				if (*format == '%')
				{	count++;
					write(1, "%", 1);
					break;
				}
				else if (func[i].specf == *format)
				{
					count += func[i].ptr_f(parm);
					break;
				}
			}

		}
		else
		{
			count++;
			write(1, format, 1);
			format++;
		}
	}
	va_end(parm);
	return (count);
}
