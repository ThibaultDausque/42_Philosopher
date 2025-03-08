/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:27:30 by tdausque          #+#    #+#             */
/*   Updated: 2025/03/08 11:28:50 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// write the 3 routine functions: eat, sleep, think
// give a t_philo * in arg to know which philo is sleeping, eating or thinking
void	ft_think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
	usleep(200000);
}

void	ft_sleep(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	usleep(philo->time_to_sleep * 1000);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);

	print_message("is eating", philo, philo->id);
	usleep(philo->time_to_eat * 1000);

	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}