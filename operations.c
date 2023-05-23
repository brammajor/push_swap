/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:32:55 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/18 15:36:14 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node **head, char x)
{
	t_node	*newhead;
	t_node	*node2;

	if (*head == NULL || (*head)->next == NULL)
		return (0);
	node2 = *head;
	newhead = node2->next;
	node2->next = newhead->next;
	newhead->next = node2;
	*head = newhead;
	if (x == 's')
		return (0);
	ft_printf("s%c\n", x);
	return (1);
}

int	pa(t_node **astack, t_node **bstack)
{
	t_node	*newhead;

	if (*bstack == NULL)
		return (0);
	newhead = *bstack;
	*bstack = newhead->next;
	newhead->next = *astack;
	*astack = newhead;
	ft_printf("pa\n");
	return (1);
}

int	pb(t_node **astack, t_node **bstack)
{
	t_node	*newhead;

	if (*astack == NULL)
		return (0);
	newhead = *astack;
	*astack = newhead->next;
	newhead->next = *bstack;
	*bstack = newhead;
	ft_printf("pb\n");
	return (1);
}

int	rot(t_node **head, char x)
{
	t_node	*curr;
	t_node	*newlast;

	curr = *head;
	newlast = *head;
	curr = curr->next;
	*head = curr;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = newlast;
	newlast->next = NULL;
	if (x == 'r')
		return (1);
	ft_printf("r%c\n", x);
	return (1);
}

int	rerot(t_node **head, char x)
{
	t_node	*curr;
	t_node	*prev;

	curr = *head;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = *head;
	*head = curr;
	prev->next = NULL;
	if (x == 'r')
		return (1);
	ft_printf("rr%c\n", x);
	return (1);
}
