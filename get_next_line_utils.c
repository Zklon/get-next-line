/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrito- <lubrito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:34:39 by lubrito-          #+#    #+#             */
/*   Updated: 2024/05/11 19:58:28 by lubrito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	i;

	ret = (void *)malloc(nmemb * size);
	if (ret)
	{
		i = 0;
		while (i < nmemb * size)
			*((unsigned char *) ret + i++) = 0;
	}
	return (ret);
}

void	buffer_corrector(char *buffer)
{
	char	*buffer_nl;
	int		i;
	int		len;

	buffer_nl = ft_strchr(buffer, '\n');
	i = 0;
	if (buffer_nl)
	{
		len = ft_strlen(buffer_nl + 1);
		while (i < len)
		{
			buffer[i] = buffer_nl[i + 1];
			i++;
		}
		while (i < BUFFER_SIZE)
			buffer[i++] = 0;
	}
	else
	{
		while (i < BUFFER_SIZE)
			buffer[i++] = 0;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = (size_t)-1;
	j = 0;
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	str[i] = s2[j];
	if (s2[j] == '\n')
		str[i++] = '\0';
	buffer_corrector(s2);
	free(s1);
	return (str);
}
