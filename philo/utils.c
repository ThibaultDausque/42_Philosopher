/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:24:56 by thibault          #+#    #+#             */
/*   Updated: 2025/03/01 19:50:05 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/philo.h"

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

int	check_number(const char *s)
{
	int		i;
	
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_input(int ac, char **av)
{
	int		i;
	long	output;

	i = 0;
	while (i < ac)
	{
		if (!check_number(av))
			return (0);
		i++;
	}
}