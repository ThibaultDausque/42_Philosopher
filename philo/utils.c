/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:24:56 by thibault          #+#    #+#             */
/*   Updated: 2025/03/09 12:10:37 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(const char *s)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result *= 10;
		result += s[i] - '0';
		i++;
	}
	return (result * sign);
}

int	check_number(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				ft_printf("error: input isn't a number\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	positive_num(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 0)
		{
			ft_printf("error: negative number\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	print_message(char *s, t_philo *philo, int id)
{
	if (!s)
		return ;
	pthread_mutex_lock(philo->message);
	ft_printf("[%d ms] Philosopher %d %s\n", (int)elapsed_time(philo->start_time), id, s);
	pthread_mutex_unlock(philo->message);
}

long long	get_time(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	elapsed_time(long long start_time)
{
	return (get_time() - start_time);
}