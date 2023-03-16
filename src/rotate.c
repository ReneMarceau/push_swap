/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:56 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/15 20:01:24 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Shifts up all elements of the linked list by 1
static void	rotate(t_stack **stack, int size)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*last_node;

	first_node = *stack;
	second_node = (*stack)->next;
	last_node = (*stack)->prev;
	if (size == 2)
		swap(stack);
	else
	{
		last_node->next = first_node;
		*stack = second_node;
	}
}

//Shifts up all elements of stack_a by 1
void	ra(t_stack **stack_a, int size)
{
	if (size < 2)
		return ;
	rotate(stack_a, size);
	ft_putendl_fd(ROTATE_A, 1);
}

//Shifts up all elements of stack_b by 1
void	rb(t_stack **stack_b, int size)
{
	if (size < 2)
		return ;
	rotate(stack_b, size);
	ft_putendl_fd(ROTATE_B, 1);
}

//Shifts up all elements of stack_a and stack_b by 1
void	rr(t_stack **stack_a, t_stack **stack_b, int size_a, int size_b)
{
	if (size_a < 2 || size_b < 2)
		return ;
	rotate(stack_a, size_a);
	rotate(stack_b, size_b);
	ft_putendl_fd(ROTATE_STACK, 1);
}
