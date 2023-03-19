/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:27:46 by bjeana            #+#    #+#             */
/*   Updated: 2021/10/29 17:58:42 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *s1, char c);
char	*ft_check_ost(char *ost, char **line, char **ptr);
char	*create_buf(void);
char	*ft_free(char *line, char *str, char *ptr, int a);
int		read_buf(int fd, char *buf);
#endif
