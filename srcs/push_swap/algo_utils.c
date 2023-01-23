/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:18:23 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/23 18:15:18 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	*get_action(char *s, char *action, char *letter)
{
	ft_strlcpy(s, action, 4);
	ft_strlcat(s, letter, 4);
	return (s);
}

int	get_next_position(t_stack *stack, t_node *node)
{
	int	i;
	int	actual_position;
	int	lowest_position;

	i = 0;
	lowest_position = INT_MAX;
	actual_position = INT_MAX;
	stack->curr = stack->head;
	while (i < stack->size)
	{
		if (stack->curr->position < lowest_position)
			lowest_position = stack->curr->position;
		if (stack->curr->position > node->position
			&& stack->curr->position < actual_position)
			actual_position = stack->curr->position;
		stack->curr = stack->curr->next;
		i = i + 1;
	}
	if (i == 0)
		return (-1);
	if (actual_position == INT_MAX)
		return (lowest_position);
	return (actual_position);
}

void	place_node_to_top_by_pos(
	t_stack **stack,
	t_list **insts,
	int position,
	char *letter
) {
	int		i;
	t_node	*tail_curr;

	i = 0;
	(*stack)->curr = (*stack)->head;
	tail_curr = (*stack)->tail;
	while (i < ((*stack)->size))
	{
		if ((*stack)->curr->position == position)
			while (i-- > 0)
				call_instruction_with_stack(&*stack, &*insts, "r", letter);
		else if (tail_curr->position == position)
			while (1 + i-- > 0)
				call_instruction_with_stack(&*stack, &*insts, "rr", letter);
		if ((*stack)->curr->position == position
			|| tail_curr->position == position)
			return ;
		(*stack)->curr = (*stack)->curr->next;
		tail_curr = tail_curr->prev;
		i = i + 1;
	}
}

int	get_direction_by_pos(t_stack *stack, int position)
{
	int		i;
	t_node	*tail_curr;

	i = 0;
	stack->curr = stack->head;
	tail_curr = stack->tail;
	while (i < (stack->size))
	{
		if (stack->curr->position == position)
			return (1);
		else if (tail_curr->position == position)
			return (0);
		stack->curr = stack->curr->next;
		tail_curr = tail_curr->prev;
		i = i + 1;
	}
	return (1);
}
