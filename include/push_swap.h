/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:38:12 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/11 18:53:29 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

# define PUSH_A "pa"
# define PUSH_B "pb"
# define SWAP_A "sa"
# define SWAP_B "sb"
# define SWAP_STACK "ss"
# define ROTATE_A "ra"
# define ROTATE_B "rb"
# define ROTATE_STACK "rr"
# define REV_ROTATE_A "rra"
# define REV_ROTATE_B "rrb"
# define REV_ROTATE_STACK "rrr"
# define ERROR "Error"

typedef struct s_stack
{
	int	data;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

t_stack	*fill_stack(int argc, char **argv);
void	lstadd_front(t_stack **node_first, t_stack **node_last, t_stack *new);
int		*args_to_tab(int argc, char **argv);
int		*quotes_to_tab(char **argv);
size_t	count_arg(int *tab);

#endif