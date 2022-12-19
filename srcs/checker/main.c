/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:04:00 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/19 19:37:30 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 0;
	stack_a = process_args(argc, argv);
	stack_b = NULL;
	display_lst(stack_a);
	ft_putstr_fd("\n", 1);
	// ft_push(&stack_a, &stack_b);
	ft_rrotate(&stack_a);
	display_lst(stack_a);
	ft_putstr_fd("\n", 1);
	// display_lst(stack_b);
	ft_lstclear(&stack_a, &free);
	return (0);
}
