/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:20:23 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/13 21:19:56 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <string.h>

size_t	count_arg(int *tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*quotes_to_tab(char **argv)
{
	char	**tab_char;
	int		*tab;
	int		i;

	tab_char = NULL;
	tab = NULL;
	i = -1;
	tab_char = ft_split(argv[1], ' ');
	if (!tab_char)
		return (NULL);
	tab = (int *)ft_calloc(sizeof(tab_char), sizeof(int));
	if (!tab)
		return (NULL);
	while (tab_char[++i])
	{
		if (ft_isnumber(tab_char[i]))
			tab[i] = ft_atoi(tab_char[i]);
		else
			return (NULL);
	}
	free(tab_char);
	return (tab);
}

int	*args_to_tab(int argc, char **argv)
{
	int		*tab;
	size_t	i;
	size_t	j;

	tab = (int *)ft_calloc(argc - 1, sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while ((int)++i < argc)
	{
		if (ft_isnumber(argv[i]))
		{
			tab[j] = ft_atoi(argv[i]);
			j++;
		}
		else
			return (NULL);
	}
	return (tab);
}
