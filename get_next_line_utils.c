/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:48:55 by omimouni          #+#    #+#             */
/*   Updated: 2019/11/15 10:00:16 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		x;

	x = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			x = i;
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	if (x == -1)
		return (NULL);
	else
		return ((char*)s + x);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(s1) + 1;
	if (!(ptr = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	ptr[--i] = '\0';
	while (i + 1)
	{
		ptr[i] = s1[i];
		i--;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	p;
	size_t	q;
	size_t	i;
	char	*tmp;

	p = ft_strlen(s1);
	q = ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (p + q + 1))))
		return (NULL);
	i = 0;
	tmp = (char *)s1;
	while (*tmp)
		ptr[i++] = *tmp++;
	tmp = (char *)s2;
	while (*tmp)
		ptr[i++] = *tmp++;
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	l;

	l = 0;
	if (start > ft_strlen(s))
	{
		if (!(ptr = (char *)malloc(1)))
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	while (l < len && s[l + start] != '\0')
		l++;
	if (!(ptr = (char *)malloc(sizeof(char) * l + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
