/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:19:24 by thibault          #+#    #+#             */
/*   Updated: 2025/03/08 11:56:39 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t *message;
}	t_philo;

typedef struct s_time
{
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
}	t_time;


typedef struct s_table
{
	int				nb_of_philo;
	pthread_mutex_t	*forks;
}	t_table;

/************ UTILS ************/
int		check_number(char **av);
int		positive_num(int ac, char **av);
long	ft_atoi(const char *s);
void	print_message(char *s, t_philo *philo, int id);

/************ ROUTINE ************/
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);

/************ PHILO ************/
void	*routine(void *arg);
void	create_thread(t_philo *philo, t_time time, int nb_of_philo);


#endif