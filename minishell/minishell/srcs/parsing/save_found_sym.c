/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:26:57 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/02 15:50:53 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		found_pipe(int *fd, t_comm **curr, t_string **string, int *j)
{
	t_string	*tmp;
	int			size;

	tmp = *string;
	size = 1;
	if (!(strcmp((*string)->next->s, ">")) ||
		!(strcmp((*string)->next->s, "<")))
	{
		*string = (*string)->next;
		return (0);
	}
	while (tmp && size++)
		tmp = tmp->next;
	pipe(fd);
	(*curr)->fdout = fd[1];
	*string = (*string)->next;
	(*curr)->arguments[*j] = 0;
	(*curr)->next = new_node();
	(*curr) = (*curr)->next;
	*j = 0;
	(*curr)->arguments = malloc(sizeof(char *) * size);
	(*curr)->pipe = 1;
	(*curr)->fdin = fd[0];
	return (1);
}

int		found_major(t_comm **curr, t_string **string)
{
	if ((*curr)->fdout != 0)
		close((*curr)->fdout);
	if (!ft_strcmp((*string)->next->s, ">"))
	{
		if (((*curr)->fdout = open((*string)->next->next->s,
			O_RDWR | O_CREAT | O_APPEND, 0644)) < 0)
		{
			printf("OPEN ERROR\n");
			return (0);
		}
		(*string) = (*string)->next;
	}
	else if (((*curr)->fdout = open((*string)->next->s,
			O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)
	{
		printf(RED"Open error\n"RESET);
		return (0);
	}
	(*string) = (*string)->next->next;
	return (1);
}

int		found_minus(t_comm **curr, t_string **string)
{
	if ((*curr)->fdin != 0)
		close((*curr)->fdin);
	if (((*curr)->fdin = open((*string)->next->s, O_RDONLY, 0644)) < 0)
	{
		printf(RED"Æ → %s: No such file or directory\n"RESET,
			(*string)->next->s);
		g_lo.t_q = 1;
		return (0);
	}
	(*string) = (*string)->next->next;
	return (1);
}

void	add_comm(t_string **string, t_comm **curr)
{
	if (ft_strcmp((*string)->s, ";") == 0)
		(*string) = (*string)->next;
	if ((*curr)->pipe == 0)
	{
		(*curr)->next = new_node();
		(*curr) = (*curr)->next;
	}
	(*curr)->pipe = 0;
}

void	add_arg(t_string **string, t_comm **curr, int *j)
{
	if ((*string)->s && *(*string)->s != 0)
		(*curr)->arguments[(*j)++] = ft_strdup((*string)->s);
	(*string) = (*string)->next;
}
