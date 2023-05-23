/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:45:21 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/23 15:29:39 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*astack;
	t_node	*bstack;

	check_error(ac, av);
	astack = makestack(ac, av);
	bstack = NULL;
	if (is_sorted(&astack) == 0)
	{
		printstack(&astack);
		return (0);
	}
	give_index(&astack);
	//printstack(&astack);
	sort_size(&astack, &bstack);
	//printstack(&astack);
	//ft_printf("\n");
	//if (is_all_sorted(&astack, &bstack))
		printstack(&bstack);
}
