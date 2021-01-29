/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:26:26 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/17 09:26:29 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	shift_buff(char *buffer, size_t index)
{
	size_t j;

	j = 1;
	while (buffer[index + j])
	{
		buffer[j - 1] = buffer[index + j];
		j++;
	}
	buffer[j - 1] = 0;
}

int		put_line(char *buffer, char **line)
{
	size_t	index;
	size_t	mlen;

	if (*line)
		mlen = ft_strlen(*line);
	else
		mlen = 0;
	if (!(ft_realloc(line, (BUFFER_SIZE + mlen + 1))))
		return (-1);
	index = 0;
	while (buffer[index])
	{
		if (buffer[index] == '\n')
		{
			(*line)[mlen + index] = 0;
			shift_buff(buffer, index);
			return (1);
		}
		(*line)[mlen + index] = buffer[index];
		index++;
	}
	(*line)[mlen + index] = 0;
	return (0);
}

int		read_error(char **line)
{
	if (*line)
		free(*line);
	*line = 0;
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*node;
	int				checkl;
	int				checkr;

	if (BUFFER_SIZE <= 0 || fd < 0 || (!head && !(head = find_fd(&head, fd))) ||
		!(node = find_fd(&head, fd)) || !line)
		return (-1);
	*line = 0;
	if ((checkl = put_line(node->buffer, line)))
		return (checkl);
	while ((checkr = read(fd, node->buffer, BUFFER_SIZE)) > 0)
	{
		node->buffer[checkr] = 0;
		if ((checkl = put_line(node->buffer, line)))
			return (checkl);
	}
	free_node(&head, node);
	if (checkr < 0)
		return (read_error(line));
	return (0);
}
