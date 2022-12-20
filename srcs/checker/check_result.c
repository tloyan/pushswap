/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:05:16 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/20 16:50:06 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	check_result(t_list **stack_a, t_list **stack_b)
{
	int		max;
	int		valid;
	int		stack_b_len;

	max = 0;
	valid = 1;
	stack_b_len = ft_lstsize(*stack_b);
	if (stack_b_len != 0)
		valid = 0;
	while (*stack_a && valid)
	{
		if (((t_data *)(*stack_a)->content)->number < max)
			valid = 0;
		max = ((t_data *)(*stack_a)->content)->number;
		*stack_a = (*stack_a)->next;
	}
	ft_lstclear(&*stack_a, &free);
	ft_lstclear(&*stack_b, &free);
	if (valid)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
