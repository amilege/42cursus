/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:51:21 by amile-ge          #+#    #+#             */
/*   Updated: 2024/10/13 17:48:20 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define EAT 2
# define DIE 1
# define THINK 3
# define LLENOS 4
# define SLEEP 5
# define FORK_R 6
# define FORK_L 7

typedef struct philo
{
	int				id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	last_meal_flag;
	int				numl_fork;
	int				numr_fork;
	unsigned int	last_meal;
	int				c_meals;
	pthread_t		thread;
	struct data		*table;
	struct philo	*next;
	struct god		*goddess;

}					t_philo;

typedef struct god
{
	pthread_t		monitor_thread;
	struct data		*god_list;
	struct philo	*sims;

}					t_god;

typedef struct data
{
	int				time_to_sleep;
	int				time_to_eat;
	int				meals_to_eat;
	unsigned int	time_to_die;
	int				death_flag;
	int				c_meals;
	int				flag_meals;
	int				num_philos;
	unsigned int	time;
	unsigned int	real_time;
	unsigned int	first_time;
	unsigned int	inicio;
	unsigned int	final_time;
	pthread_mutex_t	lock;
	pthread_mutex_t	*forks;
	pthread_mutex_t	comida;
	pthread_mutex_t	impr;
	pthread_mutex_t	check_flag;
	pthread_mutex_t	check_death_flag;
	struct god		*goddess;
	t_philo			*philos;
	struct t_data	*next;
}					t_data;

int					create_mutex(t_data *data);
void				create_philo(void);
int					error_exit(char *str);
void				*playroom(void *arg);
int					destroy_threads(t_data *data);
void				think(t_data *data, t_philo *philo, int time);
void				eat(t_data *data, t_philo *philo);
void				sleepy(t_data *data, t_philo *philo);
unsigned int		g_time(void);
int					finish(int action, t_data *data, t_philo *philo);
unsigned int		philo_time(t_data *data);
void				cleanup(t_data *data);
int					impr(int action, t_philo *philo, t_data *data);
void				meals_to_eat(t_data *data, t_philo *philo);
void				check_init(t_data *data, t_philo *philo);
void				check_philo(t_data *data);
int					check_death(t_data *data);
void				*monitor(void *arg);
int					init_estruct(t_data *data);
void				check_meals(t_data *data, t_philo *philo);
int					lim_int(char *argv);
int					ft_check_args(int argc, char **argv);
int					ft_atoi(char *a);
int					ft_strlen(const char *c);
int					ft_atol(char *a);
void				eat_action(t_data *data, t_philo *philo);
void				eat2(t_data *data, t_philo *philo);
void				impr2(int action, t_philo *philo, t_data *data);
#endif
