/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:40:56 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/26 19:07:01 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

//Just for testing...
void	display_lst(t_stack *stack)
{
	t_stack *current;
	int	i;

	i = 0;
	if (!stack->size)
		ft_printf("Stack is empty\n");
	current = stack;
	while (i++ < stack->size)
	{
		ft_printf("value: %d prev: %d next: %d index: %d chunk: %d\n", current->data, current->prev->data, current->next->data, current->index, current->chunk);
		current = current->next;
	}
}
void	display_all(t_stack *stack_a, t_stack *stack_b)
{
		ft_printf("STACK A:\n");
		display_lst(stack_a);
		ft_printf("--------\n");
		ft_printf("STACK B:\n");
		display_lst(stack_b);
}

//Main sorting algorithm
static void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size == 2)
		sa(stack_a);
	else if ((*stack_a)->size == 3)
		sort_three(stack_a);
	else if ((*stack_a)->size <= 5)
		sort_five(stack_a, stack_b);
	else if ((*stack_a)->size <= 100)
	{
		set_chunk(*stack_a, numberPerChunk((*stack_a)->size, 8));
		sort_big(stack_a, stack_b);
	}
	else if ((*stack_a)->size <= 500)
	{
		set_chunk(*stack_a, numberPerChunk((*stack_a)->size, 18));
		sort_big(stack_a, stack_b);
	}
	else
	{
		set_chunk(*stack_a, numberPerChunk((*stack_a)->size, 28));
		sort_big(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc >= 2)
	{
		stack_a = fill_stack(argc, argv);
		stack_b = NULL;
		if (!stack_a)
			end_program(stack_a, stack_b, true);
		set_index(stack_a);
		display_all(stack_a, stack_b);
		//ft_printf("before size_a: %d\n", stack_a->size);
		//pb(&stack_a, &stack_b);
		//ft_printf("after size_a: %d\n", stack_a->size);
		//ft_printf("after size_b: %d\n", stack_b->size);
		end_program(stack_a, stack_b, false);
		push_swap(&stack_a, &stack_b);
	}
	return (EXIT_SUCCESS);
}
