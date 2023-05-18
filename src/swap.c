/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:58 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/18 18:22:34 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Swaps the first two values in a linked list
void	swap(t_stack **stack, int size)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;

	first = *stack;
	second = (*stack)->next;
	third = (*stack)->next->next;
	last = (*stack)->prev;
	if (size <= 2)
	{
		first->next = second;
		first->prev = second;
		second->next = first;
		second->prev = first;
	}
	else {
		first->next = second->next;
		first->prev = second;
		last->next = second;
		second->next = first;
		second->prev = last;
		third->prev = first;
	}
	*stack = second;
}

//Swaps the first two values of stack_a
void	sa(t_stack **stack_a, int size)
{
	if (size < 2)
		return ;
	swap(stack_a, size);
	ft_putendl_fd(SWAP_A, 1);
}

//Swaps the first two values of stack_b
void	sb(t_stack **stack_b, int size)
{
	if (size < 2)
		return ;
	swap(stack_b, size);
	ft_putendl_fd(SWAP_B, 1);
}

//Swaps the first two values of stack_a and stack_b
void	ss(t_stack **stack_a, t_stack **stack_b, int size_a, int size_b)
{
	if (size_a > 1 || size_b > 1)
	{
		if (size_a > 1)
			swap(stack_a, size_a);
		if (size_b > 1)
			swap(stack_b, size_b);
		ft_putendl_fd(SWAP_STACK, 1);
	}
}
