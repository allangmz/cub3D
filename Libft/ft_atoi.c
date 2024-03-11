/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:57:54 by tvanbael          #+#    #+#             */
/*   Updated: 2022/03/01 14:18:14 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		res;
	int		i;
	char	*str2;

	res = 0;
	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' && i++ == 0)
		str++;
	else if (*str == '+')
		str++;
	str2 = (char *)str;
	while (*str2 >= '0' && *str2 <= '9')
		str2++;
	if ((str2 - str) > 10 && i == 0)
		return (-1);
	else if ((str2 - str) > 10 && i == 1)
		return (0);
	while ((*str >= '0' && *str <= '9'))
		res = res * 10 + *str++ - 48;
	if (i != 0)
		res -= (res * 2);
	return (res);
}
