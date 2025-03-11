/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:25:20 by thibault          #+#    #+#             */
/*   Updated: 2025/03/11 13:57:46 by tdausque         ###   ########.fr       */
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
		if (philo->nb_of_meal == philo->nb_philo_must_eat)
			break ;
		if (ft_dead(philo))
			break ;
	}
	return (NULL);
}

void	free_thread(pthread_t *philo_thread, pthread_mutex_t *fork,
	pthread_mutex_t *message ,int nb_of_philo)
{
	int		i;

	i = 0;
	while (i < nb_of_philo)
		pthread_join(philo_thread[i++], NULL);
	i = 0;
	while (i < nb_of_philo)
		pthread_mutex_destroy(&fork[i++]);
	pthread_mutex_destroy(message);
	free(philo_thread);
	free(fork);
	free(message);
}

void	philo_thread(t_philo *philo, t_time time, int nb_of_philo, char **av)
{
	pthread_t		*philo_thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*message;
	int				i;

	philo_thread = (pthread_t *)malloc(sizeof(pthread_t) * nb_of_philo);
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nb_of_philo);
	message = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!philo_thread || !fork || !message)
		return ;
	i = 0;
	while (i < nb_of_philo)
		pthread_mutex_init(&fork[i++], NULL);
	pthread_mutex_init(message, NULL);
	i = 0;
	while (i < nb_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].time_to_eat = time.time_to_eat;
		philo[i].time_to_sleep = time.time_to_sleep;
		philo[i].time_to_die = time.time_to_die;
		philo[i].l_fork = &fork[i];
		philo[i].r_fork = &fork[(i + 1) % nb_of_philo];
		philo[i].message = message;
		philo[i].start_time = get_time();
		philo[i].nb_of_meal = 0;
		if (av[5])
			philo[i].nb_philo_must_eat = ft_atoi(av[5]);
		pthread_create(&philo_thread[i], NULL, routine, (void *) &philo[i]);
		i++;
	}
	free_thread(philo_thread, fork, message, nb_of_philo);
}
