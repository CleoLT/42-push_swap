/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:21:27 by ale-tron          #+#    #+#             */
/*   Updated: 2024/01/05 16:31:25 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*node_a;

	node_a = NULL;
	if (argc == 1)
		return (0);
	if (error_syntax(argv))
		ft_error();
	fill_stack(&node_a, argv);
	if (error_duplicate(node_a))
	{	
		free_stack(&node_a);
		ft_error();
	}
//    while(node_a)
//    {
//        printf("main: %d\n", node_a->value);
//        node_a = node_a->next;
//    }
	if (check_sorted(node_a))
		printf("not sorted");
	free_stack(&node_a);
	return (0);
}
