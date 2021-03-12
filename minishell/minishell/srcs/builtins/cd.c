/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:26:27 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/02 16:08:05 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(t_comm *comm)
{
	int r;

	if (comm->arguments[0] == 0)
	{
		r = chdir(strfind("HOME"));
		if (r < 0)
		{
			printf(RED"Æ → cd: HOME not set\n"RESET);
			return (1);
		}
		return (0);
	}
	if (chdir(comm->arguments[0]) == 0)
		return (0);
	printf(RED"Æ → %s: %s: %s\n"RESET, comm->command,
		comm->arguments[0], strerror(2));
	return (2);
}
