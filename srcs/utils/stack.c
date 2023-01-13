/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:35:44 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/13 12:12:47 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->curr = NULL;
	stack->size = 0;
	return (stack);
}

void	insert_at_begin(t_stack **stack, t_node **node)
{
	if ((*stack)->size == 0)
	{
		(*node)->prev = *node;
		(*node)->next = *node;
		(*stack)->head = *node;
		(*stack)->tail = *node;
		(*stack)->curr = *node;
		(*stack)->size = 1;
		return ;
	}
	(*node)->prev = (*stack)->tail;
	(*node)->next = (*stack)->head;
	(*stack)->head->prev = (*node);
	(*stack)->tail->next = (*node);
	(*stack)->head = (*node);
	(*stack)->curr = (*node);
	(*stack)->size = (*stack)->size + 1;
}

void	insert_at_end(t_stack **stack, t_node **node)
{
	if ((*stack)->size == 0)
	{
		(*node)->prev = *node;
		(*node)->next = *node;
		(*stack)->head = *node;
		(*stack)->tail = *node;
		(*stack)->curr = *node;
		(*stack)->size = 1;
		return ;
	}
	(*node)->prev = (*stack)->tail;
	(*node)->next = (*stack)->head;
	(*stack)->head->prev = (*node);
	(*stack)->tail->next = (*node);
	(*stack)->tail = (*node);
	(*stack)->size = (*stack)->size + 1;
}

t_node	*create_stack_node(int value, int position)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->position = position;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	clear_stack(t_stack	*stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	stack->curr = stack->head;
	while (i++ < stack->size)
	{
		tmp = stack->curr->next;
		free(stack->curr);
		stack->curr = tmp;
	}
	free(stack);
}
