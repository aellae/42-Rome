/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:26:34 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/02 16:08:53 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		print_echo(t_comm *comm, int flag_n)
{
	pid_t	pid;
	int		j;

	j = flag_n == 0 ? 0 : 1;
	pid = fork();
	if (pid == 0)
	{
		if (comm->fdout != 0)
			dup2(comm->fdout, 1);
		while (comm->arguments && comm->arguments[j])
		{
			write(1, comm->arguments[j], ft_strlen(comm->arguments[j]));
			if (comm->arguments[j + 1])
				write(1, " ", 1);
			j++;
		}
		if (flag_n == 0)
			write(1, "\n", 1);
		if (flag_n == 1 && comm->fdout == 0)
			printf(W_BGROUND"%%\n"RESET);
		exit(0);
	}
	else
		wait(NULL);
	return (0);
}

int		b_echo(t_comm *comm)
{
	int		flag_n;
	int		space;
	t_comm	*curr;

	flag_n = 0;
	space = 0;
	curr = comm;
	if (comm->arguments[0] && ft_strcmp(comm->arguments[0], "-n") == 0)
		flag_n = 1;
	return (print_echo(comm, flag_n));
}
