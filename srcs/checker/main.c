/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:04:00 by thloyan           #+#    #+#             */
/*   Updated: 2023/05/25 13:14:13 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*instructions;

	a = process_args(argc, argv);
	if (a == NULL)
		return (-1);
	b = init_stack();
	if (b == NULL)
		return (clear_stack(a), -1);
	instructions = NULL;
	if (get_instructions(&instructions) == -1)
		return (process_exit(a, b), -1);
	run_instructions(&a, &b, &instructions);
	check_result(&a, &b);
	return (0);
}
