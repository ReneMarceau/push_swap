/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:07:47 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/29 01:57:47 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Finds the index of a value in a stack
static int	find_index(t_stack *stack, int index_searched)
{
	int	index;

	index = 0;
	while (stack->index != index_searched)
	{
		stack = stack->next;
		index++;
	}
	return (index);
}

// Sorts a stack of size 3
void	sort_three(t_container *data)
{
	int	first;
	int	second;
	int	third;

	first = data->stack_a->value;
	second = data->stack_a->next->value;
	third = data->stack_a->prev->value;
	if (first > second && second < third && third > first)
		sa(data);
	else if (first > second && second > third && third < first)
	{
		sa(data);
		rra(data);
	}
	else if (first > second && second < third && third < first)
		ra(data);
	else if (first < second && second > third && third > first)
	{
		sa(data);
		ra(data);
	}
	else if (first < second && second > third && third < first)
		rra(data);
}

// Sorts a stack of size 5 or 4
void	sort_five(t_container *data)
{
	int	smallest_index;
	int	repeat_num;

	smallest_index = 0;
	repeat_num = data->size_a - 3;
	while (repeat_num--)
	{
		if (data->size_a / 2 > find_index(data->stack_a, smallest_index))
		{
			while (data->stack_a->index != smallest_index)
				ra(data);
		}
		else
		{
			while (data->stack_a->index != smallest_index)
				rra(data);
		}
		pb(data);
		smallest_index++;
	}
	sort_three(data);
	repeat_num = (data->size_a + smallest_index) - 3;
	while (repeat_num--)
		pa(data);
}
