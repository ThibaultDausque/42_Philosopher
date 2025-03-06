/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:45:12 by thibault          #+#    #+#             */
/*   Updated: 2025/03/06 17:18:07 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/philo.h"

int	main(int ac, char **av)
{
	int		nb_of_philo;
	t_philo	*philo;

	if (ac != 6)
		return (0);
	if (!check_number(ac, av) || !positive_num(ac, av));
		return (0);
	nb_of_philo = ft_atoi(av[1]);
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	return (0);
}