/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:36:58 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/11 23:34:46 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_philo(t_val *data)
{
	int	i;

	i = 0;
	while(i != data->n_philo)
	{
		if (pthread_create(&data->philo[i].id, NULL, p_routine, &data->philo[i]))
		{
			printf("Error while creating thread : Exiting\n");
			return (1);
		}
		data->philo[i].last_meal = currenttime();
		i++;
	}
	return (0);
}
