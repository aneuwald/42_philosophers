/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:11:29 by acanterg          #+#    #+#             */
/*   Updated: 2022/01/06 10:46:43 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_done_eating(t_philo *philo)
{
	t_obj	*obj;

	obj = philo->obj_ref;
	if (obj->must_eat_count != -1 && philo->meals_count >= obj->must_eat_count)
		philo->done_eating = true;
	return (philo->done_eating);
}

bool	check_death(t_philo *philo)
{
	t_obj	*obj;

	obj = philo->obj_ref;
	if (current_time_ms() - philo->last_eat > obj->time_to_die)
	{
		pthread_mutex_lock(&obj->m_someone_dieded);
		if (!obj->someone_dieded && !all_already_ate(obj))
		{
			print_message(obj, philo->id, MSG_DIE);
			obj->someone_dieded = true;
		}
		pthread_mutex_unlock(&obj->m_someone_dieded);
		return (true);
	}
	return (false);
}

bool	all_already_ate(t_obj *obj)
{
	int	i;

	i = -1;
	while (++i < obj->philos_count)
		if (obj->philos[i].done_eating == false)
			return (false);
	return (true);
}
