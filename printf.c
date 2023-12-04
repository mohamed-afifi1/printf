#include "main.h"

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

	int count = 0, ex = 1;

	char new;

	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}
	while (num / ex > 9)
		ex *= 10;
	while (ex)
	{
		new = (num / ex) + '0';
		count = write(1, &new, 1);
		num %= ex;
		ex /= 10;
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
* print_raw - to print raw character after %r
* @parm: character.
* Return: print character.
*/
int print_raw(va_list parm)
{
	int count = 0;

	char c = va_arg(parm, int);

	count += write(1, "%", 1);
	count += write(1, &c, 1);
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
	int count = 0, i, j;

	opp func[] = {{'c', print_char}, {'s', print_string}, {'d', print_digit},
		{'i', print_digit}, {'r', print_raw},};

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(parm, format);
	for (i = 0; format[i] != '\0'; i++)

	{
		if (format[i] == '%')
		{
			i++;
			for (j = 0; j < 5; j++)

			{
				if (format[i] == '%' || format[i] == '\0')
				{
					count += write(1, "%", 1);
					if (format[i] == '\0')
						break;
				}
				else if (func[j].specf == format[i])
				{count += func[j].ptr_f(parm);
					break; }
				if (j == 4)
				{
					count += write(1, "%", 1);
					count += write(1, &format[i], 1);
					break;
				}
			}
		}
		else
			count += write(1, &format[i], 1); }
	va_end(parm);
	return (count); }
