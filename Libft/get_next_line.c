/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbael <tvanbael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:16:06 by tvanbael          #+#    #+#             */
/*   Updated: 2023/02/07 11:18:14 by tvanbael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr_gnl(char *line, char nl)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] == nl)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin_gnl(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	ret = malloc(ft_strlen_gnl(line) + ft_strlen_gnl(buffer) + 1);
	if (!ret)
		return (NULL);
	if (line)
	{
		while (line[i])
		{
			ret[i] = line[i];
			i++;
		}
	}
	j = 0;
	while (buffer[j])
		ret[i++] = buffer[j++];
	ret[i] = '\0';
	free(line);
	return (ret);
}

char	*ft_check(int fd, char *buffer, char *line, int ret)
{
	while (ret > 0 && ft_strchr_gnl(line, '\n'))
	{
		line = ft_strjoin_gnl(line, buffer);
		ret = read(fd, buffer, 1);
		buffer[ret] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd, int mod)
{
	static int	ret;
	static char	buffer[BUFFER_SIZE / BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (ret == 0 || mod)
	{
		ret = read(fd, buffer, 1);
		buffer[ret] = '\0';
	}
	if (ret > 0 && buffer[0] != '\0')
		line = ft_check(fd, buffer, line, ret);
	else
		return (NULL);
	return (line);
}
