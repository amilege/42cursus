/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:13:42 by amile-ge          #+#    #+#             */
/*   Updated: 2024/10/13 18:59:09 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	think(t_data *data, t_philo *philo, int time)
{
	impr(THINK, philo, data);
	usleep(time * 1000);
}

void	eat(t_data *data, t_philo *philo)
{
	if (philo->id % 2 == 0)
		eat2(data, philo);
	else
	{
		pthread_mutex_lock(philo->l_fork);
		impr(FORK_L, philo, data);
		if (philo->l_fork == philo->r_fork)
		{
			pthread_mutex_unlock(philo->l_fork);
			usleep(data->time_to_die * 1000);
			return ;
		}
		pthread_mutex_lock(philo->r_fork);
		impr(FORK_R, philo, data);
	}
	if (philo->l_fork != philo->r_fork)
		eat_action(data, philo);
	else
		usleep(data->time_to_die * 1000);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	eat2(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	impr(FORK_R, philo, data);
	pthread_mutex_lock(philo->l_fork);
	impr(FORK_L, philo, data);
}

void	sleepy(t_data *data, t_philo *philo)
{
	impr(SLEEP, philo, data);
	usleep(data->time_to_sleep * 1000);
}
