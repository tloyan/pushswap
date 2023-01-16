/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:29:05 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/16 16:23:19 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	set_min_max(t_stack *stack, int *min, int *max)
{
	int	i;

	i = 0;
	stack->curr = stack->head;
	while (i++ < stack->size)
	{
		if (stack->curr->value < *min)
			*min = stack->curr->value;
		if (stack->curr->value > *max)
			*max = stack->curr->value;
		stack->curr = stack->curr->next;
	}
}

void	algo_3(t_stack **a, t_stack **b, t_list **instructions)
{
	int		min;
	int		max;

	min = INT_MAX;
	max = INT_MIN;
	set_min_max(*a, &min, &max);
	if ((*a)->head->value == max)
		call_instruction(&*a, &*b, &*instructions, "ra");
	if ((*a)->tail->value != max)
		call_instruction(&*a, &*b, &*instructions, "rra");
	if ((*a)->head->value != min)
		call_instruction(&*a, &*b, &*instructions, "sa");
}

void	algo_5(t_stack **a, t_stack **b, t_list **instructions)
{
	int	next_pos;

	while ((*a)->size > 3)
		call_instruction(&*a, &*b, &*instructions, "pb");
	algo_3(&*a, &*b, &*instructions);
	while ((*b)->size > 0)
	{
		next_pos = get_next_position(*a, (*b)->head);
		if (next_pos > -1)
			place_node_to_top_by_pos(&*a, &*instructions, next_pos, "a");
		call_instruction(&*a, &*b, &*instructions, "pa");
	}
	place_node_to_top_by_pos(&*a, &*instructions, 0, "a");
}
