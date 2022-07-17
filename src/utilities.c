/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:46:35 by cjackows          #+#    #+#             */
/*   Updated: 2022/07/14 13:33:40 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_write(char c)
{
	return(write(1, &c, 1));
}

int	string(char *str)
{
	int	i;
	i = 0;

	if (!str)
		return (write(1, "(null)", 6));
	while(str[i])
		write(1, &str[i++], 1);
	return(i);
}

int	integer(int	long nb)
{
	int	converter;
	static int	length;
	static	int	minus;

	length = 0;
	minus = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		integer(nb);
		minus++;
	}
	else if (nb != 0)
	{
		integer(nb / 10);
		length++;
		converter = nb % 10 + '0';
		write(1, &converter, 1);
	}
	return (length + minus);
}

// static void	ft_convert(unsigned long x)
// {
// 	if (x <= 9)
// 		ft_write(x + 48);
// 	else if (x >= 10)
// 		ft_write(x + 87);
// }

// static int	ft_p_hex(unsigned long x)
// {
// 	int	i;

// 	i = 1;
// 	if (x >= 16)
// 		ft_p_hex(x / 16);
// 	ft_convert(x % 16);
// 	while (x >= 16)
// 	{
// 		x = x / 16;
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_pointer(void *p)
// {
// 	unsigned long	address;

// 	address = (unsigned long)p;
// 	write(1, "0x", 2);
// 	return (2 + ft_p_hex(address));
// }
