/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:55:39 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/13 17:20:10 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*csrc;
	unsigned char		*cdst;
	size_t				i;

	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	i = 0;
	if (!(dst || src))
		return (NULL);
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
