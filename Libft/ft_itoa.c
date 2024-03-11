/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:56:30 by tvanbael          #+#    #+#             */
/*   Updated: 2022/10/29 14:35:00 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long int	ft_n_to_p(long int i)
{
	if (i < 0)
		i = (i - (i * 2));
	return (i);
}

static	long int	ft_n_or_p(long int i)
{
	long int	j;

	j = 0;
	if (i < 0)
		return (1);
	return (0);
}

static	long int	ft_h_l(long int i)
{
	long int	g;
	long int	h;

	g = 0;
	h = 0;
	if (i < 0)
		h = ft_n_to_p(i);
	if (h >= 0)
	{
		while (i)
		{
			i = i / 10;
			g++;
		}
	}
	if (i < 0)
		g = (g + 1);
	return (g);
}

static	char	*ft_what_a_mlc(long int i)
{
	long int		j;
	long int		h;
	long int		k;
	char			*finalint;

	j = 0;
	if (i < 0 || i > 0)
	{
		k = ft_h_l(i);
		finalint = malloc(sizeof(char) * (k + ft_n_or_p(i)) + 1);
		if (!finalint)
			return (NULL);
		h = (k + ft_n_or_p(i));
		finalint[h] = '\0';
	}
	else
	{
		finalint = malloc(sizeof(char) * 2);
		if (!finalint)
			return (NULL);
		finalint[0] = (i + 48);
		finalint[1] = '\0';
	}
	return (finalint);
}

char	*ft_itoa(int n)
{
	long int				k;
	long int				pon;
	char					*final;

	k = 0;
	pon = ft_n_to_p((long)n);
	final = ft_what_a_mlc((long)n);
	if (!final)
		return (NULL);
	if (n == 0)
		return (final);
	if ((long)n)
	{
		k = ((ft_h_l((long)n) + ft_n_or_p((long)n)) - 1);
		while (pon && k >= 0)
		{
			final[k--] = (pon % 10) + 48;
			pon = pon / 10;
		}
		if (ft_n_or_p((long)n) == 1)
			final[k] = '-';
	}
	return (final);
}
