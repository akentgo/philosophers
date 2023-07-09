/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:54:10 by akent-go          #+#    #+#             */
/*   Updated: 2023/04/11 16:51:33 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*srcs;

	str = (unsigned char *)dst;
	srcs = (unsigned char *)src;
	if (!str && !srcs)
		return (NULL);
	while (n--)
		*str++ = *srcs++;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 && !s2)
		return (0);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}
