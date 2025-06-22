/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:51:52 by amile-ge          #+#    #+#             */
/*   Updated: 2024/10/13 18:05:29 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

unsigned int	philo_time(t_data *data)
{
	return (g_time() - data->first_time);
}

unsigned int	g_time(void)
{
	struct timeval	tmp;
	unsigned int	current_time;

	gettimeofday(&tmp, NULL);
	current_time = (tmp.tv_sec * 1000) + (tmp.tv_usec / 1000);
	return (current_time);
}

int	impr(int action, t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->impr);
	if (check_death(data) != 1)
	{
		if (action == DIE || action == LLENOS)
		{
			pthread_mutex_lock(&data->check_death_flag);
			philo->table->death_flag = 1;
			pthread_mutex_unlock(&data->check_death_flag);
			if (action == DIE)
				printf("%u: philo %d has died\n", philo_time(data), philo->id);
			pthread_mutex_unlock(&data->impr);
			return (0);
		}
		else if (action == EAT)
			printf("%u: philo %d is eating\n", philo_time(data), philo->id);
		else if (action == SLEEP)
			printf("%u: philo %d is sleeping\n", philo_time(data), philo->id);
		else if (action == THINK)
			printf("%u: philo %d is thinking\n", philo_time(data), philo->id);
		else if (action == FORK_L || action == FORK_R)
			impr2(action, philo, data);
	}
	pthread_mutex_unlock(&data->impr);
	return (0);
}

void	impr2(int action, t_philo *philo, t_data *data)
{
	if (action == FORK_R)
		printf("%u: Philo%i has taken the r fork\n", philo_time(data),
			philo->id);
	else if (action == FORK_L)
		printf("%u: Philo%i has taken the l fork\n", philo_time(data),
			philo->id);
}

void	eat_action(t_data *data, t_philo *philo)
{
	impr(EAT, philo, data);
	pthread_mutex_lock(&data->comida);
	philo->last_meal = philo_time(data);
	philo->c_meals++;
	pthread_mutex_unlock(&data->comida);
	usleep(data->time_to_eat * 1000);
}
