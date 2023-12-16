/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:21:27 by ale-tron          #+#    #+#             */
/*   Updated: 2023/12/16 17:57:36 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc == 1)
		return (0);
//	printf("%d", argc);
	if (ft_check_error(argc, argv))
		return (ft_putstr_fd("Error\n", 1), 0);
	return (0);
}
