/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:08:44 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/15 11:54:02 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	my_atoll(char *str)
{
	int			i;
	long long	ret;

	ret = 0;
	i = 0;
	while (str && str[i])
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	return (ret);
}

int	my_atoi(char *str)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (str && str[i])
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	return (ret);
}

int	init_struct(char **av, t_val *data)
{
	data->philo_n = my_atoi(av[1]);
	data->tt_die = my_atoi(av[2]);
	data->tt_eat = my_atoi(av[3]);
	data->tt_sleep = my_atoi(av[4]);
	if (av[5])
		data->ntt_eat = my_atoi(av[5]);
	else
		data->ntt_eat = -1;
	if (data->philo_n < 1)
		return (1);
	return (0);
}
