/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:28:36 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/12 18:09:08 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	ft_rrotate(t_stack **stack)
{
	if ((*stack)->size < 2)
		return ;
	(*stack)->curr = (*stack)->tail->prev;
	(*stack)->head = (*stack)->tail;
	(*stack)->tail = (*stack)->curr;
	(*stack)->curr = (*stack)->tail;
}
