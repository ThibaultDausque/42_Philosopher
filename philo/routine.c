/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:27:30 by tdausque          #+#    #+#             */
/*   Updated: 2025/03/09 16:10:20 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// write the 3 routine functions: eat, sleep, think
// give a t_philo * in arg to know which philo is sleeping, eating or thinking
void	ft_think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}

void	ft_sleep(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	usleep(philo->time_to_sleep * 1000);
}

void	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_message("has taken a fork", philo, philo->id);
		usleep(500);
		pthread_mutex_lock(philo->r_fork);
		print_message("has taken a fork", philo, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_message("has taken a fork", philo, philo->id);
		usleep(500);
		pthread_mutex_lock(philo->l_fork);
		print_message("has taken a fork", philo, philo->id);
	}
	print_message("is eating", philo, philo->id);
	philo->last_meal = get_time();
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

int	ft_dead(t_philo *philo)
{
	// dead if time_to_die is reached from
	// their last meal or the start of the simulation
	int		current_time;

	current_time = get_time();
	if (current_time - philo->last_meal >= philo->time_to_die
		|| (current_time - philo->start_time >= philo->time_to_die
		&& philo->last_meal == 0))
	{
		print_message("died", philo, philo->id);
		return (1);
	}
	return (0);
}