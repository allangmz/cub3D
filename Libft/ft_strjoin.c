/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:53:10 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/01 10:56:03 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		count;
	int		h;

	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	final = malloc((ft_strlen((char *)s1) + (ft_strlen((char *)s2) + 1)));
	if (!final)
		return (NULL);
	count = 0;
	h = 0;
	while (s1[count])
		final[h++] = s1[count++];
	count = 0;
	while (s2[count])
		final[h++] = s2[count++];
	final[h] = '\0';
	return (final);
}
