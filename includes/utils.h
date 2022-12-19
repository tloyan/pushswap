/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:33:52 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/19 19:43:22 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

typedef struct s_data {
	long int	number;
}	t_data;

t_list	*process_args(int argc, char **argv);
void	process_exit(t_list *lst);

void	ft_swap(t_list **lst);
void	ft_push(t_list **lst_src, t_list **lst_dest);
void	ft_rotate(t_list **lst);
void	ft_rrotate(t_list **lst);

void	display_lst(t_list *lst);

#endif