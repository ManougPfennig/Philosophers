/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_routine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:18:40 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/24 22:02:37 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	write_msg(int num, t_val *d, int msg, t_philo *p)
{
	pthread_mutex_lock(&d->printing);
	if (msg == 1 && loop_check(p, d))
		printf("%lld %d has taken a fork\n", (currenttime() - d->start), num);
	else if (msg == 2 && loop_check(p, d))
		printf("%lld %d is eating\n", (currenttime() - d->start), num);
	else if (msg == 3 && loop_check(p, d))
		printf("%lld %d is sleeping\n", (currenttime() - d->start), num);
	else if (msg == 4 && loop_check(p, d))
		printf("%lld %d is thinking\n", (currenttime() - d->start), num);
	else if (msg == 5)
		printf("%lld %d died\n", (currenttime() - d->start), num);
	else if (msg == 6)
		printf("%lld %d can't use fork yet\n", (currenttime() - d->start), num);
	pthread_mutex_unlock(&d->printing);
}

int	is_lonely(t_philo *p, t_val *data)
{
	pthread_mutex_unlock(&data->forks[p->left_i]);
	while (!p->dead)
		usleep(50);
	return (1);
}

void	philo_eating(t_philo *p, t_val *data)
{
	pthread_mutex_lock(&data->forks[p->left_i]);
	write_msg(p->num, data, 1, p);
//	if (data->n_philo == 1 && is_lonely(p, data))
//		return ;
	pthread_mutex_lock(&data->forks[p->right_i]);
	write_msg(p->num, data, 1, p);
	write_msg(p->num, data, 2, p);
	p->eating = 1;
	p->n_ate++;
	philo_wait(data->tt_eat);
	p->last_meal = currenttime();
	p->eating = 0;
	pthread_mutex_unlock(&data->forks[p->left_i]);
	pthread_mutex_unlock(&data->forks[p->right_i]);
}

void	philo_sleep(long long tt_wait, t_philo *p)
{
	long long	time_ref;

	time_ref = currenttime();
	while (currenttime() - time_ref <= tt_wait && !p->dead)
		usleep(50);
}

void	*p_routine(void *ptr)
{
	t_philo	*p;
	t_val	*data;

	p = (t_philo *)ptr;
	data = p->data;
	if (p->num % 2)
		usleep(1500);
	while (loop_check(p, data))
	{
		philo_eating(p, data);
		write_msg(p->num, data, 3, p);
		philo_sleep(data->tt_sleep, p);
		write_msg(p->num, data, 4, p);
	}
	return (NULL);
}
