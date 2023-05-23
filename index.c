/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:17:08 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/18 14:44:43 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_index(t_node **astack)
{
	t_node	*curr;
	int		index;
	int		min;

	curr = *astack;
	index = 0;
	min = get_min(astack);
	while (index < size_count(astack))
	{
		while (curr != NULL)
		{
			if (curr->content == min)
			{
				curr->index = index;
				index++;
				min = new_min(astack, min);
			}
			curr = curr->next;
		}
		curr = *astack;
	}
}

int	new_min(t_node **astack, int min)
{
	t_node	*curr;
	int		newmin;

	curr = *astack;
	newmin = 2147483647;
	while (curr != NULL)
	{
		if (curr->content < newmin && curr->content > min)
			newmin = curr->content;
		curr = curr->next;
	}
	return (newmin);
}
