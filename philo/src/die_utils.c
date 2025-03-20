/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:50:13 by tdausque          #+#    #+#             */
/*   Updated: 2025/03/20 16:05:13 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_die(t_god_eyes *god_eyes)
{
	pthread_mutex_lock(&god_eyes->deat_mutex);
	god_eyes->someone_died = 1;
	pthread_mutex_unlock(&god_eyes->deat_mutex);
}

int	check_death(t_god_eyes *god_eyes)
{
	int		died;

	pthread_mutex_lock(&god_eyes->deat_mutex);
	died = god_eyes->someone_died;
	pthread_mutex_unlock(&god_eyes->deat_mutex);
	return (died);
}
