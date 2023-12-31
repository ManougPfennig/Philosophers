/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:30:52 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/24 22:09:40 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	fork_index(t_val *data, t_philo *philo, int i)
{
	philo[i].left_i = i;
	if (i + 1 == data->n_philo)
		philo[i].right_i = 0;
	else
		philo[i].right_i = i + 1;
}

int	init_mutex(t_val *data)
{
	int	i;

	i = 0;
	data->forks = malloc((data->n_philo) * sizeof(pthread_mutex_t));
	while (i != data->n_philo)
	{
		if (pthread_mutex_init(data->forks + i, NULL) != 0)
		{
			printf("Error occured while initialising mutex : Exiting\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_philo(t_philo *philo, t_val *data)
{
	int		i;

	if (init_mutex(data))
		return (1);
	i = 0;
	while (i != data->n_philo)
	{
		philo[i].num = i + 1;
		philo[i].n_ate = 0;
		philo[i].dead = 0;
		philo[i].eating = 0;
		fork_index(data, philo, i);
		i++;
	}
	return (0);
}
