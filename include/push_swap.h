/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:31:35 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/11 16:16:03 by ale-tron         ###   ########.fr       */
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
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

int		error_duplicate(t_stack *stack);
int		error_syntax(char **argv);
int		check_sorted(t_stack *stack);
void	ft_error(void);
void	free_stack(t_stack **stack);

t_stack	*find_last_node(t_stack *node);
t_stack	*find_node_max(t_stack *node);

void	print_stack(t_stack *node_a);
void	print_stack_rev(t_stack *node_a);



void	fill_stack(t_stack **node_a, char **argv);
void	sort_three(t_stack **stack);

void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);

void	ft_rra(t_stack **a);

#endif
