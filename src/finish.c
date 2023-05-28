/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:38:50 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/28 16:12:36 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Free 2d array of char
void	free_2d(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}

//Free every node in the linked list
static void	free_lst(t_stack *stack, int size)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (stack)
	{
		while (i++ < size)
		{
			tmp = stack->next;
			free(stack);
			stack = tmp;
		}
	}
}

//Terminate the program with an error message if needed
void	end_program(t_container *data, bool error)
{
	if (data->stack_a)
		free_lst(data->stack_a, data->size_a);
	if (data->stack_b)
		free_lst(data->stack_b, data->size_b);
	if (data->tab)
		free(data->tab);
	free(data);
	if (error)
	{
		ft_putendl_fd(ERROR, 2);
		exit(EXIT_FAILURE);
	}
}

