/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:37:00 by amile-ge          #+#    #+#             */
/*   Updated: 2024/03/01 18:49:42 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_piece
{
	int				value;
	int				index;
	struct s_piece	*next;
}					t_piece;

typedef struct s_stack
{
	t_piece			*first;
	t_piece			*last;
	int				len;
}					t_stack;

int					ft_check_args(int argc, char **argv);
int					ft_num(char *argv);
int					ft_dup(int argc, char **argv);
int					ft_atoi(char *a);
void				ft_initstack(t_stack *map);
void				fill_stack_a(t_stack *stack, char **argv);
void				fill_index(t_stack *stack);
int					check_if_ordered(t_stack *stack_a);
void				ordenar(t_stack *stack_a, t_stack *stack_b, int argc);
void				swap(t_stack *stackx);
void				sa(t_stack *stacka);
void				sb(t_stack *stackb);
void				ss(t_stack *stacka, t_stack *stackb);
void				push(t_stack **stackfrom, t_stack **stackto);
void				pa(t_stack *stacka, t_stack *stackb);
void				pb(t_stack *stacka, t_stack *stackb);
void				ordtres(t_stack *stack_a, int lent);
void				small_sort(t_stack *stack_a, t_stack *stack_b, int lent,
						int smalle);
void				rotate(t_stack *stackx);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				reverse(t_stack *stack_a);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);
void				print_stacks(t_stack *stack_a, t_stack *stack_b);
int					bigger(t_stack *stackx);
int					smaller(t_stack *stackx);
void				chunks_ord(t_stack *stack_a, t_stack *stack_b, int lent);
int					cost(t_stack *stackx, int smalle, char type);
int					len(t_stack *stackx);
int					divlent(int lent, int *divl);
int					big_sort(t_stack *stackx, int lent, int smalle);
void				free_stacks(t_stack *stack_a, t_stack *stack_b);
int					ft_strlen(const char *c);
int					smaller_cost(t_stack *stackx, int num, int chunks);
int					count_mov(t_piece *templ, t_piece *tempf, int smalle,
						int x);
void				searchsmaller(t_piece *temp, int smaller_c,
						int temp_smaller, int indext);

void				return_ordered(int lent, t_stack *stack_a,
						t_stack *stack_b);
void				check_a(t_stack *stack_a, t_stack *stack_b, int lent);
int					div_500(int lent, int *chunk);
void				rev_2(t_stack *stackx);
void				final_ord(int lent, t_stack *stack_a, t_stack *stack_b);
int					ft_atol(char *a);
#endif
