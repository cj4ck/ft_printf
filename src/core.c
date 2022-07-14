/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:52:01 by cjackows          #+#    #+#             */
/*   Updated: 2022/07/14 13:52:18 by cjackows         ###   ########.fr       */
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
	// if (format_specifier == 's')
	// 	par_index += string(va_arg(args, char *));
	// if (*p == 's')
	// 	// return (ft_str(va_arg(args, char *)));
	// if (*p == 'd' || *p == 'i')
	// 	// return (ft_decint(va_arg(args, int)));
	// if (*p == 'u')
	// 	// return (ft_unsigned(va_arg(args, unsigned int)));
	// if (*p == 'p')
	// 	// return (ft_pointer(va_arg(args, void *)));
	// if (*p == 'x')
	// 	// return (ft_hex(va_arg(args, unsigned int), 'x'));
	// if (*p == 'X')
	// 	// return (ft_hex(va_arg(args, unsigned int), 'X'));
	if (format_specifier == '%')
		par_index += write(1, &format_specifier, 1);
	return (par_index);
}

int ft_printf(char *str, ...)
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
			str_len += format_check(args, str[str_index + 1]);
		else
			str_len += write(1, &str[str_index], 1);
	str_index++;
	}
	va_end(args);
	return (str_len);
}

// int main()	
// {
// char	c = '!';
// char	s[] = "world!";
// char	n[] = "\0";

// /**
//  * @brief Custom printf tester
//  * 
//  */
// }