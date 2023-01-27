/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:45:48 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/27 14:15:09 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_action(t_list **lst, char *str)
{
	int	i;

	i = 0;
	while (*lst && ft_memcmp((*lst)->content, str, 3) == 0)
	{
		i = i + 1;
		*lst = (*lst)->next;
	}
	return (i);
}

int	count_opposite(t_list **lst, char *str, int max)
{
	int	i;

	i = 0;
	while (*lst && ft_memcmp((*lst)->content, str, 3) == 0 && i < max)
	{
		i = i + 1;
		*lst = (*lst)->next;
	}
	return (i);
}

void	replace_rb(t_list **lst, t_list **prev)
{
	t_list	*begin;
	int		act_count;
	int		opp_count;
	int		i;

	begin = *lst;
	act_count = count_action(lst, "rb");
	opp_count = count_opposite(lst, "ra", act_count);
	*lst = begin;
	i = ft_lstdeln(lst, prev, opp_count);
	begin = *lst;
	while (*lst && (i++ < act_count + 1))
		*lst = (*lst)->next;
	i = 0;
	while (i++ < opp_count)
	{
		ft_memcpy((*lst)->content, "rr", 3);
		*lst = (*lst)->next;
	}
	*lst = begin;
}

void	replace_rrb(t_list **lst, t_list **prev)
{
	t_list	*begin;
	int		act_count;
	int		opp_count;
	int		i;

	begin = *lst;
	act_count = count_action(lst, "rrb");
	opp_count = count_opposite(lst, "rra", act_count);
	*lst = begin;
	i = ft_lstdeln(lst, prev, opp_count);
	begin = *lst;
	while (*lst && (i++ < act_count + 1))
		*lst = (*lst)->next;
	i = 0;
	while (i++ < opp_count)
	{
		ft_memcpy((*lst)->content, "rrr", 3);
		*lst = (*lst)->next;
	}
	*lst = begin;
}

void	opti(t_list **instructions)
{
	t_list	*prev;
	t_list	*begin;

	prev = NULL;
	begin = NULL;
	while (*instructions != NULL)
	{
		if (ft_memcmp((*instructions)->content, "rb", 3) == 0)
			replace_rb(&*instructions, &prev);
		if (!ft_memcmp((*instructions)->content, "rrb", 3))
			replace_rrb(&*instructions, &prev);
		prev = *instructions;
		if (begin == NULL)
			begin = *instructions;
		*instructions = (*instructions)->next;
	}
	*instructions = begin;
}
