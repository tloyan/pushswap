/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args_val.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:41:35 by thloyan           #+#    #+#             */
/*   Updated: 2023/01/12 11:59:12 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "limits.h"

static int	str_is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] != 0 && (str[i] == '-' || str[i] == '+'))
		i = i + 1;
	if (str[i] == 0)
		return (0);
	while (str[i] != 0)
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i = i + 1;
	}
	return (1);
}

static int	nb_already_exist(int number, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == number)
			return (1);
		i = i + 1;
	}
	return (0);
}

int	*args_to_arr(int argc, char **argv)
{
	int			i;
	long int	number;
	int			*array;

	array = malloc(argc * sizeof(*array));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (!str_is_valid_number(argv[i + 1]))
			return (free(array), NULL);
		number = ft_atol(argv[i + 1]);
		if (number > INT_MAX || number < INT_MIN)
			return (free(array), NULL);
		if (nb_already_exist(number, array, i))
			return (free(array), NULL);
		array[i] = number;
		i = i + 1;
	}
	return (array);
}

void	set_stack_value(t_stack **stack, int *array, int size)
{
	t_node	*node;
	int		i;

	i = 0;
	while (i < size - 1)
	{
		node = create_stack_node(array[i], 0);
		if (node == NULL)
			return (free(array), process_exit(*stack, NULL));
		insert_at_end(&*stack, &node);
		i = i + 1;
	}
}
