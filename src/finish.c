/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:38:50 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/04 11:46:17 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Free every node in the linked list
static void	free_lst(t_stack *stack, int size)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (stack)
	{
		while (i++ < size)
		{
			tmp = stack->next;
			free(stack);
			stack = tmp;
		}
	}
}

//Terminate the program when an error occured
void	end_failure(t_stack *stack_a, t_stack *stack_b, int size_a, int size_b)
{
	if (stack_a)
		free_lst(stack_a, size_a);
	if (stack_b)
		free_lst(stack_b, size_b);
	ft_putendl_fd(ERROR, 2);
	exit(EXIT_FAILURE);
}

//Terminate the program successfully
void	end_success(t_stack *stack_a, t_stack *stack_b, int size_a, int size_b)
{
	if (stack_a)
		free_lst(stack_a, size_a);
	if (stack_b)
		free_lst(stack_b, size_b);
	exit(EXIT_SUCCESS);
}

//Free 2d array of char
void	free_2d(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}
