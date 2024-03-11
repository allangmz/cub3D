/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:50:57 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/02 18:01:06 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if ((char)c == '\0')
		return (&*(char *)(s + i));
	while (s[i] != (char)c && i >= 0)
		i--;
	if (s[i] == (char)c)
		return (&*(char *)(s + i));
	else
		return (NULL);
}
