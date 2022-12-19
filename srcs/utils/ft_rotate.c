/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:07:30 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/19 19:27:35 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;

	tmp = (*lst)->next;
	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	last = ft_lstlast(*lst);
	(*lst)->next = NULL;
	last->next = *lst;
	*lst = tmp;
}
