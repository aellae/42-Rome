/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:24:59 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/02 16:06:07 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_comm		*new_node(void)
{
	t_comm *new;

	if (!(new = malloc(sizeof(t_comm))))
		return (0);
	new->next = 0;
	new->command = 0;
	new->arguments = 0;
	new->fdin = 0;
	new->fdout = 0;
	new->pipe = 0;
	return (new);
}

t_string	*new_list(void)
{
	t_string *new;

	if (!(new = malloc(sizeof(t_string))))
		return (0);
	if (!(new->s = malloc(1)))
		return (0);
	new->s[0] = 0;
	new->apix = 0;
	new->next = 0;
	return (new);
}
