/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:25:20 by thibault          #+#    #+#             */
/*   Updated: 2025/03/07 12:20:38 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

// create 2 thread to simulate philo routine
void	create_thread(t_philo *philo, t_time time)
{
	int				nb_philo = 2;
	pthread_t		philo_thread[nb_philo];
	pthread_mutex_t	fork[nb_philo];
	int				i;
	int				j;

	i = 1;
	while (i <= nb_philo)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}

	i = 1;
	j = 0;
	//initialiser chaque philosophe
	while (i <= nb_philo)
	{
		philo[j].id = i;
		philo[j].time_to_eat = time.time_to_eat;
		philo[j].time_to_sleep = time.time_to_sleep;
		philo[j].l_fork = &fork[i];
		philo[j].r_fork = &fork[(i + 1) % nb_philo];
		pthread_create(&philo_thread[j], NULL, routine, (void *) &philo[i]);
		j++;
		i++;
	}

	i = 0;
	while (i < nb_philo)
		pthread_join(philo_thread[j], NULL);

	i = 0;
	while (i < nb_philo)
		pthread_mutex_destroy(&fork[i]);

}
