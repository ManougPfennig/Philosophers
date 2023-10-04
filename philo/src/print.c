/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:11:03 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/02 14:20:38 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_act(int timestamp, int philo, int action)
{
	if (action == 1)
		printf("%d %d has taken a fork\n", timestamp, philo);
	else if (action == 2)
		printf("%d %d is eating\n", timestamp, philo);
	else if (action == 3)
		printf("%d %d is sleeping\n", timestamp, philo);
	else if (action == 4)
		printf("%d %d is thinking\n", timestamp, philo);
	else if (action == 5)
		printf("%d %d died\n", timestamp, philo);
	else
		printf("wrong printing value\n");
}