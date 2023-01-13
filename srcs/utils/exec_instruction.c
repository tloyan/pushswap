/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:39:37 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/13 12:16:34 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	exec_instruction(
	t_stack **a,
	t_stack **b,
	char *instruction
) {
	if (ft_strncmp(instruction, "sa", 3) == 0)
		return (ft_swap(&*a));
	else if (ft_strncmp(instruction, "sb", 3) == 0)
		return (ft_swap(&*b));
	else if (ft_strncmp(instruction, "ss", 3) == 0)
		return (ft_swap(&*a), ft_swap(&*b));
	else if (ft_strncmp(instruction, "pa", 3) == 0)
		return (ft_push(&*b, &*a));
	else if (ft_strncmp(instruction, "pb", 3) == 0)
		return (ft_push(&*a, &*b));
	else if (ft_strncmp(instruction, "ra", 3) == 0)
		return (ft_rotate(&*a));
	else if (ft_strncmp(instruction, "rb", 3) == 0)
		return (ft_rotate(&*b));
	else if (ft_strncmp(instruction, "rr", 3) == 0)
		return (ft_rotate(&*a), ft_rotate(&*b));
	else if (ft_strncmp(instruction, "rra", 3) == 0)
		return (ft_rrotate(&*a));
	else if (ft_strncmp(instruction, "rrb", 3) == 0)
		return (ft_rrotate(&*b));
	else if (ft_strncmp(instruction, "rrr", 3) == 0)
		return (ft_rrotate(&*a), ft_rotate(&*b));
}
