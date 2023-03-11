/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:38:12 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/11 16:02:23 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

# define ERROR "Error\n"

typedef struct s_stack
{
	int	data;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

t_stack	*fill_stack(char **args, int len);
void	lstadd_front(t_stack **node_first, t_stack **node_last, t_stack *new);
int	len_arg(char **tab);

#endif