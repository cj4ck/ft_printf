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

// int	string(char *str)
// {
// 	write(1, 'c', 1);
// }

int	string(char *str)
{
	int	i;
	i = 0;

	if (!str)
		return (write(1, "(null)", 6));
	while(str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	integer(int	nb)
{
	// int	i;
	int	l;
	int	converter;
	int	length;

	l = nb;
	length = 0;
	if (l == 0)
		length = 1;
	else if (l < 0)
	{
		length++;
		l = l * -1;
	}
	while (l > 0)
	{
		length++;
		l = l / 10;
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		integer(nb / 10);
	converter = nb % 10 + '0';
	write(1, &converter,1);

	return (length);
}
