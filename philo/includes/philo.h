/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:36:52 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/11 17:17:55 by mapfenni         ###   ########.fr       */
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

struct s_philo;

typedef struct s_val
{
	int				n_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				n_meal;
	int				all_meal_ate;
	long long		timer_start;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	forks[250];
	t_philo			*philo;
}				t_val;

typedef struct s_philo
{
	int			num;
	int			n_ate;
	int			left_id;
	int			right_id;
	long long	last_timer;
	t_val		values;
	pthread_t	id;
}				t_philo;


# define ERROR_ARG	"Launch program with following arguments :\n\
--	./philo [1][2][3][4][5]\n\
--	[1] : [number_of_philosophers] (1-INT_MAX)\n\
--	[2] : [time_to_die] (0-INT_MAX)\n\
--	[3] : [time_to_eat] (0-INT_MAX)\n\
--	[4] : [time_to_sleep] (0-INT_MAX)\n\
--	[5] : [number_of_times_each_philosopher_must_eat] (0-INT_MAX)\
 (mandatory)\n"

# define INT_MAX 2147483647

int			parsing(int ac, char **av, t_val *data);
int			init_struct(char **av, t_val *data);
long long	my_atoll(char *str);
int			my_atoi(char *str);
int			my_strlen(char *str);
void		*philo_routine(void *ptr);

#endif