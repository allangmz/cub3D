/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:42:06 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/06 10:01:18 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tab;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((ft_strlen((char *)s) <= (int)start))
	{
		tab = malloc(sizeof(char));
		if (!tab)
			return (NULL);
		*tab = 0;
		return (tab);
	}
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (len-- > 0)
		(tab[i++] = s[start++]);
	tab[i] = '\0';
	return (tab);
}
