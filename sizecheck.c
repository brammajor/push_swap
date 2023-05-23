/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:21:25 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/23 18:02:27 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_count(t_node **head)
{
	int		size;
	t_node	*curr;

	curr = *head;
	size = 1;
	while (curr->next != NULL)
	{
		curr = curr->next;
		size++;
	}
	return (size);
}

int	sort_size(t_node **astack, t_node **bstack)
{
	int	size;
	int	op_count;

	(void)bstack;
	size = size_count(astack);
	op_count = 0;
	if (!is_all_sorted(astack, bstack))
		exit (1);
	if (size == 2)
		op_count = rot(astack, 'a');
	else if (size == 3)
		op_count = sort_3(astack);
	else if (size == 4)
		op_count = sort_4(astack, bstack);
	else if (size == 5)
		sort_5(astack, bstack);
	else if (size > 5)
	{
		chunks_to_b(astack, bstack);
		max_to_a(astack, bstack);
	}	
	return (op_count);
}
