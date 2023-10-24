/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:36:52 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/24 22:08:43 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

struct	s_val;

typedef struct s_philo
{
	int				num;
	int				n_ate;
	int				left_i;
	int				right_i;
	int				dead;
	int				eating;
	long long		last_meal;
	struct s_val	*data;
	pthread_t		id;
}				t_philo;

typedef struct s_val
{
	int				n_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				n_meal;
	int				all_meal_ate;
	int				all_dead;
	long long		start;
	int				end;
	pthread_t		supervise;
	pthread_mutex_t	looper;
	pthread_mutex_t	printing;
	pthread_mutex_t	eating;
	pthread_mutex_t	*forks;
}				t_val;

# define ERROR_ARG	"Launch program with following arguments :\n\
--	./philo [1][2][3][4][5]\n\
--	[1] : [number_of_philosophers] (1-INT_MAX)\n\
--	[2] : [time_to_die] (0-INT_MAX)\n\
--	[3] : [time_to_eat] (0-INT_MAX)\n\
--	[4] : [time_to_sleep] (0-INT_MAX)\n\
--	[5] : [number_of_times_each_philosopher_must_eat] (0-INT_MAX)\
 (not mandatory for starting)\n"

# define INT_MAX 2147483647

int			parsing(int ac, char **av, t_val *data);
int			init_struct(char **av, t_val *data);
long long	my_atoll(char *str);
int			my_atoi(char *str);
int			my_strlen(char *str);
void		*p_routine(void *ptr);
int			init_philo(t_philo *philo, t_val *data);
long long	currenttime(void);
int			start_philo(t_philo *philo, t_val *data);
void		end_philo(t_philo *philo, t_val *data);
void		*p_routine(void *ptr);
void		*philo_superviser(void *ptr);
void		philo_wait(long long tt_wait);
int			loop_check(t_philo *p, t_val *data);
void		write_msg(int num, t_val *d, int msg, t_philo *p);

#endif