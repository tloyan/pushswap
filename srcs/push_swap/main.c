/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:20:57 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/19 17:19:45 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*lst;

	i = 0;
	lst = process_args(argc, argv);
	display_lst(lst);
	ft_lstclear(&lst, &free);
	return (0);
}
