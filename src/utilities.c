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
	// const char null [] = "(null)";

	i = 0;
	// if (str == NULL)
	// {
	// 	while (null[i])
	// 	{
	// 		write(1, &null[i], 1);
	// 		i++;
	// 	}	
	// }
	// else
	// {
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
