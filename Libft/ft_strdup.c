/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:32:49 by tvanbael          #+#    #+#             */
/*   Updated: 2022/02/27 19:59:50 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	const char	*str2;
	size_t		i;

	i = 0;
	i = ft_strlen((char *)str) + 1;
	str2 = malloc(sizeof(char) * i);
	if (!str2)
		return (NULL);
	ft_strlcpy((char *)str2, str, i);
	return ((char *)str2);
}
