/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:04:00 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/20 16:22:04 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*instructions;

	stack_a = process_args(argc, argv);
	stack_b = NULL;
	instructions = NULL;
	if (get_instructions(&instructions) == -1)
		return (process_exit(stack_a), 0);
	run_instructions(&stack_a, &stack_b, &instructions);
	ft_lstclear(&stack_a, &free);
	return (0);
}
