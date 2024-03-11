/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:43:51 by tvanbael          #+#    #+#             */
/*   Updated: 2022/02/25 17:21:47 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			index;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	index = 0;
	if (!len)
		return (0);
	while ((str1[index] == str2[index]) && index < len - 1)
		index++;
	return (str1[index] - str2[index]);
}
