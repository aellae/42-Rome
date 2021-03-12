/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:27:05 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/01 17:27:06 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(t_comm *comm)
{
	char	*buf;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (comm->fdout != 0)
			dup2(comm->fdout, 1);
		if (!(buf = malloc(500)))
			return (0);
		printf("%s\n", getcwd(buf, 500));
		free(buf);
		exit(0);
	}
	else
		wait(NULL);
	return (0);
}
