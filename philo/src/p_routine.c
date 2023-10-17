/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_routine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:18:40 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/17 18:34:23 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	write_msg(int num, t_val *d, int msg, t_philo *p)
{
	if (p->dead)
		return ;
	pthread_mutex_lock(&d->printing);
	if (msg == 1)
		printf("%lld %d has taken a fork\n", (d->start - currenttime()), num);
	else if (msg == 2)
		printf("%lld %d is eating\n", (d->start - currenttime()), num);
	else if (msg == 3)
		printf("%lld %d is sleeping\n", (d->start - currenttime()), num);
	else if (msg == 4)
		printf("%lld %d is thinking\n", (d->start - currenttime()), num);
	else if (msg == 5)
		printf("%lld %d died\n", (d->start - currenttime()), num);
	pthread_mutex_unlock(&d->printing);
}

void	philo_wait(long long tt_wait, t_val *data)
{
	long long	time_ref;

	time_ref = currenttime();
	while (!data->all_dead)
	{
		if (currenttime() - time_ref >= tt_wait)
			break ;
		usleep(50);
	}
}

void	philo_eating(t_philo *p, t_val *data)
{
	if (p->dead)
		return ;
	pthread_mutex_lock(&data->forks[p->left_i]);
	write_msg(p->num, data, 1, p);
	pthread_mutex_lock(&data->forks[p->right_i]);
	write_msg(p->num, data, 1, p);
	pthread_mutex_lock(&data->eating);
	p->n_ate++;
	write_msg(p->num, data, 2, p);
	p->last_meal = currenttime();
	pthread_mutex_unlock(&data->eating);
	philo_wait(data->tt_eat, data);
	pthread_mutex_unlock(&data->forks[p->left_i]);
	pthread_mutex_unlock(&data->forks[p->right_i]);
}

void	*p_routine(void *ptr)
{
	t_philo	*p;
	t_val	*data;

	p = (t_philo *)ptr;
	data = p->data;
	if (p->num % 2)
		usleep(1500);
	while (!data->all_dead && !p->dead)
	{
		philo_eating(p, data);
		if (data->all_meal_ate || data->all_dead || p->dead)
			break ;
		write_msg(p->num, data, 3, p);
		philo_wait(data->tt_sleep, data);
		write_msg(p->num, data, 4, p);
	}
	return (NULL);
}
