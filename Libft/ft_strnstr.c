/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:33:44 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/02 18:57:13 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *srch, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!len && !(*srch))
		return ((char *)str);
	if (!len)
		return (NULL);
	if ((!srch && !len) || (srch[0] == '\0') || !len)
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (srch[j] && srch[j] == str[i + j] && i + j < len)
		{
			if (srch[j + 1] == '\0')
			{
				return ((char *)(str + i));
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
