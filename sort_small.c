/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:19:18 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/23 18:18:15 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **astack)
{
	rot(astack, 'a');
}

void	sort_3(t_node **astack)
{
	t_node	*curr;

	curr = *astack;
	if (curr->content == get_max(astack))
	{
		rot(astack, 'a');
		if (is_sorted(astack))
			swap(astack, 'a');
	}
	else if (curr->content == get_min(astack))
	{
		swap(astack, 'a');
		rot(astack, 'a');
	}
	else if (curr->next->content == get_max(astack))
		rerot(astack, 'a');
	else if (curr->next->content == get_min(astack))
		swap(astack, 'a');
}

void	sort_4(t_node **astack, t_node **bstack)
{
	int	max;

	max = get_max(astack);
	pb(astack, bstack);
	sort_3(astack);
	while (*bstack != NULL)
	{
		if ((*bstack)->content == max)
		{
			pa(astack, bstack);
			rot(astack, 'a');
		}
		else if ((*astack)->content > (*bstack)->content)
		{
			pa(astack, bstack);
			break ;
		}
		rot(astack, 'a');
	}
	while (is_all_sorted(astack, bstack))
		rerot(astack, 'a');
}

void	sort_5_part2(t_node **astack, t_node **bstack)
{
	sort_3(astack);
	if (is_sorted(bstack))
		swap(bstack, 'b');
	pa(astack, bstack);
	pa(astack, bstack);
	rot(astack, 'a');
}

void	sort_5(t_node **astack, t_node **bstack)
{
	int	count;
	int	min;
	int	max;

	count = 0;
	min = get_min(astack);
	max = get_max(astack);
	while (count < 2)
	{
		if ((*astack)->content == min || (*astack)->content == max)
		{
			pb(astack, bstack);
			count++;
			if ((*astack)->content == min || (*astack)->content == max)
			{
				pb(astack, bstack);
				count++;
			}
			if (count == 2)
				break ;
		}
		rot(astack, 'a');
	}
	sort_5_part2(astack, bstack);
}
