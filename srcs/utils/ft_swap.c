/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:39:54 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/12 19:25:15 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	ft_swap(t_stack **stack)
{
	(*stack)->curr = (*stack)->head;
	if ((*stack)->curr != NULL && (*stack)->curr->next != NULL)
	{
		(*stack)->curr->prev = (*stack)->curr->next;
		(*stack)->curr->next->next->prev = (*stack)->curr;
		(*stack)->curr->next = (*stack)->curr->next->next;
		(*stack)->curr->prev->next = (*stack)->curr;
		(*stack)->curr->prev->prev = (*stack)->tail;
		(*stack)->curr = (*stack)->curr->prev;
		(*stack)->head = (*stack)->curr;
	}
}
