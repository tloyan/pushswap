/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:20:57 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/21 19:36:15 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		len;

	stack_a = process_args(argc, argv);
	stack_b = NULL;
	len = ft_lstsize(stack_a);
	if (len < 4)
		algo_3(&stack_a, &stack_b);
	else if (len < 6)
		algo_5(&stack_a, &stack_b);
	ft_lstclear(&stack_a, &free);
	return (0);
}
