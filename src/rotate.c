/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:56 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/29 02:00:37 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Shifts up all elements of the linked list by 1
static void	rotate(t_stack **stack, int size)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (size == 2)
		swap(stack, 2);
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

// Shifts up all elements of stack_a by 1
void	ra(t_container *data)
{
	if (data->size_a < 2)
		return ;
	rotate(&data->stack_a, data->size_a);
	ft_putendl_fd(ROTATE_A, 1);
}

// Shifts up all elements of stack_b by 1
void	rb(t_container *data)
{
	if (data->size_b < 2)
		return ;
	rotate(&data->stack_b, data->size_b);
	ft_putendl_fd(ROTATE_B, 1);
}

// Shifts up all elements of stack_a and stack_b by 1
void	rr(t_container *data)
{
	if (data->size_a > 1 && data->size_b > 1)
		return ;
	if (data->size_a > 1)
		rotate(&data->stack_a, data->size_a);
	if (data->size_b > 1)
		rotate(&data->stack_b, data->size_b);
	ft_putendl_fd(ROTATE_STACK, 1);
}
