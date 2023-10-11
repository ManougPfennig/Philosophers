/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_routine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:18:40 by mapfenni          #+#    #+#             */
/*   Updated: 2023/10/11 23:44:34 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*p_routine(void *ptr)
{
	t_philo	*p;

	p = (t_philo *)ptr;
//	if (p->num % 2)
//		usleep(15000);
	while (!p->dead)
	{
		pthread_mutex_lock(&p->values->printing);
		printf("thread %i\n", p->num);
		pthread_mutex_unlock(&p->values->printing);
		p->dead = 1;
	}
	return (0);
}