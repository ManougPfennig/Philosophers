/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superviser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:54:20 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/17 18:44:03 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	death(t_philo *philo, t_val *data)
{
	write_msg(philo->num, data, 5, philo);
	philo->dead = 1;
	return (1);
}

int	finished_spaghetti(t_val *data, t_philo p[250])
{
	int	i;
	int	full;

	i = 0;
	full = 0;
	if (data->n_meal == -1)
		return (0);
	while (i != data->n_philo)
	{
		if (p[i].n_ate == data->n_meal)
			full++;
		i++;
	}
	if (full == i)
		return (1);
	return (0);
}

int	are_dead(t_val *data, t_philo p[250])
{
	int	i;
	int	dead;

	i = 0;
	dead = 0;
	while (i != data->n_philo)
	{
		if (p[i].dead == 1)
			dead++;
		i++;
	}
	if (dead == i)
		return (1);
	return (0);
}

void	philo_superviser(t_philo p[250], t_val *data)
{
	int	i;

	while (data->all_meal_ate == 0 && data->all_dead == 0)
	{
		i = -1;
		if (data->all_meal_ate || data->all_dead)
			break ;
		while (++i != data->n_philo)
		{
			pthread_mutex_lock(&data->eating);
			if (currenttime() - p[i].last_meal > data->tt_die && p[i].dead == 0)
			{
				death(&p[i], data);
				if (data->n_meal == -1)
					data->all_dead = 1;
			}
			pthread_mutex_unlock(&(data->eating));
		}
		usleep(10);
		data->all_meal_ate = finished_spaghetti(data, p);
		data->all_dead = are_dead(data, p);
	}
}
