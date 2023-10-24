/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:07:24 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/24 22:10:00 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	currenttime(void)
{
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	return ((temp.tv_sec * 1000) + (temp.tv_usec / 1000));
}

long long	my_atoll(char *str)
{
	long long	ret;
	int			i;

	ret = 0;
	i = 0;
	while (str[i])
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	return (ret);
}

int	my_atoi(char *str)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (str[i])
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	return (ret);
}
