/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:31:07 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/26 19:03:56 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    push_selected_chunk(t_stack **stack_a, t_stack **stack_b, int chunk, bool is_bottom)
{
    int repeat_movement;

    repeat_movement = best_path_chunk(*stack_a, chunk);
    if (repeat_movement > 0)
    {
        if ((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->chunk == (*stack_a)->next->chunk)
            sa(stack_a);
        while (repeat_movement-- > 0)
            ra(stack_a);
    }
    else
    {
        if ((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->chunk == (*stack_a)->next->chunk)
            sa(stack_a);
        while (repeat_movement++ < 0)
            rra(stack_a);
    }
    pb(stack_a, stack_b);
    if (is_bottom)
        rb(stack_b);
}

static void    push_chunks_to_b(t_stack **stack_a, t_stack **stack_b)
{
    int chunk_top;
    int chunk_bottom;
    int chunk_size_top;
    int chunk_size_bottom;

    chunk_top = 1;
    chunk_bottom = 0;
    chunk_size_top = get_chunk_size(*stack_a, chunk_top);
    chunk_size_bottom = get_chunk_size(*stack_a, chunk_bottom);
    while (stack_a)
    {
        if (chunk_size_bottom == 0)
        {
            chunk_bottom++;
            if (chunk_bottom == chunk_top)
                chunk_size_top = 0;
            chunk_size_bottom = get_chunk_size(*stack_a, chunk_bottom);
        }
        if (chunk_size_top == 0)
        {
            chunk_top++;
            chunk_size_top = get_chunk_size(*stack_a, chunk_top);
        }
        if (best_path_chunk(*stack_a, chunk_top) < best_path_chunk(*stack_a, chunk_bottom))
        {
            push_selected_chunk(stack_a, stack_b, chunk_top, false);
            chunk_size_top--;
        }
        else
        {
            push_selected_chunk(stack_a, stack_b, chunk_bottom, true);
            chunk_size_bottom--;
        }
    }
}

int get_last_index(t_stack *stack)
{
    int last_index;
    int i;

    last_index = stack->index;
    i = 0;
    while (i++ < stack->size)
    {
        if (stack->index > last_index)
            last_index = stack->index;
        stack = stack->next;
    }
    return (last_index);
}

int    best_path_index(t_stack *stack, int index)
{
    t_stack *tmp;
    int move_top;
    int move_bottom;

    tmp = stack;
    move_top = 0;
    move_bottom = 0;
    while (move_top < stack->size)
    {
        if (tmp->index == index)
            break;
        move_top++;
        tmp = tmp->next;
    }
    tmp = stack->prev;
    while (--move_bottom > (stack->size * -1))
    {
        if (tmp->index == index)
            break;
        tmp = tmp->prev;
    }
    if (move_top <= (move_bottom * -1))
        return (move_top);
    else
        return (move_bottom);
}

void    push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
    int repeat_movement;
    int last_index;

    last_index = get_last_index(*stack_b);
    while (stack_b)
    {
        repeat_movement = best_path_index(*stack_b, last_index);
        if (repeat_movement > 0)
        {
            while (repeat_movement-- > 0)
                rb(stack_b);
        }
        else
        {
            while (repeat_movement++ < 0)
                rrb(stack_b);
        }
        pa(stack_a, stack_b);
        last_index--;
        //display_all(*stack_a, *stack_b);
    }
}

void    sort_big(t_stack **stack_a, t_stack **stack_b)
{
    push_chunks_to_b(stack_a, stack_b);
    push_back_to_a(stack_a, stack_b);
}