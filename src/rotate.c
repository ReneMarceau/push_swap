/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:56 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/14 16:49:14 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack **stack)
{
	
}

void	ra(t_stack **stack_a)
{
	rotate(*stack_a);
	ft_putendl_fd(ROTATE_A, 1);
}

void	rb(t_stack **stack_b)
{
	rotate(*stack_b);
	ft_putendl_fd(ROTATE_B, 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(*stack_a);
	rotate(*stack_b);
	ft_putendl_fd(ROTATE_STACK, 1);
}
