/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:04:00 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/19 17:19:52 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

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
