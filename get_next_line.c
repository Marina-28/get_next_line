/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:32:01 by bjeana            #+#    #+#             */
/*   Updated: 2021/10/29 17:58:06 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*ft_check_ost(char *ost, char **line, char **ptr)
{
	char	*temp;

	*ptr = ft_strchr(ost, 10);
	if (ost == NULL)
	{
		*line = (char *)malloc(1 * sizeof(char));
		if (*line == NULL)
			return (NULL);
		*line[0] = '\0';
	}
	else if (ost != NULL && *ptr != NULL)
	{
		*line = ft_strdup(ost, '\n');
		temp = ost;
		ost = ft_strdup(*ptr + 1, '\0');
		free(temp);
	}
	else if (ost != NULL && *ptr == NULL)
	{
		*line = ft_strdup(ost, '\0');
		free(ost);
		return (NULL);
	}
	return (ost);
}

char	*ft_free(char *line, char *str, char *ptr, int a)
{
	char	*temp;

	if (a == -1)
	{
		free(line);
		free(str);
		return (NULL);
	}
	temp = line;
	line = ft_strjoin(line, str);
	free(temp);
	if (ptr != NULL)
	{
		temp = line;
		line = ft_strjoin(line, "\n");
		free(temp);
	}
	return (line);
}

char	*create_buf(void)
{
	char	*buf;

	if (BUFFER_SIZE > 0)
	{
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buf == NULL)
			return (NULL);
	}
	else
		return (NULL);
	return (buf);
}

int	read_buf(int fd, char *buf)
{
	int	i;

	i = read(fd, buf, BUFFER_SIZE);
	buf[i] = '\0';
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	char		*ptr;
	static char	*ost;
	int			i;

	i = 1;
	buf = create_buf();
	ost = ft_check_ost(ost, &line, &ptr);
	while (i && ptr == NULL && buf != NULL)
	{
		i = read_buf(fd, buf);
		if ((i == 0 && buf[0] == '\0' && line[0] == '\0') || i == -1)
			return (ft_free(line, buf, ptr, -1));
		ptr = ft_strchr(buf, '\n');
		if (ft_strchr(buf, '\n'))
		{
			*ptr = '\0';
			ost = ft_strdup((ptr + 1), '\0');
		}
		line = ft_free(line, buf, ptr, 0);
	}
	free(buf);
	return (line);
}
