/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:14:16 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/28 17:23:55 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int get_chunk_size(t_container *data, int chunk)
{
    t_stack *current;
    int chunk_size;
    int i;

    current = data->stack_a;
    chunk_size = 0;
    i = 0;
    while (i++ < data->size_a)
    {
        if (current->chunk == chunk)
            chunk_size++;
        current = current->next;
    }
    return (chunk_size);
}

int simulate_move_top(t_stack *stack, int size, int val, bool is_chunk)
{
    t_stack *current;
    int move_top;

    current = stack;
    move_top = 0;
    while (move_top < size)
    {
        if (is_chunk)
        {
            if (current->chunk == val)
                break ;
        }
        else
        {
            if (current->index == val)
                break ;
        }
        move_top++;
        current = current->next;
    }
    return (move_top);
}

int simulate_move_bottom(t_stack *stack, int size, int val, bool is_chunk)
{
    t_stack *current;
    int move_bottom;

    current = stack->prev;
    move_bottom = 0;
    while (--move_bottom > (size * -1))
    {
        if (is_chunk)
        {
            if (current->chunk == val)
                break ;
        }
        else
        {
            if (current->index == val)
                break ;
        }
        current = current->prev;
    }
    return (move_bottom);
}

int best_path(t_stack *stack, int size, int value, bool is_chunk)
{
    int     move_top;
    int     move_bottom;

    move_top = simulate_move_top(stack, size, value, is_chunk);
    move_bottom = simulate_move_bottom(stack, size, value, is_chunk);
    if (move_top <= abs(move_bottom))
        return (move_top);
    else
        return (move_bottom);
}
