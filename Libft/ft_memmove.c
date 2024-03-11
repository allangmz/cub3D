/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:15:05 by tvanbael          #+#    #+#             */
/*   Updated: 2022/02/27 17:23:34 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (!src && !dest)
		return (NULL);
	if (dest > src)
	{
		while (len-- > 0)
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
	}
	else if (len > 0)
			dest = ft_memcpy(dest, src, len);
	return (dest);
}
