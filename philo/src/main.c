/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:57:00 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/17 17:40:29 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_val	*data;
	t_val	temp;
	t_philo	philo[250];

	data = &temp;
	if (parsing(ac, av, data))
		return (1);
	if (init_philo(philo, data))
		return (1);
	if (start_philo(philo, data))
		return (1);
	philo_superviser(philo, data);
	end_philo(philo, data);
	return (0);
}