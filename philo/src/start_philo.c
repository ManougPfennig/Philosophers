/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:36:58 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/24 21:57:28 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_philo(t_philo *philo, t_val *data)
{
	int	i;

	i = 0;
	data->start = currenttime();
	while(i != data->n_philo)
	{
		philo[i].data = data;
		philo[i].eating = 0;
		if (pthread_create(&philo[i].id, NULL, p_routine, &philo[i]))
		{
			printf("Error while creating thread : Exiting\n");
			return (1);
		}
		philo[i].last_meal = currenttime();
		i++;
	}
	if (pthread_create(&data->supervise, NULL, philo_superviser, philo))
	{
			printf("Error while creating thread : Exiting\n");
			return (1);
	}
	return (0);
}

void	end_philo(t_philo *philo, t_val *data)
{
	int		i;

	pthread_join(data->supervise, NULL);
	i = -1;
	while (++i != data->n_philo)
		pthread_mutex_unlock(data->forks + i);
	i = -1;
	while (++i != data->n_philo)
	{
		pthread_join(philo[i].id, NULL);
		pthread_detach(philo[i].id);
	}
	free(philo);
	i = -1;
	while (++i != data->n_philo)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->eating);
	pthread_mutex_destroy(&data->printing);
	pthread_mutex_destroy(&data->looper);
	free(data->forks);
	return ;
}