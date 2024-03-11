/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:56:48 by tvanbael          #+#    #+#             */
/*   Updated: 2023/01/16 15:33:17 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	const char		*j;
	const char		*k;

	j = s1;
	k = s2;
	i = 0;
	if (n == 0)
		return (0);
	n = n - 1;
	while (j[i] == k[i] && j[i] != '\0' && k[i] != '\0' && i < n)
		i++;
	return ((unsigned char)j[i] - (unsigned char)k[i]);
}
