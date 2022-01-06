/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:28:30 by acanterg          #+#    #+#             */
/*   Updated: 2021/11/08 18:01:44 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putnbr(int n)
{
	uint64_t	holder;

	holder = n;
	if (holder >= 10)
	{
		ft_putnbr(holder / 10);
		ft_putnbr(holder % 10);
	}
	else
		ft_putchar(holder + '0');
}
