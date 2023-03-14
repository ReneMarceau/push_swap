/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:40:56 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/13 16:11:22 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	// Test display
	int		i;

	i = 0;
	if (argc >= 2)
	{
		stack_a = fill_stack(argc, argv);
		if (!stack_a)
		{
			ft_putendl_fd(ERROR, 2);
			exit(EXIT_FAILURE);
		}
		stack_b = NULL;
		// Test display
		while (i < 4)
		{
			ft_printf("%d\n", stack_a->data);
			stack_a = stack_a->next;
			i++;
		}
	}
	return (0);
}
