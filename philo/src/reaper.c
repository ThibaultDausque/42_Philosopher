/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:12:16 by tdausque          #+#    #+#             */
/*   Updated: 2025/03/22 13:22:09 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	manage_death(t_god_eyes *god_eyes, int i)
{
	if (god_eyes->nb_of_philo > 1)
		print_message("died", &god_eyes->philo[i],
			god_eyes->philo[i].id);
	set_die(god_eyes);
}

void	manage_eat(t_god_eyes *god_eyes, int i)
{
	god_eyes->philo[i].finish = 1;
	god_eyes->finish_to_eat++;
	if (god_eyes->finish_to_eat == god_eyes->nb_of_philo)
		set_eat(god_eyes);
}

void	*reaper_routine(void *args)
{
	t_god_eyes	*god_eyes;
	int			i;

	god_eyes = (t_god_eyes *)args;
	while (1)
	{
		i = 0;
		while (i < god_eyes->nb_of_philo)
		{
			pthread_mutex_lock(&god_eyes->philo[i].meal_lock);
			if (get_time() - god_eyes->philo[i].last_meal
				>= god_eyes->philo[i].time_to_die)
			{
				pthread_mutex_unlock(&god_eyes->philo[i].meal_lock);
				manage_death(god_eyes, i);
				return (NULL);
			}
			else if (!god_eyes->philo[i].finish && god_eyes->philo[i].nb_of_meal
				== god_eyes->philo[i].nb_philo_must_eat && god_eyes->av[5])
				manage_eat(god_eyes, i);
			pthread_mutex_unlock(&god_eyes->philo[i].meal_lock);
			i++;
		}
		usleep(100);
	}
}

void	init_god(t_philo *philo, t_god_eyes *god_eyes,
			char **av, pthread_t *philo_thread)
{
	pthread_t		reaper;
	int				i;

	god_eyes->philo = philo;
	god_eyes->av = av;
	god_eyes->nb_of_philo = philo->nb_of_philo;
	pthread_mutex_init(&god_eyes->deat_mutex, NULL);
	pthread_mutex_init(&god_eyes->eat_mutex, NULL);
	pthread_mutex_lock(&god_eyes->deat_mutex);
	god_eyes->someone_died = 0;
	pthread_mutex_unlock(&god_eyes->deat_mutex);
	pthread_mutex_lock(&god_eyes->eat_mutex);
	god_eyes->everyone_eat = 0;
	god_eyes->finish_to_eat = 0;
	pthread_mutex_unlock(&god_eyes->eat_mutex);
	pthread_create(&reaper, NULL, reaper_routine, (void *) god_eyes);
	i = 0;
	while (i < philo->nb_of_philo)
		pthread_join(philo_thread[i++], NULL);
	free(philo_thread);
	pthread_join(reaper, NULL);
}
