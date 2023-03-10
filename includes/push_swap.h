/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:29:42 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/27 14:12:39 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

void	algo(t_stack **a, t_stack **b, t_list **instructions);
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
int		get_direction_by_pos(t_stack *stack, int position);
void	place_node_to_top_by_pos(
			t_stack **stack,
			t_list **instructions,
			int position,
			char *letter
			);
void	opti(t_list **instructions);
int		ft_lstdeln(t_list **lst, t_list **prev, int n);

#endif