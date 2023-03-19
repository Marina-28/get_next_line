/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:31:49 by bjeana            #+#    #+#             */
/*   Updated: 2021/10/29 18:03:00 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] != c) && (s[i] != '\0'))
		i++;
	if (s[i] != c)
		return (NULL);
	return (&s[i]);
}

static void	ft_fill(char *s1, char *s2, char *str, int len)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (n < len)
	{
		while (s1[i] != '\0')
		{
			str[n] = s1[i];
			n++;
			i++;
		}
		if (s2[j] != '\0')
		{
			str[n] = s2[j];
			j++;
			n++;
		}
	}
	str[n] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	len = i + j;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_fill(s1, s2, str, len);
	return (str);
}

char	*ft_strdup(char *s1, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s1[i] != '\0' && s1[i] != c)
		i++;
	if (s1[i] == c && c != '\0')
		i = i + 1;
	str = (char *)malloc((i + 1) * (sizeof(char)));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && s1[i] != c)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = s1[i];
	if (s1[i] == c && c != '\0')
		str[i + 1] = '\0';
	return (str);
}
