/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_A.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:58:46 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/23 15:26:37 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_to_A(t_node **astack, t_node **bstack)
{
	int	index;

	index = size_count(bstack) - 1;
	while (*bstack)
	{
		if (rot_or_rerot_B(bstack, index))
		{
			while ((*bstack)->index != index)
				rot(bstack, 'b');
		}
		else
		{
			while ((*bstack)->index != index)
				rerot(bstack, 'b');
		}
		pa(astack, bstack);
		index--;
	}
}

int	rot_or_rerot_B(t_node **bstack, int index)
{
	t_node	*curr;
	int		op_count;

	curr = *bstack;
	op_count = 0;
	while (curr->index != index)
	{
		curr = curr->next;
		op_count++;
	}
	if (op_count < size_count(bstack) / 2)
		return (1);
	else
		return (0);
}

