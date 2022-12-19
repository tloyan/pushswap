/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:26:13 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/19 16:13:53 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	process_exit(t_list *lst)
{
	ft_lstclear(&lst, &free);
	ft_putstr_fd("Error\n", 1);
	exit(-1);
}
