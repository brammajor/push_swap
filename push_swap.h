/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:39:06 by brmajor           #+#    #+#             */
/*   Updated: 2023/05/23 18:32:47 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct s_node
{	
	int				content;
	int				index;
	struct s_node	*next;
}					t_node;

int		check_dup(int ac, char **av);
int		check_int(int ac, char **av);
void	check_error(int ac, char **av);

t_node	*makestack2(t_node *astack, int ac, char **av);
t_node	*makestack(int ac, char **av);
void	printstack(t_node **astack);

void	give_index(t_node **astack);
int		new_min(t_node **astack, int min);

int		swap(t_node **head, char x);
int		pa(t_node **astack, t_node **bstack);
int		pb(t_node **astack, t_node **bstack);
int		rot(t_node **head, char x);
int		rerot(t_node **head, char x);

int		size_count(t_node **head);
void	sort_size(t_node **head, t_node **bstack);

int		is_sorted(t_node **head);
int		is_all_sorted(t_node **astack, t_node **bstack);
int		get_max(t_node **head);
int		get_min(t_node **head);

void	sort_2(t_node **head);
void	sort_3(t_node **head);
void	sort_4(t_node **head, t_node **bstack);
void	sort_5_part2(t_node **head, t_node **bstack);
void	sort_5(t_node **head, t_node **bstack);

void	chunks_to_b(t_node **head, t_node **bstack);
int		check_chunk(t_node **astack, int chunk);
int		rot_count(t_node **astack, int chunk);
int		rerot_count(t_node **astack, int chunk);
int		chunk_size(t_node **astack);

void	max_to_a(t_node **astack, t_node **bstack);
int		rot_or_rerot_b(t_node **bstack, int index);

void	free_memory(t_node **stack);

#endif
