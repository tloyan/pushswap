/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:02:14 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/20 19:48:45 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int	is_valid_instruction(char *instruction)
{
	const char	*possible_instructions[12] = {
		"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr", NULL
	};
	int			i;

	i = 0;
	while (possible_instructions[i] != NULL)
	{
		if (ft_strncmp(instruction, possible_instructions[i], 3) == 0)
			return (1);
		i = i + 1;
	}
	return (0);
}

int	get_instructions(t_list **instructions)
{
	char	*line;
	char	*instruction;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		instruction = ft_strtrim_end(line, "\n");
		if (is_valid_instruction(instruction))
			ft_lstadd_back(&*instructions, ft_lstnew(instruction));
		else
			return (
				free(line),
				free(instruction),
				ft_lstclear(&*instructions, &free), -1
			);
		free(line);
	}
	return (0);
}

void	run_instructions(
	t_list **stack_a,
	t_list **stack_b,
	t_list **instruction
) {
	t_list	*tmp;

	while (*instruction)
	{
		tmp = (*instruction)->next;
		exec_instruction(&*stack_a, &*stack_b, (*instruction)->content);
		free((*instruction)->content);
		free(*instruction);
		*instruction = tmp;
	}
}
