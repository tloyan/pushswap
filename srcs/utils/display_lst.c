/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:01:44 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/20 15:18:21 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	display_lst(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		ft_putstr_fd("content element n ", 1);
		ft_putnbr_fd(i++, 1);
		ft_putstr_fd(" => ", 1);
		ft_putnbr_fd(((t_data *)lst->content)->number, 1);
		ft_putstr_fd("\n", 1);
		lst = lst->next;
	}
}
