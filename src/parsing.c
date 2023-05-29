/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:36:14 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/29 02:02:29 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Fill an array of int the values passed to the program is a string
int	*quotes_to_tab(char **argv, int *size)
{
	char	**tab_char;
	int		*tab;
	int		i;

	tab_char = ft_split(argv[1], ' ');
	*size = count_arg(tab_char);
	tab = (int *)ft_calloc(*size, sizeof(int));
	i = -1;
	while (tab_char[++i])
	{
		if (ft_isnumber(tab_char[i]) && ft_strlen(tab_char[i]) < 10)
			tab[i] = ft_atoi(tab_char[i]);
		else
		{
			free(tab);
			free_2d(tab_char, *size);
			return (NULL);
		}
	}
	free_2d(tab_char, *size);
	return (tab);
}

// Fill an array of int the values passed to the program are arguments
int	*args_to_tab(int argc, char **argv, int *size)
{
	int	*tab;
	int	i;
	int	j;

	*size = argc - 1;
	tab = (int *)ft_calloc(*size, sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (i++ < *size)
	{
		if (ft_isnumber(argv[i]) && ft_strlen(argv[i]) < 12)
			tab[j++] = ft_atoi(argv[i]);
		else
		{
			free(tab);
			return (NULL);
		}
	}
	return (tab);
}

// Fill The stack_a with all the value provided by quotes or arguments.
// But only if all the values are valids.
void	fill_stack(t_container *data, int argc, char **argv)
{
	int	len;

	if (argc == 2)
		data->tab = quotes_to_tab(argv, &data->size_a);
	else
		data->tab = args_to_tab(argc, argv, &data->size_a);
	if (!data->tab || !is_repeat(data->tab, data->size_a))
		end_program(data, true);
	if (is_sorted(data->tab, data->size_a))
	{
		end_program(data, false);
		exit(EXIT_SUCCESS);
	}
	len = data->size_a;
	while (--len >= 0)
	{
		if (!data->stack_a)
			data->stack_a = lstnew(data->tab[len], -1, -1);
		else
			lstadd_front(&data->stack_a, &data->stack_a->prev,
				lstnew(data->tab[len], -1, -1));
	}
	data->stack_a->prev->next = data->stack_a;
}
