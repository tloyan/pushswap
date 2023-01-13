/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:26:13 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/12 12:02:55 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	process_exit(t_stack *a, t_stack *b)
{
	if (a != NULL)
		clear_stack(a);
	if (b != NULL)
		clear_stack(b);
	ft_putstr_fd("Error\n", 1);
	exit(-1);
}
