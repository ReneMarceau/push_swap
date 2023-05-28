/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:54 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/27 14:01:56 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Shifts down all elements of the linked list by 1
static void	reverse_rotate(t_stack **stack, int size)
{
	t_stack	*first;
	t_stack	*second_last;
	t_stack	*last;

	first = *stack;
	second_last = (*stack)->prev->prev;
	last = (*stack)->prev;
	if (size == 2)
		swap(stack, 2);
	else
	{
		first->prev = last;
		last->next = first;
		last->prev = second_last;
		second_last->next = last;
		*stack = last;
	}
}

//Shifts down all elements of stack_a by 1
void	rra(t_container *data)
{
	if (data->size_a < 2)
		return ;
	reverse_rotate(&data->stack_a, data->size_a);
	ft_putendl_fd(REV_ROTATE_A, 1);
}

//Shifts down all elements of stack_b by 1
void	rrb(t_container *data)
{
	if (data->size_b < 2)
		return ;
	reverse_rotate(&data->stack_b, data->size_b);
	ft_putendl_fd(REV_ROTATE_B, 1);
}

//Shifts down all elements of stack_a and stack_b by 1
void	rrr(t_container *data)
{
	if (data->size_a > 1 && data->size_b > 1)
		return ;
	if (data->size_a > 1)
		reverse_rotate(&data->stack_a, data->size_a);
	if (data->size_b > 1)
		reverse_rotate(&data->stack_b, data->size_b);
	ft_putendl_fd(REV_ROTATE_STACK, 1);
}
