/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:45:21 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/26 12:33:45 by brmajor          ###   ########.fr       */
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
	give_index(&astack);
	sort_size(&astack, &bstack);
	if (is_all_sorted(&astack, &bstack))
		printstack(&astack);
	free_memory(&astack);
	free_memory(&bstack);
}
