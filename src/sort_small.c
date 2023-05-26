/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:07:47 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/26 19:00:58 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

//Sorts a stack of size 3
void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->prev->data;
	if (first > second && second < third && third > first)
		sa(stack);
	else if (first > second && second > third && third < first)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && third < first)
		ra(stack);
	else if (first < second && second > third && third > first)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && third < first)
		rra(stack);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest_position;
	int	smallest_index;
	int	repeat_num;

	smallest_index = 0;
	repeat_num = (*stack_a)->size - 3;
	while (repeat_num--)
	{
		smallest_position = find_index(*stack_a, smallest_index);
		if ((*stack_a)->size / 2 > smallest_position)
		{
			while ((*stack_a)->index != smallest_index)
				ra(stack_a);
		}
		else
		{
			while ((*stack_a)->index != smallest_index)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		smallest_index++;
	}
	sort_three(stack_a);
	repeat_num = ((*stack_a)->size + smallest_index) - 3;
	while (repeat_num--)
		pa(stack_a, stack_b);
}
