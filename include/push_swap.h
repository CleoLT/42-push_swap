/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:31:35 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/24 19:14:47 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				above_median;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

int		error_int(char **argv);
int		error_duplicate(t_stack *stack);
int		error_syntax(char **argv);
void	ft_error(void);
void	free_stack(t_stack **stack);

int		check_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
t_stack	*find_last_node(t_stack *node);
t_stack	*find_node_max(t_stack *node);
t_stack	*find_node_min(t_stack *node);

void	set_index(t_stack *stack);
t_stack	*get_cheapest(t_stack *node);
void	cheapest_on_top(t_stack **stack, t_stack *cheapest, char stack_name);
void	min_on_top(t_stack **stack);

void	fill_stack(t_stack **node_a, char **argv);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	set_cost(t_stack *stack_a, t_stack *stack_b);

void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_pb(t_stack **src_a, t_stack **dest_b);
void	ft_pa(t_stack **src_b, t_stack **dest_a);
void	sort_three(t_stack **stack);

void	print_stack(t_stack *node_a, char *str);
void	print_stack_rev(t_stack *node_a, char *str);
void	print_target(t_stack *stack, char *str);
void	print_above_median(t_stack *stack, char *str);
void	print_index(t_stack *stack, char *str);
void	print_cost(t_stack *stack, char *str);

#endif
