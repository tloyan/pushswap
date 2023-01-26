/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:07:30 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/26 10:06:46 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	ft_rotate(t_stack **stack)
{
	if ((*stack)->size < 2)
		return ;
	(*stack)->curr = (*stack)->head->next;
	(*stack)->tail = (*stack)->head;
	(*stack)->head = (*stack)->curr;
}
