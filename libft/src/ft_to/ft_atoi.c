/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:56:02 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/29 14:04:56 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_atoi(char *str)
{
	long long int	ct[3];

	if (!str || str[0] == 0)
		return (0);
	if (ft_isspace(*str))
		return (ft_atoi(str + 1));
	if (str[0] == '+' || str[0] == '-')
		ct[0] = 0;
	else
		ct[0] = -1;
	if (str[0] == '-')
		ct[2] = -1;
	else
		ct[2] = 1;
	ct[1] = 0;
	while (str[++ct[0]])
	{
		if (str[ct[0]] < '0' || str[ct[0]] > '9')
			return (ct[1] * ct[2]);
		ct[1] = 10 * ct[1] + str[ct[0]] - '0';
	}
	return (ct[1] * ct[2]);
}
