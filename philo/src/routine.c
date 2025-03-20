/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:27:30 by tdausque          #+#    #+#             */
/*   Updated: 2025/03/16 14:11:57by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	if (check_death(philo->god_eyes))
		return ;
	print_message("is thinking", philo, philo->id);
	return ;
}

void	ft_sleep(t_philo *philo)
{
	if (check_death(philo->god_eyes))
		return ;
	print_message("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep, philo);
	if (check_death(philo->god_eyes))
		return ;
}

void	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_message("has taken a fork", philo, philo->id);
		pthread_mutex_lock(philo->r_fork);
		print_message("has taken a fork", philo, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_message("has taken a fork", philo, philo->id);
		pthread_mutex_lock(philo->l_fork);
		print_message("has taken a fork", philo, philo->id);
	}
	print_message("is eating", philo, philo->id);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time();
	philo->nb_of_meal++;
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo->time_to_eat, philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
