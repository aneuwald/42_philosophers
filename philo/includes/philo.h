/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:48:04 by acanterg          #+#    #+#             */
/*   Updated: 2021/12/22 19:43:14 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "lib.h"
# include "const.h"
# include "struct.h"
# include "functions.h"

void			ft_quit(char *str);
void			clean(t_obj *obj);
void			init_obj(t_obj *obj, int argc, char **argv);
unsigned int	current_time_ms(void);
unsigned int	get_time_now(t_obj *obj);
void			create_threads(t_obj *obj);
void			print_message(t_obj *obj, int philo_id, char *type_msg);
void			go_sleep(t_philo *philo);
void			go_eat(t_philo *philo);
void			valid_args(int argc, char **argv);
bool			check_done_eating(t_philo *philo);
bool			check_death(t_philo *philo);
bool			all_already_ate(t_obj *obj);
void			sleep_hack(t_obj *obj, int duration, t_philo *philo);

#endif
