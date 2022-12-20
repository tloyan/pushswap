/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:04:44 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/20 14:52:21 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "utils.h"

void	checker(t_list **stack_a, t_list **stack_b, t_list	**instructions);
int		get_instructions(t_list **instructions);

#endif