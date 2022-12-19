/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:19:48 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/19 19:43:05 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push(t_list **lst_src, t_list **lst_dest)
{
	t_list	*tmp;

	if (*lst_src == NULL)
		return ;
	tmp = (*lst_src)->next;
	(*lst_src)->next = *lst_dest;
	*lst_dest = *lst_src;
	*lst_src = tmp;
}
