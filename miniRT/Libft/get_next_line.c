/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:51:07 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:51:10 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_for_all(t_memory *start)
{
	t_memory *temp;

	temp = start;
	while (temp)
	{
		start = start->next;
		if (temp->buffer)
		{
			free(temp->buffer);
			temp->buffer = 0;
		}
		temp->next = 0;
		free(temp);
		temp = 0;
		temp = start;
	}
}

int		ft_read_fd(t_memory **c_pointer, int *list_len, int fd)
{
	int			status;
	t_memory	*current;

	current = *c_pointer;
	status = 1;
	while (++(*list_len))
	{
		if (current->buffer && ft_check_newline(current->buffer))
			break ;
		else if (!(current->buffer))
		{
			current->buffer = malloc(BUFFER_SIZE + 1);
			status = read(fd, current->buffer, BUFFER_SIZE);
			if (status == -1)
				return (-1);
			*((current->buffer) + status) = 0;
		}
		if ((status == 0 || ft_check_newline(current->buffer)))
			break ;
		current->next = ft_new_struct(fd);
		current = current->next;
	}
	*c_pointer = current;
	return (status);
}

int		ft_setup(t_memory **s_pt, t_memory **c_pt, char *memory, int fd)
{
	*s_pt = ft_new_struct(fd);
	*c_pt = *s_pt;
	if (memory)
		(*s_pt)->buffer = memory;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*memory;
	t_memory		*start;
	t_memory		*current;
	int				list_len;
	int				status;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	*line = 0;
	list_len = ft_setup(&start, &current, memory, fd);
	status = ft_read_fd(&current, &list_len, fd);
	if (status == -1 || !(*line = malloc(BUFFER_SIZE * (list_len) + 1)))
		return (-1);
	ft_concatenate_buffers(start, *line);
	memory = ft_shift_string(current->buffer);
	ft_free_for_all(start);
	if (status == 0)
	{
		if (memory)
			free(memory);
		memory = 0;
		return (0);
	}
	return (1);
}
