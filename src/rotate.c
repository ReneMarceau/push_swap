/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:56 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/27 17:31:21 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Shifts up all elements of the linked list by 1
static void	rotate(t_stack **stack, int size)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;
	
	if (size == 2)
		swap(stack);
	else
	{
		first = *stack;
		second = (*stack)->next;
		last = (*stack)->prev;
		last->next = first;
		first->prev = last;
		first->next = second;
		second->prev = first;
		*stack = second;
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
