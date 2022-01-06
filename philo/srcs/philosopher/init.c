/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:11:16 by acanterg          #+#    #+#             */
/*   Updated: 2021/12/22 20:04:31 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_obj *obj)
{
	int	i;

	i = -1;
	while (++i < obj->philos_count)
	{
		obj->philos[i].id = i;
		obj->philos[i].meals_count = 0;
		obj->philos[i].done_eating = false;
		obj->philos[i].eating = false;
		obj->philos[i].left_fork = i;
		obj->philos[i].right_fork = (i + 1) % obj->philos_count;
		obj->philos[i].fork = false;
		obj->philos[i].obj_ref = obj;
	}
}

void	init_mutex(t_obj *obj)
{
	int	i;

	i = -1;
	while (++i < obj->philos_count)
		pthread_mutex_init(&obj->philos[i].m_fork, NULL);
	pthread_mutex_init(&obj->m_printing, NULL);
	pthread_mutex_init(&obj->m_meals, NULL);
	pthread_mutex_init(&obj->m_someone_dieded, NULL);
}

void	init_args(t_obj *obj, int argc, char **argv)
{
	obj->philos_count = ft_atoi(argv[1]);
	obj->time_to_die = ft_atoi(argv[2]);
	obj->time_to_eat = ft_atoi(argv[3]);
	obj->time_to_sleep = ft_atoi(argv[4]);
	obj->someone_dieded = 0;
	obj->must_eat_count = -1;
	if (argc == 6)
		obj->must_eat_count = ft_atoi(argv[5]);
	obj->philos = malloc(sizeof(t_philo) * obj->philos_count);
	if (!obj->philos)
		ft_quit("Philos couldn't initializate properly!");
}

void	init_obj(t_obj *obj, int argc, char **argv)
{
	valid_args(argc, argv);
	init_args(obj, argc, argv);
	init_philos(obj);
	init_mutex(obj);
}
