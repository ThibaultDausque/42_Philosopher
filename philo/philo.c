/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:25:20 by thibault          #+#    #+#             */
/*   Updated: 2025/03/07 16:13:36 by thibault         ###   ########.fr       */
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
	pthread_t		*philo_thread;
	pthread_mutex_t	*fork;
	int				i;

	philo_thread = (pthread_t *)malloc(sizeof(pthread_t) * nb_philo);
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!philo_thread || !fork)
		return ;
	
	i = 0;
	while (i < nb_philo)
		pthread_mutex_init(&fork[i++], NULL);

	i = 0;
	//initialiser chaque philosophe
	while (i < nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].time_to_eat = time.time_to_eat;
		philo[i].time_to_sleep = time.time_to_sleep;
		philo[i].l_fork = &fork[i];
		philo[i].r_fork = &fork[(i + 1) % nb_philo];
		pthread_create(&philo_thread[i], NULL, routine, (void *) &philo[i]);
		i++;
	}

	i = 0;
	while (i < nb_philo)
		pthread_join(philo_thread[i++], NULL);

	i = 0;
	while (i < nb_philo)
		pthread_mutex_destroy(&fork[i++]);

}
