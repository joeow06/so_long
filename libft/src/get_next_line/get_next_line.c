/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:21:53 by jow               #+#    #+#             */
/*   Updated: 2024/07/03 19:12:21 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/get_next_line.h"

static char	*set_line(char *line)
{
	int		i;
	char	*left_str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	left_str = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!left_str)
		return (NULL);
	if (left_str[0] == '\0')
	{
		free (left_str);
		left_str = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (left_str);
}

static char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if ((unsigned char)c == *str)
			return ((char *)(str));
		str++;
	}
	if (c == '\0')
		return ((char *)(str));
	return (NULL);
}

static char	*find_next_line(int fd, char *left_str, char *buffer)
{
	ssize_t	char_read;
	char	*temp;

	char_read = 1;
	while (char_read > 0)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == -1)
			return (NULL);
		else if (char_read == 0)
			break ;
		buffer[char_read] = '\0';
		if (!left_str)
			left_str = ft_strdup("");
		temp = left_str;
		left_str = ft_strjoin(temp, buffer);
		if (!left_str)
			return (NULL);
		free(temp);
		temp = NULL;
		if (ft_strchr(left_str, '\n'))
			break ;
	}
	return (left_str);
}

char	*get_next_line(int fd)
{
	static char	*left_str;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = find_next_line(fd, left_str, buffer);
	free(buffer);
	if (!line)
	{
		free(left_str);
		left_str = NULL;
		return (NULL);
	}
	left_str = set_line(line);
	return (line);
}
