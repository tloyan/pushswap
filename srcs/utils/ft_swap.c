/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:39:54 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/26 14:13:19 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	ft_swap(t_stack **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*tmp;

	(*stack)->curr = (*stack)->head;
	if ((*stack)->curr != NULL && (*stack)->curr->next != NULL)
	{
		tmp = (*stack)->curr->next->next;
		first = (*stack)->curr->next;
		second = (*stack)->curr;
		first->prev = (*stack)->tail;
		(*stack)->tail->next = first;
		first->next = second;
		second->prev = first;
		second->next = tmp;
		tmp->prev = second;
		(*stack)->head = first;
	}
}
