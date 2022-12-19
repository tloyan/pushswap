/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:28:36 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/19 19:38:15 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rrotate(t_list **lst)
{
	t_list	*first;
	t_list	*last;
	t_list	*prev;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	while ((*lst)->next)
	{
		prev = *lst;
		*lst = (*lst)->next;
	}
	last = *lst;
	last->next = first;
	prev->next = NULL;
	*lst = last;
}
