/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:07:47 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/27 18:13:54 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack, int size)
{
	int first;
	int second;
	int third;

	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->prev->data;
	if (first > second && second < third && third > first)
		sa(stack, size);
	else if (first > second && second > third && third < first)
	{
		sa(stack, size);
		rra(stack, size);
	}
	else if (first > second && second < third && third < first)
		ra(stack, size);
	else if (first < second && second > third && third > first)
	{
		sa(stack, size);
		ra(stack, size);
	}
	else if (first < second && second > third && third < first)
		rra(stack, size);
}
