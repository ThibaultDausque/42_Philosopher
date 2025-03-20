/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:56:32 by tdausque          #+#    #+#             */
/*   Updated: 2025/03/20 15:59:24 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->nb_of_philo == 1)
	{
		print_message("has taken a fork", philo, philo->id);
		print_message("died", philo, philo->id);
		return (NULL);
	}
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
		if (check_death(philo->god_eyes))
			break ;
	}
	return (NULL);
}

void	init_and_free(t_philo *philo, t_god_eyes *god_eyes,
	pthread_t *philo_thread)
{
	int		i;

	init_god(philo, god_eyes);
	i = 0;
	while (i < philo->nb_of_philo)
		pthread_join(philo_thread[i++], NULL);
	free(philo_thread);
}

void	init_a_philo(int nb_of_philo, t_philo *philo,
	char **av, t_god_eyes *god_eyes)
{
	int				i;
	pthread_t		*philo_thread;
	pthread_mutex_t	meal_lock;

	philo_thread = (pthread_t *)malloc(sizeof(pthread_t) * nb_of_philo);
	if (!philo_thread)
		return ;
	pthread_mutex_init(&meal_lock, NULL);
	i = 0;
	while (i < nb_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].nb_of_philo = nb_of_philo;
		philo[i].time_to_die = ft_atoi(av[2]);
		philo[i].start_time = get_time();
		philo[i].nb_of_meal = 0;
		philo[i].last_meal = get_time();
		philo[i].meal_lock = meal_lock;
		if (av[5])
			philo[i].nb_philo_must_eat = ft_atoi(av[5]);
		pthread_create(&philo_thread[i], NULL, routine, (void *) &philo[i]);
		i++;
	}
	init_and_free(philo, god_eyes, philo_thread);
}

void	free_thread(pthread_mutex_t *fork, pthread_mutex_t *message,
	int nb_of_philo)
{
	int		i;

	i = 0;
	while (i < nb_of_philo)
		pthread_mutex_destroy(&fork[i++]);
	pthread_mutex_destroy(message);
	free(fork);
	free(message);
}

void	philo_thread(t_philo *philo, t_god_eyes *god_eyes, char **av)
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	*message;
	int				i;

	fork = malloc(sizeof(pthread_mutex_t) * philo->nb_of_philo);
	message = malloc(sizeof(pthread_mutex_t));
	if (!fork || !message)
		return ;
	i = 0;
	while (i < philo->nb_of_philo)
		pthread_mutex_init(&fork[i++], NULL);
	pthread_mutex_init(message, NULL);
	i = 0;
	while (i < philo->nb_of_philo)
	{
		philo[i].l_fork = &fork[i];
		philo[i].r_fork = &fork[(i + 1) % philo->nb_of_philo];
		philo[i].message = message;
		philo[i].god_eyes = god_eyes;
		philo[i].time_to_eat = ft_atoi(av[3]);
		philo[i].time_to_sleep = ft_atoi(av[4]);
		i++;
	}
	init_a_philo(philo->nb_of_philo, philo, av, god_eyes);
	free_thread(fork, message, philo->nb_of_philo);
}
