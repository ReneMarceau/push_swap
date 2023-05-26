/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:58 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/26 18:51:35 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Swaps the first two values in a linked list
void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;

	first = *stack;
	second = (*stack)->next;
	third = (*stack)->next->next;
	last = (*stack)->prev;
	first->prev = second;
	second->next = first;
	if ((*stack)->size <= 2)
	{
		first->next = second;
		second->prev = first;
	}
	else {
		first->next = second->next;
		last->next = second;
		second->prev = last;
		third->prev = first;
	}
	*stack = second;
}

//Swaps the first two values of stack_a
void	sa(t_stack **stack_a)
{
	if ((*stack_a)->size < 2)
		return ;
	swap(stack_a);
	ft_putendl_fd(SWAP_A, 1);
}

//Swaps the first two values of stack_b
void	sb(t_stack **stack_b)
{
	if ((*stack_b)->size < 2)
		return ;
	swap(stack_b);
	ft_putendl_fd(SWAP_B, 1);
}

//Swaps the first two values of stack_a and stack_b
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size <= 1 && (*stack_b)->size <= 1)
		return ;
	if ((*stack_a)->size > 1)
		swap(stack_a);
	if ((*stack_b)->size > 1)
		swap(stack_b);
	ft_putendl_fd(SWAP_STACK, 1);
}
