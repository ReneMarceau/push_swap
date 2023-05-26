/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:14:16 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/26 16:50:55 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int get_chunk_size(t_stack *stack, int chunk)
{
    int chunk_size;
    int i;

    chunk_size = 0;
    i = 0;
    while (i++ < stack->size)
    {
        if (stack->chunk == chunk)
            chunk_size++;
        stack = stack->next;
    }
    return (chunk_size);
}

int get_chunk_nbr(t_stack *stack)
{
    int chunk_nbr;
    int i;

    chunk_nbr = 0;
    i = 0;
    while (i++ < stack->size)
    {
        if (stack->chunk > chunk_nbr)
            chunk_nbr = stack->chunk;
        stack = stack->next;
    }
    return (chunk_nbr);
}

int best_path_chunk(t_stack *stack, int chunk)
{
    t_stack *tmp;
    int     chunk_nbr;
    int     move_top;
    int     move_bottom;

    tmp = stack;
    move_top = 0;
    move_bottom = 0;
    chunk_nbr = get_chunk_nbr(stack) + 1;
    if (chunk > chunk_nbr || chunk < 0)
        return (INT_MAX);
    while (move_top < stack->size)
    {
        if (tmp->chunk == chunk)
            break ;
        move_top++;
        tmp = tmp->next;
    }
    tmp = stack->prev;
    while (--move_bottom > (stack->size * -1))
    {
        if (tmp->chunk == chunk)
            break ;
        tmp = tmp->prev;
    }
    if (move_top <= (move_bottom * -1))
        return (move_top);
    else
        return (move_bottom);
}
