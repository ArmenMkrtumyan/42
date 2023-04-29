/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:09:18 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/04/29 17:38:35 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char * word)
{
	int	i;
	int	len;

	i = 0;
	len = strlen(word);
	while (i < len)
	{
		ft_putchar_fd(word[i], 1);
		i++;
	}
	return (strlen(word));
}

int	switch_case(char letter, void *argument)
{
	if (letter == 's')
		return(print_string((char *)argument));
	else if (letter == 'p')
		return (print_pointer(argument));
	else if (letter == 'd' || letter == 'i')
		return(print_number((int) argument));
	else if (letter == 'c')
		return(print_char((char) argument));
	else if (letter == 'u')
	{
		if (argument == 0)
		{
			ft_putnbr_fd(0, 1);
			return (1);
		}
		return (print_unsigned(((unsigned int) argument)));
	}
	else if (letter == 'x')
		return (print_hexadecimal((unsigned int) argument, 0));
	else if (letter == 'X')
		return (print_hexadecimal((unsigned int) argument, 1));
	else if (letter == '%')
		return(print_char('%'));
	return (0);
}

int	ft_printf (const char *sentence, ...)
{
  va_list	args;
  int		i;
  int		full_length;
  int		len;
  int		count;

  i = -1;
  full_length = 0;
  len = ft_strlen(sentence);
  va_start (args, sentence);/* Save arguments in list. */
  while (++i < len)
  {
  	if ((sentence[i] == '%') && (len != i))
	{
		full_length += switch_case(sentence[i+1], va_arg(args, void *));
		i++;
	}
	else
	{
		ft_putchar_fd(sentence[i], 1);
		full_length ++;
	}
  }

  va_end (args);/* Stop traversal. */
  return full_length;
}


int main()
{

  //int number = 429496295;
  char * name = "ARmen";
  char * add = "address";
  int number = 8;

  printf("CORRECT Length: %d\n", printf("%s = %p, you did this %d times\n", add, name, number));
  printf("MY Length: %d\n", ft_printf("%s = %p, you did this %d times\n", add, name, number));
  //printf("Length: %d\n", ft_printf("address = %x\n", name));



  return 0;

}
