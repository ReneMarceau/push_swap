/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:31:07 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/28 17:42:04 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    push_selected_chunk(t_container *data, int chunk, bool is_bottom)
{
    int repeat_movement;

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

static void    push_chunks_to_b(t_container *data)
{
    int chunk_top[CHUNK_COUNT];
    int chunk_bottom[CHUNK_COUNT];

    chunk_top[VALUE] = 1;
    chunk_bottom[VALUE] = 0;
    chunk_top[SIZE] = get_chunk_size(data, chunk_top[VALUE]);
    chunk_bottom[SIZE] = get_chunk_size(data, chunk_bottom[VALUE]);
    while (data->stack_a)
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
        if (abs(best_path(data->stack_a, data->size_a, chunk_top[VALUE], true)) <= abs(best_path(data->stack_a, data->size_a, chunk_bottom[VALUE], true)))
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

void    push_back_to_a(t_container *data)
{
    int repeat;
    int last_index;

    last_index = data->size_b - 1;
    while (data->stack_b)
    {
        repeat = best_path(data->stack_b, data->size_b, last_index, false);
        if (repeat > 0)
        {
            while (repeat-- > 0)
                rb(data);
        }
        else
        {
            while (repeat++ < 0)
                rrb(data);
        }
        pa(data);
        last_index--;
    }
}

void    sort_big(t_container *data)
{
    push_chunks_to_b(data);
    push_back_to_a(data);
}
