/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:33:52 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/13 12:27:25 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

typedef struct s_node {
	int				value;
	int				position;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	struct s_node	*head;
	struct s_node	*tail;
	struct s_node	*curr;
	int				size;
}	t_stack;

void	process_exit(t_stack *a, t_stack *b);
void	set_stack_value(t_stack **stack, int *array, int size);
int		*args_to_arr(int argc, char **argv);
t_stack	*process_args(int argc, char **argv);

t_stack	*init_stack(void);
t_node	*create_stack_node(int value, int position);
void	insert_at_begin(t_stack **stack, t_node **node);
void	insert_at_end(t_stack **stack, t_node **node);
void	clear_stack(t_stack	*stack);

void	ft_swap(t_stack **stack);
void	ft_push(t_stack **stack_src, t_stack **stack_dest);
void	ft_rotate(t_stack **stack);
void	ft_rrotate(t_stack **stack);
void	exec_instruction(t_stack **a, t_stack **b, char *instruction);

#endif