/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:29:42 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/16 16:39:38 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

void	algo_3(t_stack **a, t_stack **b, t_list **instructions);
void	algo_5(t_stack **a, t_stack **b, t_list **instructions);
void	call_instruction(
			t_stack **a,
			t_stack **b,
			t_list **instructions,
			char *instruction
			);
void	call_instruction_with_stack(
			t_stack **stack,
			t_list **inst,
			char *action,
			char *letter
			);
void	display_instructions(t_list *instruction);
char	*get_action(char *s, char *action, char *letter);
int		get_next_position(t_stack *stack, t_node *node);
void	place_node_to_top_by_pos(
			t_stack **stack,
			t_list **instructions,
			int position,
			char *letter
			);

#endif