/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:36:58 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/17 17:40:46 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_philo(t_philo philo[250], t_val *data)
{
	int	i;

	i = 0;
	data->start = currenttime();
	while(i != data->n_philo)
	{
		philo[i].data = data;
		philo[i].last_meal = currenttime();
		if (pthread_create(&philo[i].id, NULL, p_routine, &philo[i]))
		{
			printf("Error while creating thread : Exiting\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	end_philo(t_philo philo[250], t_val *data)
{
	int	i;

	i = 0;
	while (i != data->n_philo)
	{
		pthread_join(philo[i].id, NULL);
		i++;
	}
	return ;
}