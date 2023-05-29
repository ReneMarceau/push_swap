/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:20:23 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/29 01:53:00 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Returns the absolute value of a number
int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

// Counts the number of arguments inside a vector of numbers
int	count_arg(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

// Check if there are no repeated numbers inside the array
bool	is_repeat(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

// Check if the array is already sorted
bool	is_sorted(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

// Calculates the size of a specific chunk
int	get_chunk_size(t_container *data, int chunk)
{
	t_stack	*current;
	int		chunk_size;
	int		i;

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
