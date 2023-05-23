/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:19:19 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/10 15:23:45 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		if (av[j][i] == '-')
			i++;
		while (av[j][i] != '\0')
		{
			if (!ft_isdigit(av[j][i]))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_dup(int ac, char **av)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 1;
	j = 2;
	while (av[i])
	{
		while (j < ac)
		{
			num1 = ft_atoi(av[i]);
			num2 = ft_atoi(av[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

void	check_error(int ac, char **av)
{
	if (check_int(ac, av) || check_dup(ac, av))
	{
		write(1, "Error\n", 6);
		exit (1);
	}
}		
