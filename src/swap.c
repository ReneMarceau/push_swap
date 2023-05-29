/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:58 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/29 01:53:21 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Swaps the first two values in a linked list
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
	first->prev = second;
	second->next = first;
	if (size <= 2)
	{
		first->next = second;
		second->prev = first;
	}
	else
	{
		first->next = third;
		last->next = second;
		second->prev = last;
		third->prev = first;
	}
	*stack = second;
}

// Swaps the first two values of stack_a
void	sa(t_container *data)
{
	if (data->size_a < 2)
		return ;
	swap(&data->stack_a, data->size_a);
	ft_putendl_fd(SWAP_A, 1);
}

// Swaps the first two values of stack_b
void	sb(t_container *data)
{
	if (data->size_b < 2)
		return ;
	swap(&data->stack_b, data->size_b);
	ft_putendl_fd(SWAP_B, 1);
}

// Swaps the first two values of stack_a and stack_b
void	ss(t_container *data)
{
	if (data->size_a <= 1 && data->size_b <= 1)
		return ;
	if (data->size_a > 1)
		swap(&data->stack_a, data->size_a);
	if (data->size_b > 1)
		swap(&data->stack_b, data->size_b);
	ft_putendl_fd(SWAP_STACK, 1);
}
