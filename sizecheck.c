/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:21:25 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/23 18:39:33 by brmajor          ###   ########.fr       */
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

void	sort_size(t_node **astack, t_node **bstack)
{
	int	size;

	size = size_count(astack);
	if (!is_all_sorted(astack, bstack))
		exit (0);
	if (size == 2)
		rot(astack, 'a');
	else if (size == 3)
		sort_3(astack);
	else if (size == 4)
		sort_4(astack, bstack);
	else if (size == 5)
		sort_5(astack, bstack);
	else if (size > 5)
	{
		chunks_to_b(astack, bstack);
		max_to_a(astack, bstack);
	}	
}
