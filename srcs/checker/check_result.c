/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:05:16 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/21 14:07:16 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include <limits.h>

void	check_result(t_list **stack_a, t_list **stack_b)
{
	int		max;
	int		valid;
	int		stack_b_len;
	t_list	*lst;

	max = INT_MIN;
	valid = 1;
	stack_b_len = ft_lstsize(*stack_b);
	if (stack_b_len != 0)
		valid = 0;
	lst = *stack_a;
	while (lst && valid)
	{
		if (((t_data *)lst->content)->number < max)
			valid = 0;
		max = ((t_data *)lst->content)->number;
		lst = lst->next;
	}
	ft_lstclear(&*stack_a, &free);
	ft_lstclear(&*stack_b, &free);
	if (valid)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
