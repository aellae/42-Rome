/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:26:39 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/02 12:20:43 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env(t_comm *comm)
{
	int		i;
	pid_t	pid;

	i = -1;
	if (comm->arguments[0] != 0)
	{
		printf(RED"Æ → %s: %s: %s\n"RESET,
			comm->command, comm->arguments[0], strerror(2));
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		if (comm->fdout != 0)
			dup2(comm->fdout, 1);
		while (g_lo.t_env[++i])
			printf("%s\n", g_lo.t_env[i]);
		exit(0);
	}
	else
		wait(NULL);
	return (0);
}
