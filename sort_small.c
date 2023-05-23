/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:19:18 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/18 15:50:53 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_2(t_node **astack)
{
	if (!is_sorted(astack))
		return (0);
	rot(astack, 'a');
	return (1);
}

int	sort_3(t_node **astack)
{
	t_node	*curr;
	int		op_count;
	
	if (!is_sorted(astack))
		return (0);
	curr = *astack;
	op_count = 0;
	if (curr->content == get_max(astack))
	{
		op_count = op_count + rot(astack, 'a');
		if (is_sorted(astack))
			op_count = op_count + swap(astack, 'a');
	}
	else if (curr->content == get_min(astack))
	{
		op_count = op_count + swap(astack, 'a');
		op_count = op_count + rot(astack, 'a');
	}
	else if (curr->next->content == get_max(astack))
		op_count = op_count + rerot(astack, 'a');
	else if (curr->next->content == get_min(astack))
		op_count = op_count + swap(astack, 'a');
	return (op_count);
}

int	sort_4(t_node **astack, t_node **bstack)
{
	int	max;
	int	op_count;

	if (!is_all_sorted(astack, bstack))
		return (0);
	max = get_max(astack);
	op_count = 0;
	op_count = op_count + pb(astack, bstack);
	op_count = op_count + sort_3(astack);
	while (*bstack != NULL)
	{
		if ((*bstack)->content == max)
		{
			op_count = op_count + pa(astack, bstack);
			op_count = op_count + rot(astack, 'a');
			return (op_count);
		}
		else if ((*astack)->content > (*bstack)->content)
		{
			op_count = op_count + pa(astack, bstack);
			break ;
		}
		op_count = op_count + rot(astack, 'a');
	}
	while (is_all_sorted(astack, bstack))
			op_count = op_count + rerot(astack, 'a');
	return (op_count);
}

void	sort_5(t_node **astack, t_node **bstack)
{
	int	count;
	int	min;
	int	max;

	if (!is_all_sorted(astack, bstack))
		return ;
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
	sort_3(astack);
	if (is_sorted(bstack))
		swap(bstack, 'b');
	pa(astack, bstack);
	pa(astack, bstack);
	rot(astack, 'a');
}
