/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:16:45 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/17 17:24:44 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	data->all_meal_ate = 0;
	data->all_dead = 0;
	pthread_mutex_init(&data->printing, NULL);
	return (0);
}