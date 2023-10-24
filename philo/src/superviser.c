/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superviser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:54:20 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/24 22:02:35 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_wait(long long tt_wait)
{
	long long	time_ref;

	time_ref = currenttime();
	while (currenttime() - time_ref <= tt_wait)
		usleep(50);
}

int	loop_check(t_philo *p, t_val *data)
{
	pthread_mutex_lock(&data->looper);
	if (data->all_dead || data->all_meal_ate || p->dead || data->end)
	{
		pthread_mutex_unlock(&data->looper);
		return (0);
	}
	pthread_mutex_unlock(&data->looper);
	return (1);
}

void	are_over(t_val *data, t_philo *p)
{
	int	i;
	int	death;
	int	full;

	death = 0;
	full = 0;
	i = -1;
	while (++i != data->n_philo)
	{
		if (p[i].dead)
			death++;
		if (p[i].n_ate >= data->n_meal || p[i].dead)
			full++;
	}
	pthread_mutex_lock(&data->looper);
	if (data->n_meal == -1)
		full = -1;
	if (death == data->n_philo)
		data->all_dead = 1;
	if (full == data->n_philo)
		data->all_meal_ate = 1;
	pthread_mutex_unlock(&data->looper);
}

int	is_dead(t_philo *p, t_val *data)
{
	pthread_mutex_lock(&data->looper);
	if (p->eating)
	{
		pthread_mutex_unlock(&data->looper);
		return (0);
	}
	if (!p->dead && currenttime() - p->last_meal >= data->tt_die)
	{
		p->dead = 1;
		if (data->n_meal == -1)
			data->end = 1;
		pthread_mutex_unlock(&data->looper);
		return (1);
	}
	pthread_mutex_unlock(&data->looper);
	return (0);
}

void	*philo_superviser(void *ptr)
{
	int	i;
	t_philo *p;
	t_val *data;

	p = (t_philo *)ptr;
	data = p->data;
	while (data->start == 0)
		usleep(10);
	while (!data->all_dead && !data->all_meal_ate && !data->end)
	{
		i = -1;
		while (!data->end && ++i != data->n_philo)
		{
			if (is_dead(p + i, data))
				write_msg(p[i].num, data, 5, p + i);
		}
		are_over(data, p);
	}
	data->end = 1;
	return (NULL);
}
