/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosphers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:59:19 by acanterg          #+#    #+#             */
/*   Updated: 2021/12/22 19:43:59 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	take_fork(t_obj *obj, int fork_id)
{
	bool	taken;

	taken = false;
	pthread_mutex_lock(&obj->philos[fork_id].m_fork);
	if (!obj->philos[fork_id].fork)
	{
		obj->philos[fork_id].fork = true;
		taken = true;
	}
	pthread_mutex_unlock(&obj->philos[fork_id].m_fork);
	return (taken);
}

void	free_fork(t_obj *obj, int fork_id)
{
	pthread_mutex_lock(&obj->philos[fork_id].m_fork);
	obj->philos[fork_id].fork = false;
	pthread_mutex_unlock(&obj->philos[fork_id].m_fork);
}

void	try_take_forks(t_philo *philo)
{
	t_obj	*obj;

	obj = philo->obj_ref;
	if (take_fork(obj, philo->right_fork))
	{
		if (take_fork(obj, philo->left_fork))
			philo->eating = 1;
		else
			free_fork(obj, philo->right_fork);
	}
}

void	go_eat(t_philo *philo)
{
	try_take_forks(philo);
	if (!philo->eating)
		return ;
	print_message(philo->obj_ref, philo->id, MSG_FORK);
	print_message(philo->obj_ref, philo->id, MSG_FORK);
	philo->last_eat = current_time_ms();
	print_message(philo->obj_ref, philo->id, MSG_EAT);
	sleep_hack(philo->obj_ref, philo->obj_ref->time_to_eat, philo);
	philo->meals_count ++;
	check_done_eating(philo);
	check_death(philo);
}

void	go_sleep(t_philo *philo)
{
	print_message(philo->obj_ref, philo->id, MSG_SLEEP);
	free_fork(philo->obj_ref, philo->right_fork);
	free_fork(philo->obj_ref, philo->left_fork);
	philo->eating = 0;
	sleep_hack(philo->obj_ref, philo->obj_ref->time_to_sleep, philo);
	print_message(philo->obj_ref, philo->id, MSG_THINK);
	usleep(DELAY_AFTER_SLEEP);
}
