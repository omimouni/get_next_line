/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:06:50 by omimouni          #+#    #+#             */
/*   Updated: 2019/11/15 15:48:02 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line( int fd, char **line)
{
	int			n;
	char		*buffer;
	static char	*ptr;
	char		*tmp;
	int			i;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));

	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = '\0';
		if (ptr == NULL)
			ptr = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(ptr, buffer);
			free(ptr);
			ptr = tmp;
		}
		if (ft_strrchr(ptr, '\n'))
			break ;
	}
	i = 0;

	if (n == -1)
		return (-1);
	if (n == 0 && ptr == NULL)
		return (0);
	while (ptr[i] != '\n' && ptr[i] != '\0')
		i++;
	if(ptr[i] == '\n')
	{
		*line = ft_substr(ptr, 0, i);
		tmp = ft_strdup(ptr + i + 1);
		free(ptr);
		ptr = tmp;
	}
	else
	{
		*line = ft_strdup(ptr);
		free(ptr);
	}
	free(buffer);
	return (1);
}

