/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:56:30 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/15 11:54:31 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	str_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	parsing_error(void)
{
	printf(ERROR_ARG);
	return (1);
}

int	check_values(char **av)
{
	int			i;
	long long	temp;

	i = 0;
	while (av[i])
	{
		temp = my_atoll(av[i]);
		if (temp > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	parsing(int ac, char **av, t_val *data)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (parsing_error());
	while (av[i])
	{
		if (str_isnum(av[i]) || my_strlen(av[i]) == 0 || my_strlen(av[i]) > 10)
			return (parsing_error());
		i++;
	}
	if (check_values(av))
		return (parsing_error());
	if (init_struct(av, data))
		return (parsing_error());
	return (0);
}
