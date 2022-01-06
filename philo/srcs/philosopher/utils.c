/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:53:33 by acanterg          #+#    #+#             */
/*   Updated: 2021/12/22 20:12:33 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	current_time_ms(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

unsigned int	get_time_now(t_obj *obj)
{
	return (current_time_ms() - obj->start);
}

void	sleep_hack(t_obj *obj, int duration, t_philo *philo)
{
	long	start;
	long	time_to_die;

	start = current_time_ms();
	time_to_die = philo->last_eat + obj->time_to_die;
	while (!obj->someone_dieded && current_time_ms() - start <= duration)
	{
		if (current_time_ms() - 10 >= time_to_die && check_death(philo))
			return ;
		usleep(50);
	}
}

void	print_message(t_obj *obj, int philo_id, char *type_msg)
{
	pthread_mutex_lock(&obj->m_printing);
	if (!obj->someone_dieded && !all_already_ate(obj))
		printf("%u %d %s\n", get_time_now(obj), philo_id + 1, type_msg);
	pthread_mutex_unlock(&obj->m_printing);
}
