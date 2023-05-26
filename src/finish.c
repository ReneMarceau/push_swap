/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:38:50 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/26 13:44:30 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Free 2d array of char
void	free_2d(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}

//Free every node in the linked list
static void	free_lst(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (stack)
	{
		while (i++ < stack->size)
		{
			tmp = stack->next;
			free(stack);
			stack = tmp;
		}
	}
}

//Terminate the program with an error message if needed
void	end_program(t_stack *stack_a, t_stack *stack_b, bool error)
{
	if (stack_a)
		free_lst(stack_a);
	if (stack_b)
		free_lst(stack_b);
	if (error)
	{
		ft_putendl_fd(ERROR, 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

