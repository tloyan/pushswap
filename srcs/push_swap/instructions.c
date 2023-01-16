/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:46:50 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/16 16:49:04 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	call_instruction(
	t_stack **a,
	t_stack **b,
	t_list **instructions,
	char *instruction
) {
	t_list	*node;
	char	*instruction_cpy;

	exec_instruction(&*a, &*b, instruction);
	instruction_cpy = ft_strdup(instruction);
	node = ft_lstnew(instruction_cpy);
	if (instruction_cpy == NULL || node == NULL)
		return (free(instruction_cpy), free(node),
			ft_lstclear(&*instructions, &free),
			clear_stack(*a), clear_stack(*b), exit(-1));
	ft_lstadd_back(&*instructions, node);
}

void	call_instruction_with_stack(
	t_stack **stack,
	t_list **inst,
	char *action,
	char *letter
) {
	char	s[3];

	if (letter[0] == 'a')
	{
		call_instruction(&*stack, NULL, &*inst, get_action(s, action, letter));
		return ;
	}
	call_instruction(NULL, &*stack, &*inst, get_action(s, action, letter));
}

void	display_instructions(t_list *instruction)
{
	t_list	*tmp;

	while (instruction)
	{
		tmp = instruction->next;
		ft_putendl_fd(instruction->content, 1);
		free(instruction->content);
		free(instruction);
		instruction = tmp;
	}
}
