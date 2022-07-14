/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:52:01 by cjackows          #+#    #+#             */
/*   Updated: 2022/07/12 14:07:24 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_check(va_list args, const char format_specifier)
{
	char value;
	int	par_index;

	par_index = 0;
	value = va_arg(args,unsigned int);
	if (format_specifier == 'c')
		par_index += write(1, &value, 1);
	else if (format_specifier == '%')
		par_index += write(1, &format_specifier, 1);
	else if (format_specifier == 's')
	{
		par_index += string(va_arg(args, char *));
	}
	return (par_index);
}

int ft_printf(char *str, ...)
{
	va_list args;
	int str_index;
	// int	par_index;
	int	str_len;
	str_len = 0;
	str_index = 0;
	// par_index = 0;

	va_start(args, str);
	while (str[str_index])
	{
		if (str[str_index] == '%')
		{
			str_len += format_check(args, str[str_index + 1]);
			str_index++;
		}
		else
			str_len += write(1, &str[str_index], 1);
		str_index++;
	}
	va_end(args);
	return (str_len);
}

int main()	
{
char	c = '!';
char	s[] = "world!";
char	n[] = "\0";
// | %p The void * pointer argument has to be printed in hexadecimal format.
// | %d Prints a decimal (base 10) number.
// | %i Prints an integer in base 10.
// | %u Prints an unsigned decimal (base 10) number.
// | %x Prints a number in hexadecimal (base 16) lowercase format.
// | %X Prints a number in hexadecimal (base 16) uppercase format.
// | %% Prints a percent sign.

	// printf("ft_printf return value: %d\n   printf return value: %d\n", 	
	// ft_printf("Hello %%\n"),
	// printf("Hello %c\n", "test")	
	// ft_printf("Hello %s\n", "Test")
	printf("Printf %s\n", s);
	ft_printf("Hello %s\n", s);
	
	printf("Printf %s\n", n);
	ft_printf("Hello %s\n", n);
}