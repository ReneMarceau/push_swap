/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:40:56 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/11 16:04:22 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		stack_a = fill_stack(ft_split(argv[1], ' '), len_arg(args) - 1);
		while (i < len_arg(args))
		{
			ft_printf("%d\n", stack_a->data);
			stack_a = stack_a->next;
			i++;
		}
	}
	else
		ft_putstr_fd(ERROR, 2);
	return (0);
}
