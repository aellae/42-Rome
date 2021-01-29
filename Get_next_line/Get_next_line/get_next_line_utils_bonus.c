/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:26:53 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/17 09:26:57 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_realloc(char **ptr, size_t rlen)
{
	char	*ptmem;
	size_t	index;

	if (!(ptmem = (char *)malloc(rlen)))
		return (0);
	index = 0;
	while (index < (rlen - BUFFER_SIZE - 1))
	{
		ptmem[index] = (*ptr)[index];
		index++;
	}
	ptmem[index] = 0;
	free(*ptr);
	*ptr = ptmem;
	return (ptmem);
}

void	free_node(t_list **head, t_list *node)
{
	t_list *iter;

	iter = *head;
	if (*head == node)
	{
		*head = (*head)->next;
		free(iter);
		return ;
	}
	while (iter && iter->next != node)
		iter = iter->next;
	iter->next = node->next;
	free(node);
}

t_list	*new_node(int fd)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (0);
	node->fd = fd;
	node->buffer[0] = 0;
	node->next = 0;
	return (node);
}

t_list	*find_fd(t_list **head, int fd)
{
	t_list	*othern;

	othern = *head;
	if (!*head)
	{
		if (!(*head = new_node(fd)))
			return (0);
		return (*head);
	}
	if ((*head)->fd == fd)
		return (*head);
	while (othern->next)
	{
		if (othern->next->fd == fd)
			return (othern->next);
		othern = othern->next;
	}
	if (!(othern->next = new_node(fd)))
		return (0);
	return (othern->next);
}
