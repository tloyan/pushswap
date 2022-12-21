/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:29:42 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/21 19:33:27 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

void	push_swap(void);
void	algo_3(t_list **stack_a, t_list **stack_b);
void	algo_5(t_list **stack_a, t_list **stack_b);
void	call_instruction(t_list **stack_a, t_list **stack_b, char *instruction);

#endif