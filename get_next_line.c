/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:16:59 by omimouni          #+#    #+#             */
/*   Updated: 2019/11/25 22:24:25 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_buffer(int fd, char **ptr)
{
	char	*buffer;
	char	*tmp;
	int		n;

	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = '\0';
		if (*ptr == NULL)
			*ptr = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(*ptr, buffer);
			free(*ptr);
			*ptr = tmp;
		}
		if (ft_strchr(*ptr, '\n'))
			break ;
	}
	free(buffer);
	return (n);
}

int	ft_set_line(char **ptr, int len, char **line)
{
	char	*tmp;

	if ((*ptr)[len] == '\n')
	{
		free(*line);
		*line = ft_substr(*ptr, 0, len);
		tmp = ft_strdup(*ptr + len + 1);
		free(*ptr);
		*ptr = tmp;
	}
	else
	{
		free(*line);
		*line = ft_strdup(*ptr);
		free(*ptr);
		*ptr = NULL;
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*ptr[1024];
	int			n;
	int			len;

	n = ft_read_buffer(fd, &ptr[fd]);
	if (n < 0)
		return (-1);
	*line = ft_strdup("");
	if (n == 0 && (ptr[fd] == NULL))
		return (0);
	len = 0;
	while (ptr[fd][len] != '\n' && ptr[fd][len] != '\0')
		len++;
	return (ft_set_line(&ptr[fd], len, line));
}
