/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:20:23 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/28 15:42:52 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Counts the number of arguments inside a vector of numbers
int	count_arg(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

//Fill an array of int the values passed to the program is a string
int	*quotes_to_tab(char **argv, int *size)
{
	char	**tab_char;
	int		*tab;
	int		i;

	tab_char = ft_split(argv[1], ' ');
	*size = count_arg(tab_char);
	tab = (int *)ft_calloc(*size, sizeof(int));
	i = -1;
	while (tab_char[++i])
	{
		if (ft_isnumber(tab_char[i]) && ft_strlen(tab_char[i]) < 12)
			tab[i] = ft_atoi(tab_char[i]);
		else
		{
			free(tab);
			free_2d(tab_char, *size);
			return (NULL);
		}
	}
	free_2d(tab_char, *size);
	return (tab);
}

//Fill an array of int the values passed to the program are arguments
int	*args_to_tab(int argc, char **argv, int *size)
{
	int		*tab;
	int		i;
	int		j;

	*size = argc - 1;
	tab = (int *)ft_calloc(*size, sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (i++ < *size)
	{
		if (ft_isnumber(argv[i]) && ft_strlen(argv[i]) < 12)
			tab[j++] = ft_atoi(argv[i]);
		else
		{
			free(tab);
			return (NULL);
		}
	}
	return (tab);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
