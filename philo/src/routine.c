/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:31:44 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/04 12:12:39 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine(void *ptr)
{
	t_val	*data;

	data = ptr;
	printf("hello i am philo %d\n", data->philo->number);
	printf("ok\n");
	return(NULL);
}