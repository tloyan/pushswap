/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:05:16 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/17 16:06:36 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	checker(void)
{
	char	*str;

	str = ft_strdup("hello world !");
	ft_strlen(str);
	free(str);
	return ;
}
