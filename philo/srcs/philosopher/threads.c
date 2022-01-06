/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:42:07 by acanterg          #+#    #+#             */
/*   Updated: 2021/12/22 19:31:33 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread_function(void *void_philo)
{
	t_philo	*philo;
	t_obj	*obj;

	philo = (t_philo *)void_philo;
	obj = philo->obj_ref;
	philo->last_eat = current_time_ms();
	while (!obj->someone_dieded)
	{
		if (check_death(philo) || all_already_ate(obj))
			break ;
		if (!philo->done_eating)
			go_eat(philo);
		if (philo->eating)
			go_sleep(philo);
	}
	return (NULL);
}

void	create_threads(t_obj *obj)
{
	int	i;

	i = -1;
	obj->start = current_time_ms();
	while (++i < obj->philos_count)
		pthread_create(&obj->philos[i].tid, NULL,
			philo_thread_function, &obj->philos[i]);
	i = -1;
	while (++i < obj->philos_count)
		pthread_join(obj->philos[i].tid, NULL);
}
