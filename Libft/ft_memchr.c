/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:54:30 by tvanbael          #+#    #+#             */
/*   Updated: 2022/02/27 17:27:05 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*s;
	unsigned char	lettre;
	size_t			index;

	s = (unsigned char *)str;
	lettre = (unsigned char) c;
	index = -1;
	while (++index < len)
	{
		if (s[index] == lettre)
			return (&s[index]);
	}
	return (NULL);
}
