/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:19:50 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/23 15:58:27 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunks_to_B(t_node **astack, t_node **bstack)
{
	int	OG_chunk;
	int	newchunk;
	int	rotcount;
	int	rerotcount;

	OG_chunk = chunk_size(astack);
	newchunk = 0;
	if (!is_all_sorted(astack, bstack))
		return ;
	while (*astack)
	{
		if (check_chunk(astack, newchunk))
			newchunk = newchunk + OG_chunk;
		rotcount = rot_count(astack, newchunk);
		rerotcount = rerot_count(astack, newchunk);
		if (rotcount < rerotcount)
		{
			while (rotcount-- != 0)
				rot(astack, 'a');
		}
		else
		{
			while (rerotcount-- != 0)
				rerot(astack, 'a');
		}
		pb(astack, bstack);
	}
}

int	check_chunk(t_node **astack, int chunk)
{
	t_node	*curr;

	curr = *astack;
	while (curr)
	{
		if (curr->index < chunk)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	rot_count(t_node **astack, int chunk)
{
	t_node	*curr;
	int		rotcount;
	curr = *astack;
	rotcount = 0;
	while (curr)
	{
		if (curr->index < chunk)
			break ;
		rotcount++;
		curr = curr->next;
	}
	return (rotcount);
}

int	rerot_count(t_node **astack, int chunk)
{
	t_node	*curr;
	int		rerotcount;
	int		tracker;

	curr = *astack;
	tracker = 0;
	while (curr)
	{
		if (curr->index < chunk)
			rerotcount = tracker;
		tracker++;
		curr = curr->next;
	}
	return (size_count(astack) - rerotcount);
}

int	chunk_size(t_node **astack)
{
	int	chunk;
	int	size;

	size = size_count(astack);
	if (size <= 100)
		chunk = size / 5;
	else
		chunk = size / 13;
	return (chunk);
}
