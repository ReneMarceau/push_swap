/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:31:07 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/29 02:10:53 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Updates the top and bottom chunks if needed
static void	update_chunks(t_container *data, int *chunk_top, int *chunk_bottom)
{
	if (chunk_bottom[SIZE] == 0)
	{
		chunk_bottom[VALUE]++;
		if (chunk_bottom[VALUE] == chunk_top[VALUE])
			chunk_top[SIZE] = 0;
		chunk_bottom[SIZE] = get_chunk_size(data, chunk_bottom[VALUE]);
	}
	if (chunk_top[SIZE] == 0)
	{
		chunk_top[VALUE]++;
		chunk_top[SIZE] = get_chunk_size(data, chunk_top[VALUE]);
	}
}

// Pushes a selected chunk to stack_b
static void	push_selected_chunk(t_container *data, int chunk, bool is_bottom)
{
	int	repeat_movement;

	repeat_movement = best_path(data->stack_a, data->size_a, chunk, true);
	if (repeat_movement > 0)
	{
		while (repeat_movement-- > 0)
			ra(data);
	}
	else
	{
		while (repeat_movement++ < 0)
			rra(data);
	}
	pb(data);
	if (is_bottom)
		rb(data);
}

// Pushes all values from stack_a to stack_b 2 chunks at a time
static void	push_chunks_to_b(t_container *data)
{
	int	chunk_top[CHUNK_COUNT];
	int	chunk_bottom[CHUNK_COUNT];

	chunk_top[VALUE] = 1;
	chunk_bottom[VALUE] = 0;
	chunk_top[SIZE] = get_chunk_size(data, chunk_top[VALUE]);
	chunk_bottom[SIZE] = get_chunk_size(data, chunk_bottom[VALUE]);
	while (data->stack_a)
	{
		update_chunks(data, chunk_top, chunk_bottom);
		if (abs(best_path(data->stack_a, data->size_a, chunk_top[VALUE],
					true)) <= abs(best_path(data->stack_a, data->size_a,
					chunk_bottom[VALUE], true)))
		{
			push_selected_chunk(data, chunk_top[VALUE], false);
			chunk_top[SIZE]--;
		}
		else
		{
			push_selected_chunk(data, chunk_bottom[VALUE], true);
			chunk_bottom[SIZE]--;
		}
	}
}

// Pushes back all values from stack_b to stack_a in descending order
static void	push_back_to_a(t_container *data)
{
	int	repeat_movement;
	int	last_index;

	last_index = data->size_b - 1;
	while (data->stack_b)
	{
		repeat_movement = best_path(data->stack_b, data->size_b, last_index,
				false);
		if (repeat_movement > 0)
		{
			while (repeat_movement-- > 0)
				rb(data);
		}
		else
		{
			while (repeat_movement++ < 0)
				rrb(data);
		}
		pa(data);
		last_index--;
	}
}

// Sorts a stack of size > 5
void	sort_big(t_container *data)
{
	push_chunks_to_b(data);
	push_back_to_a(data);
}
