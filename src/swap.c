/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:58 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/14 16:49:20 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack **stack)
{
	
}

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putendl_fd(SWAP_A, 1);
}

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putendl_fd(SWAP_B, 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_a);
	ft_putendl_fd(SWAP_STACK, 1);	
}
