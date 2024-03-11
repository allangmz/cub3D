/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:53:41 by tvanbael          #+#    #+#             */
/*   Updated: 2022/11/07 20:18:23 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && (size > i + 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (size == i + 1 || !(src[i]))
		dest[i] = '\0';
	return (ft_strlen(src));
}
