/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:08:54 by efunes            #+#    #+#             */
/*   Updated: 2022/10/29 15:50:42 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freetab(char **tabtab, int i)
{
	while (i >= 0)
	{
		if (tabtab[i])
			free(tabtab[i]);
		i--;
	}
	free(tabtab);
	return (NULL);
}

int	ft_strlen_to_sep(char *s, char sep)
{
	int	index;

	index = 0;
	while (s[index] && s[index] != sep)
		index++;
	return (index);
}

int	ft_count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

char	*ft_put_in_tab(char *s, char c)
{
	int		j;
	char	*word;

	j = 0;
	if (!s)
		return (NULL);
	word = malloc(sizeof(char) * (ft_strlen_to_sep(s, c) + 1));
	if (!word)
		return (NULL);
	while (s[j] && s[j] != c)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**taboftab;
	int		count;

	j = 0;
	if (!s)
		return (NULL);
	count = ft_count_word((char *)s, c);
	taboftab = malloc(sizeof(char *) * (count + 1));
	if (!taboftab || taboftab == 0)
		return (NULL);
	while (*s && j < count)
	{
		if (*s != c && j++ > -1)
		{
			taboftab[j - 1] = ft_put_in_tab((char *)s, c);
			if (!taboftab[j - 1] && *s)
				return (ft_freetab(taboftab, j - 0));
			while (*s && *s != c)
				s++;
		}
		s++;
	}
	taboftab[j] = NULL;
	return (taboftab);
}
