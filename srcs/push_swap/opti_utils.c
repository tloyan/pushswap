/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:11:36 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/27 14:14:16 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_lstdeln(t_list **lst, t_list **prev, int n)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (*lst && (i++ < n))
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, free);
		if (*prev)
			(*prev)->next = tmp;
		else
			(*prev) = tmp;
		*lst = tmp;
	}
	return (i);
}
