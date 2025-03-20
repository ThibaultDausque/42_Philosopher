/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:45:12 by thibault          #+#    #+#             */
/*   Updated: 2025/03/18 15:45:15 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int			nb_philo;
	t_time		time;
	t_philo		*philo;
	t_god_eyes	*god_eyes;

	if (ac != 5 && ac != 6)
		return (0);
	if (!positive_num(ac, av) || !check_number(av))
		return (0);
	nb_philo = ft_atoi(av[1]);
	philo = (t_philo *)malloc(sizeof(t_philo) * nb_philo);
	god_eyes = (t_god_eyes *)malloc(sizeof(t_god_eyes));
	if (!philo || !god_eyes)
		return (0);
	philo->nb_of_philo = nb_philo;
	time.time_to_die = ft_atoi(av[2]);
	time.time_to_eat = ft_atoi(av[3]);
	time.time_to_sleep = ft_atoi(av[4]);
	philo_thread(philo, time, god_eyes, av);
	free(philo);
	return (0);
}
