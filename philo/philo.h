/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:19:24 by thibault          #+#    #+#             */
/*   Updated: 2025/03/25 12:40:06 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <errno.h>

typedef struct s_philo	t_philo;

typedef struct s_god_eyes
{
	int				someone_died;
	t_philo			*philo;
	int				nb_of_philo;
	pthread_mutex_t	deat_mutex;
	pthread_mutex_t	eat_mutex;
	int				finish_to_eat;
	char			**av;
	int				everyone_eat;
}	t_god_eyes;

typedef struct s_philo
{
	int					id;
	int					nb_of_philo;
	int					time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*message;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		meal_lock;
	int					start_time;
	int					last_meal;
	int					nb_of_meal;
	int					someone_died;
	int					nb_philo_must_eat;
	int					finish;
	t_god_eyes			*god_eyes;
}	t_philo;

typedef struct s_time
{
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
}	t_time;

/************ UTILS ************/
int		check_number(char **av);
int		positive_num(int ac, char **av);
int		ft_atoi(const char *s);
void	print_message(char *s, t_philo *philo, int id);

/************ ROUTINE ************/
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);

/************ PHILO ************/
void	*routine(void *arg);
void	philo_thread(t_philo *philo, t_god_eyes *god_eyes, char **av);

/************ TIME ************/
int		get_time(void);
int		elapsed_time(int start_time);
void	ft_usleep(int time);

/************ REAPER ************/
void	*reaper_routine(void *args);
void	init_god(t_philo *philo, t_god_eyes *god_eyes, char **av,
			pthread_t *philo_thread);

/************ DIE UTILS ************/
void	set_die(t_god_eyes *god_eyes);
int		check_death(t_god_eyes *god_eyes);
int		check_eat(t_god_eyes *god_eyes);
int		everyone_eat(t_philo *philo);
void	set_eat(t_god_eyes *god_eyes);

#endif