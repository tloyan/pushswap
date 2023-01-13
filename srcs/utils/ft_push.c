/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:19:48 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/12 18:03:50 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	ft_push(t_stack **stack_src, t_stack **stack_dest)
{
	t_node	*tmp;

	if ((*stack_src)->size <= 0)
		return ;
	tmp = (*stack_src)->head;
	(*stack_src)->size = (*stack_src)->size - 1;
	if ((*stack_src)->size > 0)
	{
		(*stack_src)->head = (*stack_src)->head->next;
		(*stack_src)->head->prev = (*stack_src)->tail;
		(*stack_src)->tail->next = (*stack_src)->head;
	}
	(*stack_dest)->curr = (*stack_dest)->head;
	(*stack_dest)->head = tmp;
	if ((*stack_dest)->size <= 0)
	{
		(*stack_dest)->tail = (*stack_dest)->head;
		(*stack_dest)->curr = (*stack_dest)->head;
	}
	(*stack_dest)->head->next = (*stack_dest)->curr;
	(*stack_dest)->head->prev = (*stack_dest)->tail;
	(*stack_dest)->curr->prev = (*stack_dest)->head;
	(*stack_dest)->tail->next = (*stack_dest)->head;
	(*stack_dest)->size = (*stack_dest)->size + 1;
}
