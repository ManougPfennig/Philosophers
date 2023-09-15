/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:56:30 by mapfenni          #+#    #+#             */
/*   Updated: 2023/09/14 19:24:33 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	parsing_error(void)
{
	printf(ERROR_ARG);
	exit(EXIT_FAILURE);
}

void	parsing(int ac, char **av)
{
	(void)av;
	if (ac < 5 || ac > 6)
		parsing_error();
}