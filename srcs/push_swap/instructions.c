/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:46:50 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/21 15:49:55 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	call_instruction(t_list **stack_a, t_list **stack_b, char *instruction)
{
	exec_instruction(&*stack_a, &*stack_b, instruction);
	ft_putendl_fd(instruction, 1);
}
