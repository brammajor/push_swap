/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:10:16 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/22 18:32:02 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*makestack(int ac, char **av)
{
	t_node	*astack;
	t_node	*newnode;
	t_node	*curr;
	int		i;

	if (ac <= 1)
		exit (1);
	i = 0;
	astack = NULL;
	curr = NULL;
	while (++i < ac)
	{
		newnode = (t_node *)malloc(sizeof(t_node));
		newnode->content = ft_atoi(av[i]);
		newnode->next = NULL;
		if (astack == NULL)
		{
			astack = newnode;
			curr = astack;
		}
		else
		{
			curr->next = newnode;
			curr = newnode;
		}
	}
	return (astack);
}

void	printstack(t_node **astack)
{
	t_node	*curr;

	curr = *astack;
	while (curr != NULL)
	{

		ft_printf("index:%d\n", curr->index);
		curr = curr->next;
	}
}
