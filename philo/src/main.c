/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:57:00 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/09 13:18:45 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_val	*data;
	t_val	temp;

	data = &temp;
	if (parsing(ac,av, data))
		return (1);
	return (0);
}