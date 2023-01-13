/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:04:44 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/13 12:18:33 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "utils.h"

void	check_result(t_stack **a, t_stack **b);
int		get_instructions(t_list **instructions);
void	run_instructions(t_stack **a, t_stack **b, t_list **instructions);

#endif