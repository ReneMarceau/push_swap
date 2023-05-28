/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:29:50 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/28 17:50:59 by rmarceau         ###   ########.fr       */
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
void	pa(t_container *data)
{
	if (!data->stack_b)
		return ;
	if (!data->stack_a)
		data->stack_a = lstnew(data->stack_b->value, data->stack_b->index,
			data->stack_b->chunk);
	else
		lstadd_front(&data->stack_a, &data->stack_a->prev, lstnew(data->stack_b->value, data->stack_b->index, data->stack_b->chunk));
	delete_node(&data->stack_b);
	update_stacks(&data->stack_a, &data->stack_b);
	data->size_a++;
	data->size_b--;
	ft_putendl_fd(PUSH_A, 1);
}

//Push the value on top of stack_a to stack_b
void	pb(t_container *data)
{
	if (!data->stack_a)
		return ;
	if (!data->stack_b)
		data->stack_b = lstnew(data->stack_a->value, data->stack_a->index, data->stack_a->chunk);
	else
		lstadd_front(&data->stack_b, &data->stack_b->prev, lstnew(data->stack_a->value, data->stack_a->index, data->stack_a->chunk));
	delete_node(&data->stack_a);
	update_stacks(&data->stack_b, &data->stack_a);
	data->size_a--;
	data->size_b++;
	ft_putendl_fd(PUSH_B, 1);
}
