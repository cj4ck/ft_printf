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
