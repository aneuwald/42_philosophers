/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 10:34:55 by acanterg          #+#    #+#             */
/*   Updated: 2021/12/22 16:08:21 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_quit(char *str)
{
	printf("Error: %s\n", str);
	exit(1);
}

void	clean(t_obj *obj)
{
	int	i;

	i = -1;
	while (++i < obj->philos_count)
		pthread_mutex_destroy(&obj->philos[i].m_fork);
	pthread_mutex_destroy(&obj->m_printing);
	pthread_mutex_destroy(&obj->m_meals);
	pthread_mutex_destroy(&obj->m_someone_dieded);
	free(obj->philos);
}
