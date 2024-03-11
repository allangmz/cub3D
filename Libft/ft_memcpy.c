/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:18:24 by tvanbael          #+#    #+#             */
/*   Updated: 2022/02/27 14:12:10 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < size)
	{
		(d[i] = s[i]);
		i++;
	}
	return (d);
}
