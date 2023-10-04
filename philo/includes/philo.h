/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:36:52 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/04 12:08:49 by mapfenni         ###   ########.fr       */
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

typedef struct s_philo {
	struct timeval	last_meal;
	int				n_meals;
	int				finished;
	int				left;
	int				right;
	int				number;
	pthread_t		id;
}				t_philo;

typedef struct s_val {
	int				philo_n;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				ntt_eat;
	struct timeval	starttime;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}				t_val;

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
int			my_strlen(char *str);
void		*philo_routine(void *ptr);

#endif