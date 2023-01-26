/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:10:27 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/26 14:08:59 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	prefilter(t_stack **a, t_stack **b, t_list **instructions, int size)
{
	t_node	*node;

	node = (*a)->head;
	while ((*a)->size > 3)
	{
		if (node->position < (size - 3))
			call_instruction(&*a, &*b, &*instructions, "pb");
		if (node->position < (size - 3) && node->position < (size / 2))
			call_instruction(&*a, &*b, &*instructions, "rb");
		if (node->position >= (size - 3))
			call_instruction(&*a, &*b, &*instructions, "ra");
		node = (*a)->head;
	}
}

int	get_r_cost_by_p(t_stack *stack, int position)
{
	int		i;
	t_node	*tail_curr;
	t_node	*curr;

	i = 0;
	curr = stack->head;
	tail_curr = stack->tail;
	while (i < (stack->size))
	{
		if (curr->position == position)
			return (i);
		else if (tail_curr->position == position)
			return (1 + i);
		curr = curr->next;
		tail_curr = tail_curr->prev;
		i = i + 1;
	}
	return (-1);
}

int	is_same_direction(t_stack *stack, int pos, int i, int size)
{
	if (i < ((size / 2)) && get_direction_by_pos(stack, pos) == 1)
		return (1);
	if (i >= ((size / 2)) && get_direction_by_pos(stack, pos) == 0)
		return (1);
	return (0);
}

int	get_lowest_cost_node(t_stack **a, t_stack **b)
{
	int	i;
	int	next_pos;
	int	lowest_cost;
	int	curr_cost;
	int	pos_lowest_cost;

	i = 0;
	lowest_cost = INT_MAX;
	(*b)->curr = (*b)->head;
	while (i++ < (*b)->size)
	{
		next_pos = get_next_position(*a, (*b)->curr);
		curr_cost = get_r_cost_by_p(*a, next_pos);
		if (is_same_direction(*a, next_pos, i, (*b)->size) == 0)
			curr_cost = curr_cost + get_r_cost_by_p(*b, (*b)->curr->position);
		else if (get_r_cost_by_p(*b, (*b)->curr->position) > curr_cost)
			curr_cost = get_r_cost_by_p(*b, (*b)->curr->position);
		if (curr_cost < lowest_cost)
		{
			lowest_cost = curr_cost;
			pos_lowest_cost = (*b)->curr->position;
		}
		(*b)->curr = (*b)->curr->next;
	}
	return (pos_lowest_cost);
}

void	algo(t_stack **a, t_stack **b, t_list **instructions)
{
	int	next_pos;

	prefilter(&*a, &*b, &*instructions, (*a)->size);
	algo_3(&*a, &*b, &*instructions);
	while ((*b)->size > 0)
	{
		next_pos = get_lowest_cost_node(&*a, &*b);
		place_node_to_top_by_pos(&*b, &*instructions, next_pos, "b");
		next_pos = get_next_position(*a, (*b)->head);
		if (next_pos > -1)
			place_node_to_top_by_pos(&*a, &*instructions, next_pos, "a");
		call_instruction(&*a, &*b, &*instructions, "pa");
	}
	place_node_to_top_by_pos(&*a, &*instructions, 0, "a");
}
