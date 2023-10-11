/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:16:45 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/09 13:34:04 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	left_right(int *left, int *right, int philo_n, int all_philo)
{
	*left = philo_n;
	if (philo_n == all_philo)
		*right = 0;
	else
		*right = philo_n + 1;
}

long long	currenttime(void)
{
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	return ((temp.tv_sec * 1000) + (temp.tv_usec / 1000));
}

int	init_struct(char **av, t_val *data)
{
	data->n_philo = my_atoi(av[1]);
	data->tt_die = my_atoi(av[2]);
	data->tt_eat = my_atoi(av[3]);
	data->tt_sleep = my_atoi(av[3]);
	if (av[4])
		data->n_meal = my_atoi(av[4]);
	else
		data->n_meal = -1;
	if (data->n_philo < 1)
		return (1);
	return (0);
}