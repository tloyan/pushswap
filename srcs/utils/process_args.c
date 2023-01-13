/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:53:30 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/12 12:03:39 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	ft_sort_int_tab(int	*tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < size)
	{
		tmp = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > tmp)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = tmp;
		i++;
	}
}

int	get_node_position(int number, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (number == array[i])
			return (i);
		i = i + 1;
	}
	return (i);
}

void	set_stack_position(t_stack **stack, int	*array)
{
	int		i;

	i = 0;
	while (i < (*stack)->size)
	{
		(*stack)->curr->position
			= get_node_position((*stack)->curr->value, array, (*stack)->size);
		(*stack)->curr = (*stack)->curr->next;
		i = i + 1;
	}
	(*stack)->curr = (*stack)->head;
}

t_stack	*process_args(int argc, char **argv)
{
	int		*array;
	t_stack	*stack;

	stack = init_stack();
	if (stack == NULL)
		return (NULL);
	array = args_to_arr(argc, argv);
	if (array == NULL)
		process_exit(stack, NULL);
	set_stack_value(&stack, array, argc);
	ft_sort_int_tab(array, argc - 1);
	set_stack_position(&stack, array);
	free(array);
	return (stack);
}
