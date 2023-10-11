/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:30:52 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/11 23:24:45 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	fork_index(t_val *data, int i)
{
	data->philo[i].left_i = i;
	if (i + 1 == data->n_philo)
		data->philo[i].right_i = 0;
	else
		data->philo[i].right_i = i + 1;
}

int	init_mutex(t_val *data)
{
	int	i;

	i = 0;

	while (i != 250)
	{
		if(pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			printf("Error occured while initialising mutex : Exiting\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_philo(t_val *data)
{
	int	i;

	if (init_mutex(data))
		return (1);
	i = 0;
	while (i != data->n_philo)
	{
		data->philo[i].num = i + 1;
		data->philo[i].n_ate = 0;
		data->philo[i].dead = 0;
		fork_index(data, i);
		data->philo[i].values = data;
		i++;
	}
	return (0);
}
