/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:19:24 by thibault          #+#    #+#             */
/*   Updated: 2025/03/02 11:35:24 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <ft_printf.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	l_fork;

}	t_philo;

/************ UTILS ************/
int		check_number(int ac, char **av);
int		positive_num(int ac, char **av);
long	ft_atoi(const char *s);


#endif