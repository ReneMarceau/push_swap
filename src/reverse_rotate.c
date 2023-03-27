/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:54 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/27 17:33:39 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Shifts down all elements of the linked list by 1
static void	reverse_rotate(t_stack **stack, int size)
{
	t_stack	*first;
	t_stack	*second_last;
	t_stack	*last;
	
	if (size == 2)
		swap(stack);
	else
	{
		first = *stack;
		second_last = (*stack)->prev->prev;
		last = (*stack)->prev;
		second_last->next = last;
		last->prev = second_last;
		last->next = first;
		first->prev = last;
		*stack = last;
	}
}

//Shifts down all elements of stack_a by 1
void	rra(t_stack **stack_a, int size)
{
	if (size < 2)
		return ;
	reverse_rotate(stack_a, size);
	ft_putendl_fd(REV_ROTATE_A, 1);
}

//Shifts down all elements of stack_b by 1
void	rrb(t_stack **stack_b, int size)
{
	if (size < 2)
		return ;
	reverse_rotate(stack_b, size);
	ft_putendl_fd(REV_ROTATE_B, 1);
}

//Shifts down all elements of stack_a and stack_b by 1
void	rrr(t_stack **stack_a, t_stack **stack_b, int size_a, int size_b)
{
	if (size_a < 2 || size_b < 2)
		return ;
	reverse_rotate(stack_a, size_a);
	reverse_rotate(stack_b, size_a);
	ft_putendl_fd(REV_ROTATE_STACK, 1);
}
