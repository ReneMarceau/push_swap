/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:50 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/18 18:10:34 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	update_stacks(t_stack **my_stack, t_stack **other_stack)
{
	(*my_stack)->prev->next = *my_stack;
	if (*other_stack)
	{
		(*other_stack)->prev = (*other_stack)->prev->prev;
		(*other_stack)->prev->next = *other_stack;
	}
}

//Push the value on top of stack_b to stack_a
void	pa(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b)
{
	if (!*stack_b)
		return ;
	if (!*stack_a)
		*stack_a = lstnew((*stack_b)->data, (*stack_b)->index, (*stack_b)->chunk);
	else
		lstadd_front(stack_a, &(*stack_a)->prev, lstnew((*stack_b)->data, (*stack_b)->index, (*stack_b)->chunk));
	delete_node(stack_b);
	update_stacks(stack_a, stack_b);
	*size_a = *size_a + 1;
	*size_b = *size_b - 1;
	ft_putendl_fd(PUSH_A, 1);
}

//Push the value on top of stack_a to stack_b
void	pb(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b)
{
	if (!*stack_a)
		return ;
	if (!*stack_b)
		*stack_b = lstnew((*stack_a)->data, (*stack_a)->index, (*stack_a)->chunk);
	else
		lstadd_front(stack_b, &(*stack_b)->prev, lstnew((*stack_a)->data, (*stack_a)->index, (*stack_a)->chunk));
	delete_node(stack_a);
	update_stacks(stack_b, stack_a);
	*size_a = *size_a - 1;
	*size_b = *size_b + 1;
	ft_putendl_fd(PUSH_B, 1);
}
