/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:19:24 by thibault          #+#    #+#             */
/*   Updated: 2025/03/02 20:18:38 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <ft_printf.h>
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
}	t_philo;

typedef struct s_table
{
	int				nb_of_philo;
	pthread_mutex_t	*forks;
}	t_table;

/************ UTILS ************/
int		check_number(int ac, char **av);
int		positive_num(int ac, char **av);
long	ft_atoi(const char *s);


#endif