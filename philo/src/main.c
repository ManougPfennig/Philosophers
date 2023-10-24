/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:57:00 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/24 18:24:28 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_val	*data;
	t_val	temp;
	t_philo	*philo;

	data = &temp;
	philo = NULL;
	if (parsing(ac, av, data))
		return (0);
	philo = malloc((data->n_philo) * sizeof(t_philo));
	if (!philo)
		return (printf("Malloc error while initialising philo : Exiting\n"));
	if (init_philo(philo, data))
		return (1);
	if (start_philo(philo, data))
		return (1);
	end_philo(philo, data);
	return (0);
}