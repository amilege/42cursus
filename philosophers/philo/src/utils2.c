/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:24:43 by amile-ge          #+#    #+#             */
/*   Updated: 2024/10/13 19:12:42 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	check_meals(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->comida);
	if (data->meals_to_eat > 0)
	{
		if (philo->c_meals == data->meals_to_eat)
		{
			philo->c_meals++;
			data->flag_meals++;
			if (data->flag_meals == data->num_philos)
			{
				pthread_mutex_lock(
					&(&data->philos[i])->table->check_death_flag);
				(&data->philos[i])->table->death_flag = 1;
				pthread_mutex_unlock(
					&(&data->philos[i])->table->check_death_flag);
				if (check_death(data) == 1)
					printf("%u: ALL PHILOS HAVE EATEN\n", philo_time(data));
				pthread_mutex_unlock(&data->comida);
				return ;
			}
		}
	}
	pthread_mutex_unlock(&data->comida);
}

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].last_meal_flag);
		i++;
	}
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->impr);
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->check_death_flag);
	pthread_mutex_destroy(&data->check_flag);
	free(data->forks);
	free(data->philos);
	free(data->goddess);
}

int	check_death(t_data *data)
{
	int	morir;

	morir = 0;
	pthread_mutex_lock(&data->check_death_flag);
	if (data->death_flag == 1)
		morir = 1;
	pthread_mutex_unlock(&data->check_death_flag);
	return (morir);
}

int	init_estruct(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(data->num_philos * sizeof(pthread_mutex_t));
	data->philos = malloc(data->num_philos * sizeof(t_philo));
	data->goddess = malloc(sizeof(t_god));
	if (!data->forks || !data->philos || !data->goddess)
	{
		free(data->forks);
		free(data->goddess);
		free(data->philos);
		printf("Memory allocation failed.");
		return (1);
	}
	create_mutex(data);
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].r_fork = &data->forks[i];
		data->philos[i].l_fork = &data->forks[(i + 1) % data->num_philos];
		data->philos[i].table = data;
		i++;
	}
	return (0);
}

int	create_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->philos[i].last_meal_flag, NULL);
		i++;
	}
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->comida, NULL);
	pthread_mutex_init(&data->impr, NULL);
	pthread_mutex_init(&data->check_death_flag, NULL);
	pthread_mutex_init(&data->check_flag, NULL);
	return (0);
}
