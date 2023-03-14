/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:38:40 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/13 21:24:11 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_repeat(int *tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
	}
	return (1);
}

int	is_sorted(int *tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (tab[i] > tab[j])
				return (0);
			j++;
		}
	}
	return (1);
}
