/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:29:05 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/21 19:35:55 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	set_min_max(t_list *stack, int *min, int *max)
{
	while (stack)
	{
		if (((t_data *)stack->content)->number < *min)
			*min = ((t_data *)stack->content)->number;
		if (((t_data *)stack->content)->number > *max)
			*max = ((t_data *)stack->content)->number;
		stack = stack->next;
	}
}

void	algo_3(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		min;
	int		max;

	min = INT_MAX;
	max = INT_MIN;
	set_min_max(*stack_a, &min, &max);
	if (((t_data *)(*stack_a)->content)->number == max)
		call_instruction(&*stack_a, &*stack_b, "ra");
	last = ft_lstlast(*stack_a);
	if (((t_data *)last->content)->number != max)
		call_instruction(&*stack_a, &*stack_b, "rra");
	if (((t_data *)(*stack_a)->content)->number != min)
		call_instruction(&*stack_a, &*stack_b, "sa");
}

int	get_rcost_move(t_list *stack_a, int nb)
{
	int	len;
	int	rcost;

	len = ft_lstsize(stack_a);
	rcost = 0;
	while (stack_a)
	{
		if (nb > ((t_data *)stack_a->content)->number)
			rcost = rcost + 1;
		stack_a = stack_a->next;
	}
	return (rcost - (len / 2));
}

void	special_move(t_list **stack_a, t_list **stack_b)
{
	int			i;
	int			rcost;
	const char	*moves[3] = {"rra", "ra"};
	int			move_i;

	move_i = 0;
	rcost = get_rcost_move(*stack_a, ((t_data *)(*stack_b)->content)->number);
	if (rcost < 0)
	{
		rcost = rcost * -1;
		move_i = 1;
	}
	i = -1;
	while (++i < rcost)
		call_instruction(&*stack_a, &*stack_b, (char *)moves[move_i]);
	call_instruction(&*stack_a, &*stack_b, "pa");
	while (i-- > -1 + move_i)
		call_instruction(&*stack_a, &*stack_b, (char *)moves[(move_i + 1) % 2]);
}

void	algo_5(t_list **stack_a, t_list **stack_b)
{
	int		len;
	int		i;

	len = ft_lstsize(*stack_a);
	i = -1;
	while (len - ++i > 3)
		call_instruction(&*stack_a, &*stack_b, "pb");
	algo_3(&*stack_a, &*stack_b);
	while (--i > -1)
	{
		if (((t_data *)(*stack_b)->content)->number
			< ((t_data *)(*stack_a)->content)->number)
			call_instruction(&*stack_a, &*stack_b, "pa");
		else if (((t_data *)(*stack_b)->content)->number
			> ((t_data *)(ft_lstlast(*stack_a))->content)->number)
		{
			call_instruction(&*stack_a, &*stack_b, "pa");
			call_instruction(&*stack_a, &*stack_b, "ra");
		}
		else
			special_move(&*stack_a, &*stack_b);
	}
}
