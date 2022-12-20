/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:02:14 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/20 15:12:01 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		line = ft_strtrim_end(line, "\n");
		if (is_valid_instruction(line))
			ft_lstadd_back(&*instructions, ft_lstnew(line));
		else
			return (ft_lstclear(&*instructions, &free), -1);
	}
	return (0);
}
