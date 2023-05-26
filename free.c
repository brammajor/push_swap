/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:23:27 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/26 12:33:22 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_memory(t_node **stack)
{
	t_node	*curr;

	while (*stack)
	{
		curr = *stack;
		*stack = (*stack)->next;
		free(curr);
	}
}
