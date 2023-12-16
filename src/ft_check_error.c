/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:17:57 by ale-tron          #+#    #+#             */
/*   Updated: 2023/12/16 16:29:47 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

static int	ft_check_int(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		if (!(ft_atoi(argv[i]) <= INT_MAX))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_error(int argc, char **argv)
{
	if (argc < 3)
		return (-1);
	if (ft_check_int(argv))
		return (-1);
	return (0);
}
