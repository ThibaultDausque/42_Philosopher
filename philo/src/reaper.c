/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:12:16 by tdausque          #+#    #+#             */
/*   Updated: 2025/03/20 16:02:48 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
				if (god_eyes->nb_of_philo > 1)
					print_message("died", &god_eyes->philo[i],
						god_eyes->philo[i].id);
				set_die(god_eyes);
				return (NULL);
			}
			pthread_mutex_unlock(&god_eyes->philo[i].meal_lock);
			i++;
		}
		usleep(100);
	}
}

void	init_god(t_philo *philo, t_god_eyes *god_eyes)
{
	pthread_t		reaper;

	god_eyes->philo = philo;
	god_eyes->nb_of_philo = philo->nb_of_philo;
	pthread_mutex_init(&god_eyes->deat_mutex, NULL);
	pthread_mutex_lock(&god_eyes->deat_mutex);
	god_eyes->someone_died = 0;
	pthread_mutex_unlock(&god_eyes->deat_mutex);
	pthread_create(&reaper, NULL, reaper_routine, (void *) god_eyes);
	pthread_join(reaper, NULL);
}
