/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:17:15 by akent-go          #+#    #+#             */
/*   Updated: 2023/04/11 16:50:43 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_last_line(char **mem)
{
	int		n_line;
	int		n_size;
	char	*n_mem;

	if (*mem == NULL)
	{
		*mem = (char *)malloc(sizeof(char));
		**mem = '\0';
		return ;
	}
	n_line = line_length(*mem);
	n_size = ft_strlen(&(*mem)[n_line]) + 1;
	n_mem = (char *)malloc(sizeof(char) * n_size);
	ft_memcpy(n_mem, &(*mem)[n_line], n_size);
	free(*mem);
	*mem = n_mem;
}

int	copy_to_mem(char **mem, int fd)
{
	int		read_value;
	char	*temp;
	char	buff[BUFFER_SIZE + 1];

	clear_last_line(mem);
	read_value = 1;
	while (!ft_strchr(*mem, '\n') && read_value)
	{
		read_value = read(fd, buff, BUFFER_SIZE);
		if (read_value < 1)
			return (read_value);
		buff[read_value] = '\0';
		temp = *mem;
		*mem = ft_strjoin(*mem, buff);
		free(temp);
	}
	return (read_value);
}

char	*read_line(char **mem)
{
	int		it;
	int		l_len;
	char	*sol;

	l_len = line_length(*mem);
	if (l_len == 0)
		return (NULL);
	sol = (char *)malloc(sizeof(char) * (l_len + 1));
	it = 0;
	while (it < l_len)
	{
		sol[it] = (*mem)[it];
		it++;
	}
	sol[it] = '\0';
	return (sol);
}

int	line_length(char *mem)
{
	int	sol;

	sol = 0;
	while (mem[sol] != '\0' && mem[sol] != '\n')
		sol++;
	if (mem[sol] == '\n')
		sol++;
	return (sol);
}

char	*get_next_line(int fd)
{
	static char	*mem = NULL;
	char		*line;

	if (copy_to_mem(&mem, fd) == -1)
	{
		free(mem);
		mem = NULL;
		return (NULL);
	}
	line = read_line(&mem);
	if (!line)
	{
		free(mem);
		mem = NULL;
	}
	return (line);
}
