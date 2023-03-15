/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:40:56 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/14 20:25:35 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Just for testing...
static void	display_lst(t_stack *stack, int size)
{
	int	i;

	i = 0;
	if (!size)
		ft_printf("Stack is empty\n");
	while (i < size)
	{
		ft_printf("%d\n", stack->data);
		stack = stack->next;
		i++;
	}
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
			end_program(stack_a, stack_b, size_a, size_b);
		pb(&stack_a, &stack_b, &size_a, &size_b);
		sa(&stack_b, size_b);
		ft_printf("STACK A:\n");
		display_lst(stack_a, size_a);
		ft_printf("--------\n");
		ft_printf("STACK B:\n");
		display_lst(stack_b, size_b);
	}
	return (0);
}
