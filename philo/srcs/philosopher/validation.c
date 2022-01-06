/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:00:20 by acanterg          #+#    #+#             */
/*   Updated: 2021/12/22 16:06:20 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_limits(char *number_str)
{
	int	len;

	len = ft_strlen(number_str);
	if (len > LEN_INT_MAX)
		ft_quit("Some argument is too big for an unsigned int 1!");
	if (len == LEN_INT_MAX && ft_strcmp(LIMIT_INT_MAX, number_str) < 0)
		ft_quit("Some argument is too big for an unsigned int 2!");
	while (*number_str)
		if (*(number_str++) != '0')
			return ;
	ft_quit("All arguments should be positive!");
}

void	check_number(char *number_str)
{
	char	*original;

	original = number_str;
	while (*number_str)
	{
		if (*number_str < '0' || *number_str > '9')
			ft_quit("Arguments should contain only numbers!");
		number_str++;
	}
	check_limits(original);
}

void	valid_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		ft_quit("Number of arguments is not correct");
	i = 0;
	while (++i < argc)
		check_number(argv[i]);
}
