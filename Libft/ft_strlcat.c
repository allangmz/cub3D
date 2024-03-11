/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:57:37 by tvanbael          #+#    #+#             */
/*   Updated: 2022/10/29 16:00:50 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	cpt;
	size_t	cpt2;

	cpt = 0;
	cpt2 = 0;
	if (!dstsize && src)
		return (ft_strlen((char *)src) + dstsize);
	else if (!dstsize)
		return (dstsize);
	i = (ft_strlen(dst));
	while (dst[cpt])
		cpt++;
	while (cpt < dstsize - 1 && src[cpt2])
		dst[cpt++] = src[cpt2++];
	dst[cpt] = '\0';
	if (dstsize >= i)
		return (i + (ft_strlen((char *)src)));
	return (ft_strlen((char *)src) + dstsize);
}
