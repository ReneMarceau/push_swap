/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:50 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/14 19:42:25 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b)
{
	if (!*stack_b)
		return ;
	if(!*stack_a)
		*stack_a = lstnew((*stack_b)->data);
	else
		lstadd_front(stack_a, &(*stack_a)->prev, lstnew((*stack_b)->data));
	delete_node(stack_b);
	*size_a = *size_a + 1;
	*size_b = *size_b - 1;
	ft_putendl_fd(PUSH_A, 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b)
{
	if (!*stack_a)
		return ;
	if (!*stack_b)
		*stack_b = lstnew((*stack_a)->data);
	else
		lstadd_front(stack_b, &(*stack_b)->prev, lstnew((*stack_a)->data));
	delete_node(stack_a);
	*size_a = *size_a - 1;
	*size_b = *size_b + 1;
	ft_putendl_fd(PUSH_B, 1);
}
