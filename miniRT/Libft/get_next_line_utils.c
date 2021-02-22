/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:51:15 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:51:19 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_concatenate_buffers(t_memory *source, char *line)
{
	unsigned int i;
	unsigned int n;

	i = 0;
	while (source)
	{
		n = 0;
		while (source->buffer && *((source->buffer) + n) &&
			*((source->buffer) + n) != '\n')
		{
			line[i] = *((source->buffer) + n);
			i++;
			n++;
		}
		source = source->next;
	}
	line[i] = 0;
	return (i);
}

t_memory	*ft_new_struct(int fd)
{
	t_memory *node;

	node = (t_memory *)malloc(sizeof(t_memory));
	if (!node)
		return (0);
	node->fd = fd;
	node->next = 0;
	node->buffer = 0;
	return (node);
}

int			ft_check_newline(char *reading)
{
	unsigned int i;

	if (!reading)
	{
		return (0);
	}
	i = 0;
	while (reading[i])
	{
		if (reading[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char		*ft_shift_string(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (*str != 0 && *str != '\n')
		str++;
	if (!(ret = malloc(BUFFER_SIZE + 1)))
		return (0);
	if (*str != 0)
	{
		while (*(++str) != 0)
			ret[i++] = *(str);
	}
	ret[i] = 0;
	return (ret);
}
