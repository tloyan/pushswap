/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:53:30 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/19 16:18:59 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
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

static int	nb_already_exist(int number, t_list *lst)
{
	while (lst)
	{
		if (((t_data *)lst->content)->number == number)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static t_list	*create_new_elem(char *str, t_list *lst)
{
	t_data		*data;

	data = malloc(sizeof(*data));
	if (data == NULL || !str_is_valid_number(str))
		return (free(data), NULL);
	data->number = ft_atol(str);
	if (data->number > INT_MAX || data->number < INT_MIN)
		return (free(data), NULL);
	if (nb_already_exist(data->number, lst))
		return (free(data), NULL);
	return (ft_lstnew((void *)data));

}

t_list	*process_args(int argc, char **argv)
{
	t_list		*lst;
	t_list		*new_element;
	t_list		*last_element;
	int			i;

	lst = NULL;
	last_element = NULL;
	i = 0;
	while (++i < (argc))
	{
		new_element = create_new_elem(argv[i], lst);
		if (new_element == NULL)
			return (process_exit(lst), NULL);
		if (lst == NULL)
			lst = new_element;
		if (last_element != NULL)
			last_element->next = new_element;
		last_element = new_element;
	}
	return (lst);
}
