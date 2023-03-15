/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:54 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/14 16:52:51 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(*stack_a);
	ft_putendl_fd(REV_ROTATE_A, 1);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(*stack_b);
	ft_putendl_fd(REV_ROTATE_B, 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(*stack_a);
	reverse_rotate(*stack_b);
	ft_putendl_fd(REV_ROTATE_STACK, 1);
}