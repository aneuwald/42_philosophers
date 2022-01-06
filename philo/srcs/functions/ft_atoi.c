/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 00:46:01 by acanterg          #+#    #+#             */
/*   Updated: 2021/11/08 18:01:28 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int				mult;
	unsigned int	nbr;

	mult = 1;
	nbr = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		mult = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (nbr > (nbr * 10) + (*str - 48))
		{
			if (mult == 1)
				return (-1);
			return (0);
		}
		nbr = (nbr * 10) + (*str - 48);
		str++;
	}
	return ((int)nbr * mult);
}
