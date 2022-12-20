/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:05:16 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/20 14:28:28 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	checker(t_list **stack_a, t_list **stack_b, t_list	**instructions)
{
	char	*str;

	(void)stack_a;
	(void)stack_b;
	(void)instructions;
	str = ft_strdup("hello world !");
	ft_strlen(str);
	free(str);
	return ;
}
