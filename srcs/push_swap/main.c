/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:20:57 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/27 14:14:21 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	display_stack(t_stack	*stack)
{
	int	i;

	i = 0;
	stack->curr = stack->head;
	while (i++ < stack->size)
	{
		printf("value: %d\n", stack->curr->value);
		printf("position: %d\n\n", stack->curr->position);
		stack->curr = stack->curr->next;
	}
}

void	display_stack_from_end(t_stack	*stack)
{
	int	i;

	i = 0;
	stack->curr = stack->tail;
	while (i++ < stack->size)
	{
		printf("value: %d\n", stack->curr->value);
		printf("position: %d\n\n", stack->curr->position);
		stack->curr = stack->curr->prev;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*instructions;

	if (argc == 1)
		return (0);
	a = process_args(argc, argv);
	b = init_stack();
	instructions = NULL;
	if (a->size < 4)
		algo_3(&a, &b, &instructions);
	else if (a->size < 6)
		algo_5(&a, &b, &instructions);
	else
		algo(&a, &b, &instructions);
	opti(&instructions);
	display_instructions(instructions);
	clear_stack(a);
	clear_stack(b);
	return (0);
}
