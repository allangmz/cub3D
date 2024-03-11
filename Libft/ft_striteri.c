/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:04:11 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/02 09:22:31 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		j;
	int		k;

	j = 0;
	if ((s) && (f))
	{
		if (s != (NULL) && f != (NULL))
		{
			k = ft_strlen(s);
			while (j < k)
			{
				(*f)(j, s);
				j++;
				s++;
			}
		}
	}
}
