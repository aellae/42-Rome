/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:27:11 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/02 16:10:01 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_string	*apix(int *i, char *input, int *j, t_string *list)
{
	char	apix;
	int		slash;

	apix = input[*i];
	(*i)++;
	while (input[*i])
	{
		slash = 0;
		if (input[*i] == '\\')
		{
			if (input[(*i) + 1] == '"' || input[(*i) + 1] == '\\')
			{
				(*i)++;
				slash = 1;
			}
		}
		if (input[*i] && input[*i] == apix && slash == 0)
			break ;
		list->s = charjoin(list->s, input[(*i)++], (*j)++);
	}
	if (input[*i] == apix)
		(*i)++;
	list->apix = apix;
	return (list);
}

int			spaces_list(t_string **list, int *i, char *input)
{
	while (is_spaces(input[*i]))
		(*i)++;
	(*list)->next = new_list();
	*list = (*list)->next;
	return (1);
}

void		found_symbol(t_string **list, char *input, int *i)
{
	(*list)->next = new_list();
	*list = (*list)->next;
	*((*list)->s) = input[*i];
	*((*list)->s + 1) = 0;
	(*list)->next = new_list();
	*list = (*list)->next;
	(*i)++;
}

t_string	*scan_list(char *input, int i, int j, t_string *list)
{
	while (is_spaces(input[i]))
		i++;
	while (input[i])
	{
		if (input[i] == '"' && (list = apix(&i, input, &j, list)))
			continue ;
		else if (input[i] == '\'' && (list = apix(&i, input, &j, list)))
			continue ;
		if (input[i] == '\\')
			i++;
		if (is_spaces(input[i]) && j > 0 && spaces_list(&list, &i, input))
			continue ;
		while (is_spaces(input[i]))
			i++;
		if (input[i] == '|' || input[i] == '>' ||
			input[i] == '<' || input[i] == ';')
			found_symbol(&list, input, &i);
		while (is_spaces(input[i]))
			i++;
		list->s = charjoin(list->s, input[i++], j++);
	}
	return (list);
}

t_string	*save_list(char *input)
{
	t_string	*list;
	t_string	*ret;

	list = new_list();
	ret = list;
	list = scan_list(input, 0, 0, list);
	return (ret);
}
