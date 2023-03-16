/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:58 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/15 19:52:33 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Swaps the first two values in a linked list
void	swap(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

//Swaps the first two values of stack_a
void	sa(t_stack **stack_a, int size)
{
	if (size < 2)
		return ;
	swap(stack_a);
	ft_putendl_fd(SWAP_A, 1);
}

//Swaps the first two values of stack_b
void	sb(t_stack **stack_b, int size)
{
	if (size < 2)
		return ;
	swap(stack_b);
	ft_putendl_fd(SWAP_B, 1);
}

//Swaps the first two values of stack_a and stack_b
void	ss(t_stack **stack_a, t_stack **stack_b, int size_a, int size_b)
{
	if (size_a < 2 || size_b < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd(SWAP_STACK, 1);
}
