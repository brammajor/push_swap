/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:40:36 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/10 15:49:31 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **head)
{
	t_node	*curr;

	curr = *head;
	while (curr->next != NULL)
	{
		if (curr->content > curr->next->content)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	is_all_sorted(t_node **astack, t_node **bstack)
{
	t_node	*curr;

	if (*bstack != NULL)
		return (1);
	curr = *astack;
	while (curr->next != NULL)
	{
		if (curr->content > curr->next->content)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	get_max(t_node **head)
{
	t_node	*curr;
	int		curr_num;
	int		biggest;

	curr = *head;
	biggest = curr->content;
	while (curr->next != NULL)
	{
		curr = curr->next;
		curr_num = curr->content;
		if (curr_num > biggest)
			biggest = curr_num;
	}
	return (biggest);
}

int	get_min(t_node **head)
{
	t_node	*curr;
	int		curr_num;
	int		smallest;

	curr = *head;
	smallest = curr->content;
	while (curr->next != NULL)
	{
		curr = curr->next;
		curr_num = curr->content;
		if (curr_num < smallest)
			smallest = curr_num;
	}
	return (smallest);
}
