/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:40:56 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/18 18:53:11 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Just for testing...
void	display_lst(t_stack *stack, int size)
{
	int	i;

	i = 0;
	if (!size)
		ft_printf("Stack is empty\n");
	while (i < size)
	{
		ft_printf("value: %d prev: %d next: %d index: %d chunk: %d\n", stack->data, stack->prev->data, stack->next->data, stack->index, stack->chunk);
		stack = stack->next;
		i++;
	}
}
void display_all(t_stack *stack_a, t_stack *stack_b, int size_a, int size_b)
{
		ft_printf("STACK A:\n");
		display_lst(stack_a, size_a);
		ft_printf("--------\n");
		ft_printf("STACK B:\n");
		display_lst(stack_b, size_b);
}

//Main sorting algorithm
void	push_swap(t_stack **stack_a, t_stack **stack_b, int size_a, int size_b)
{
	if (size_a == 2)
		sa(stack_a, size_a);
	else if (size_a == 3)
		sort_three(stack_a, size_a);
	else if (size_a <= 5)
		sort_five(stack_a, stack_b, size_a, size_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;
	int		size_b;

	if (argc >= 2)
	{
		stack_a = fill_stack(argc, argv, &size_a);
		stack_b = NULL;
		size_b = 0;
		if (!stack_a)
			end_failure(stack_a, stack_b, size_a, size_b);
		set_index(stack_a, size_a);
		push_swap(&stack_a, &stack_b, size_a, size_b);
		display_all(stack_a, stack_b, size_a, size_b);
		end_success(stack_a, stack_b, size_a, size_b);
	}
	return (EXIT_SUCCESS);
}
