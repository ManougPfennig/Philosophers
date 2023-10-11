/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:57:00 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/11 23:33:43 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_val	*data;
	t_val	temp;

	data = &temp;
	if (parsing(ac, av, data))
		return (1);
	if (init_philo(data))
		return (1);
	if (start_philo(data))
		return (1);
	return (0);
}