/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:52:01 by cjackows          #+#    #+#             */
/*   Updated: 2022/07/14 15:38:56 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_check(va_list args, const char format_specifier)
{
	char c;
	long int	num;

	if (format_specifier == 'c')
	{
		c = va_arg(args, int);
		return (write(1, &c, 1));
	}
	if (format_specifier == 's')
		return (string(va_arg(args, char *)));
	// if (format_specifier == 'p')
	// 	// return (ft_pointer(va_arg(args, void *)));
	if (format_specifier == 'd' || format_specifier == 'i')
	{
		num = va_arg(args, int);
		if (num == 0)
			return (write(1, "0", 1));
		else
			return (integer(num));
	}
	// if (*p == 'u')
	// 	// return (ft_unsigned(va_arg(args, unsigned int)));
	// if (*p == 'x')
	// 	// return (ft_hex(va_arg(args, unsigned int), 'x'));
	// if (*p == 'X')
	// 	// return (ft_hex(va_arg(args, unsigned int), 'X'));
	if (format_specifier == '%')
		return(write(1, &format_specifier, 1));
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int str_index;
	int	str_len;
	str_len = 0;
	str_index = 0;

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
