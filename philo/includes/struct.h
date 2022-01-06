/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:48:04 by acanterg          #+#    #+#             */
/*   Updated: 2021/12/22 16:10:38 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

struct	s_obj;

typedef struct s_philo
{
	int				id;
	pthread_t		tid;
	int				left_fork;
	int				right_fork;
	unsigned int	last_eat;
	int				meals_count;
	bool			eating;
	bool			done_eating;
	struct s_obj	*obj_ref;
	pthread_mutex_t	m_fork;
	bool			fork;
}	t_philo;

typedef struct s_obj
{
	int				philos_count;
	t_philo			*philos;
	unsigned int	start;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				must_eat_count;
	int				already_eat;
	bool			someone_dieded;
	pthread_mutex_t	m_someone_dieded;
	pthread_mutex_t	m_meals;
	pthread_mutex_t	m_printing;
}	t_obj;

#endif
