/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:57:00 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/04 12:13:33 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_philo(t_val *data)
{
	int	i;

	data->forks = malloc(data->philo_n * sizeof(pthread_mutex_t));
	data->philo = malloc(data->philo_n * sizeof(t_philo));
	gettimeofday(&data->starttime, NULL);
	i = 0;
	while (i < data->philo_n)
	{
		data->philo[i].number = i + 1;
		gettimeofday(&data->philo[i].last_meal, NULL);
		pthread_create(&data->philo[i].id, NULL, philo_routine(data), data);
		printf("there is this many philo -> %d\n", data->philo_n);
		i++;
	}
}

void	*test_cmd(void *lock)
{
	pthread_mutex_t *ptr = lock;
	int max = 2;
	int min = 0;
	pthread_mutex_lock(ptr);
	while (min < max)
	{
		min++;
		printf("- %d -\n", min);
	}
	pthread_mutex_unlock(ptr);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_val	*data;
	t_val	temp;

	data = &temp;
	if (parsing(ac,av, data))
		return (1);
	init_philo(data);
	return (0);
}