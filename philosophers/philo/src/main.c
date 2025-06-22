/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:33:12 by amile-ge          #+#    #+#             */
/*   Updated: 2024/10/12 19:02:18 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	parsing(int argc, char **argv, t_data *data)
{
	data->death_flag = 0;
	data->num_philos = atoi(argv[1]);
	if (data->num_philos <= 0 || (argc != 5 && argc != 6))
	{
		if (data->num_philos <= 0)
			printf("Number of philos has to be higher\n");
		else
			printf("Number of parameters incorrect\n");
		return (1);
	}
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		data->meals_to_eat = atoi(argv[5]);
	else
		data->meals_to_eat = -1;
	if (data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
	{
		printf("Invalid arguments: values must be greater than 0.");
		return (1);
	}
	return (0);
}

int	room(t_data *data)
{
	int	i;
	int	thread_status;

	data->first_time = g_time();
	i = 0;
	if (i < data->num_philos)
	{
		thread_status = pthread_create(&data->goddess->monitor_thread, NULL,
				&monitor, data);
		if (thread_status != 0)
		{
			printf("Error creating monitor\n");
			return (1);
		}
	}
	while (i < data->num_philos)
	{
		pthread_create(&data->philos[i].thread, NULL, &playroom,
			&data->philos[i]);
		i++;
	}
	return (0);
}

void	*monitor(void *arg)
{
	int		i;
	t_data	*data;

	data = (t_data *)arg;
	data->flag_meals = 0;
	while (check_death(data) == 0)
	{
		i = 0;
		while (i < data->num_philos)
		{
			check_meals(data, &data->philos[i]);
			pthread_mutex_lock(&data->comida);
			if (philo_time(data)
				- data->philos[i].last_meal >= data->time_to_die)
			{
				pthread_mutex_unlock(&data->comida);
				impr(DIE, &data->philos[i], data);
				return (NULL);
			}
			pthread_mutex_unlock(&data->comida);
			i++;
		}
		usleep(0);
	}
	return (0);
}

void	*playroom(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->table;
	pthread_mutex_lock(&data->comida);
	philo->c_meals = 0;
	pthread_mutex_unlock(&data->comida);
	while (check_death(data) != 1)
	{
		eat(data, philo);
		sleepy(data, philo);
		think(data, philo, 1);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	if (ft_check_args(argc, argv) == 1)
		return (1);
	if (parsing(argc, argv, &data) != 0)
		return (1);
	if (init_estruct(&data) != 0)
	{
		cleanup(&data);
		return (1);
	}
	room(&data);
	pthread_join(data.goddess->monitor_thread, NULL);
	i = 0;
	while (i < data.num_philos)
	{
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
	cleanup(&data);
	return (0);
}
