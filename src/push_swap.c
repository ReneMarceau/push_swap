/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:40:56 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/28 16:28:02 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

//Just for testing...
void	display_lst(t_stack *stack, int size)
{
	t_stack *current;
	int	i;

	i = 0;
	if (!stack)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	current = stack;
	while (i++ < size)
	{
		ft_printf("value: %d prev: %d next: %d index: %d chunk: %d\n", current->value, current->prev->value, current->next->value, current->index, current->chunk);
		current = current->next;
	}
}
void	display_all(t_container *data)
{
		ft_printf("STACK A:\n");
		display_lst(data->stack_a, data->size_a);
		ft_printf("--------\n");
		ft_printf("STACK B:\n");
		display_lst(data->stack_b, data->size_b);
}

//Main sorting algorithm
static void	push_swap(t_container *data)
{
	if (data->size_a == 2)
		sa(data);
	else if (data->size_a == 3)
		sort_three(data);
	else if (data->size_a <= 5)
		sort_five(data);
	else
	{
		if (data->size_a <= 100)
			set_chunk(data, numberPerChunk(data->size_a, 8));
		else if (data->size_a <= 500)
			set_chunk(data, numberPerChunk(data->size_a, 18));
		else
			set_chunk(data, numberPerChunk(data->size_a, 28));
		sort_big(data);
	}
}

t_container *init_data(void)
{
	t_container *data;

	data = (t_container *)malloc(sizeof(t_container));
	if (!data)
		return (NULL);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->tab = NULL;
	data->size_a = 0;
	data->size_b = 0;
	return (data);
}


int	main(int argc, char **argv)
{
	t_container	*data;

	if (argc >= 2)
	{
		data = init_data();
		if (!data)
			return (EXIT_FAILURE);
		fill_stack(data, argc, argv);
		if (!data->stack_a)
			end_program(data, true);
		set_index(data->stack_a, data->size_a);
		push_swap(data);
		end_program(data, false);
	}
	return (EXIT_SUCCESS);
}
