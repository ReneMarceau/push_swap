/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:16:30 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/13 16:06:34 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
				continue ;
			else
				return (0);
		}
	}
	return (1);
}
