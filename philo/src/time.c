/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:17:11 by tdausque          #+#    #+#             */
/*   Updated: 2025/03/20 10:29:35 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)tv.tv_sec * 1000 + (long)(tv.tv_usec / 1000));
}

long	elapsed_time(int start_time)
{
	return (get_time() - start_time);
}

void	ft_usleep(int time, t_philo *philo)
{
	long			end;
	struct timeval	tv;
	(void) philo;

	gettimeofday(&tv, NULL);
	end = (tv.tv_sec * 1000 + tv.tv_usec / 1000) + time;
	while ((tv.tv_sec *1000 + tv.tv_usec / 1000) < end)
	{
		// if (philo->god_eyes->someone_died == 1)
		// 	break ;
		gettimeofday(&tv, NULL);
		if ((tv.tv_sec *1000 + tv.tv_usec / 1000) >= end)
			break ;
		usleep(100);
	}
}
