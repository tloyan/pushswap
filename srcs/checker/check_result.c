/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:05:16 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/13 12:20:23 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include <limits.h>

void	check_result(t_stack **a, t_stack **b)
{
	int		max;
	int		valid;
	int		i;

	max = INT_MIN;
	valid = 1;
	if ((*b)->size != 0)
		valid = 0;
	(*a)->curr = (*a)->head;
	i = 0;
	while (i < (*a)->size)
	{
		if ((*a)->curr->position < max)
			valid = 0;
		max = (*a)->curr->position;
		(*a)->curr = (*a)->curr->next;
		i = i + 1;
	}
	clear_stack(*a);
	clear_stack(*b);
	if (valid)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
