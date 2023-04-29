#include "ft_printf.h"

int	print_number(int number)
{
	int len;

	len = 0;
	ft_putnbr_fd(number, 1);
	while (number != 0)
	{
		number = number / 10;
		len ++;
	}
	return (len);
}

int print_unsigned(unsigned int number)
{
	static int len;

	len	= 0;
	if (number == 0)
		return (1);
	else
	{
		print_unsigned(number / 10);
		ft_putnbr_fd(number%10,1);
		len ++;
	}
	return (len);
}

char	get_char(int number, int capitalize)
{
	if (number < 10)
		return (number + '0');
	if(capitalize)
		return ('A' + number-10);
	return ('a' + number-10);
}


int print_hexadecimal(unsigned long number, int capitalize)
{
	static int summary;

	summary	= 1;
	if (number >= 16)
	{
		print_hexadecimal (number / 16, capitalize);
		ft_putchar_fd(get_char(number % 16, capitalize), 1);
		summary += 1;
	}
	else
	{
		ft_putchar_fd (get_char (number, capitalize), 1);
		return (1);
	}
	return (summary);
}

int print_pointer(void *argument)
{
	write (1, "0x", 2);
	return (2 + print_hexadecimal((unsigned long)argument, 0));
}