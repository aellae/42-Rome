/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:23:21 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/02 16:05:58 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_comm(t_comm *head)
{
	t_comm	*curr;
	int		i;

	curr = head;
	while (curr)
	{
		i = 0;
		head = head->next;
		while (curr->arguments[i])
		{
			free(curr->arguments[i]);
			i++;
		}
		free(curr->arguments);
		free(curr->command);
		free(curr);
		curr = head;
	}
	free(curr);
}

void	free_list(t_string *head)
{
	t_string *curr;

	curr = head;
	while (curr)
	{
		head = head->next;
		if (curr->s)
			free(curr->s);
		free(curr);
		curr = head;
	}
	free(curr);
}
