/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:39:37 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/20 16:06:13 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	exec_instruction(
	t_list **stack_a,
	t_list **stack_b,
	char *instruction
) {
	if (ft_strncmp(instruction, "sa", 3) == 0)
		return (ft_swap(&*stack_a));
	else if (ft_strncmp(instruction, "sb", 3) == 0)
		return (ft_swap(&*stack_b));
	else if (ft_strncmp(instruction, "ss", 3) == 0)
		return (ft_swap(&*stack_a), ft_swap(&*stack_b));
	else if (ft_strncmp(instruction, "pa", 3) == 0)
		return (ft_push(&*stack_b, &*stack_a));
	else if (ft_strncmp(instruction, "pb", 3) == 0)
		return (ft_push(&*stack_a, &*stack_b));
	else if (ft_strncmp(instruction, "ra", 3) == 0)
		return (ft_rotate(&*stack_a));
	else if (ft_strncmp(instruction, "rb", 3) == 0)
		return (ft_rotate(&*stack_b));
	else if (ft_strncmp(instruction, "rr", 3) == 0)
		return (ft_rotate(&*stack_a), ft_rotate(&*stack_b));
	else if (ft_strncmp(instruction, "rra", 3) == 0)
		return (ft_rrotate(&*stack_a));
	else if (ft_strncmp(instruction, "rrb", 3) == 0)
		return (ft_rrotate(&*stack_b));
	else if (ft_strncmp(instruction, "rrr", 3) == 0)
		return (ft_rrotate(&*stack_a), ft_rotate(&*stack_b));
}
