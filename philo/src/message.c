/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:40:09 by shovsepy          #+#    #+#             */
/*   Updated: 2021/08/19 18:40:11 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_status(t_philo *philo, char *msg)
{
	int		index;
	long	time;

	index = philo->index;
	time = get_time_ms() - philo->born_time_ms;
	printf("%ld #%d %s\n", time, index, msg);
	return (0);
}
