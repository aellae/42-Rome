/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:27:36 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/02 16:03:30 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sort_env(int i)
{
	if (i >= g_lo.t_env_size)
		free(g_lo.t_env[i]);
	if (i < g_lo.t_env_size)
		g_lo.t_env_size--;
	while (g_lo.t_env[i])
	{
		g_lo.t_env[i] = g_lo.t_env[i + 1];
		i++;
	}
	return (0);
}

int	sort_local(int i)
{
	free(g_lo.t_local[i]);
	while (g_lo.t_local[i])
	{
		g_lo.t_local[i] = g_lo.t_local[i + 1];
		i++;
	}
	return (0);
}

int	rm_local(t_comm *comm)
{
	int i;
	int j;

	i = 0;
	while (g_lo.t_local[i])
	{
		j = 0;
		while (comm->arguments[0][j])
		{
			if (comm->arguments[0][j] != g_lo.t_local[i][j])
				break ;
			j++;
		}
		if (g_lo.t_local[i][j] == '=')
			return (sort_local(i));
		i++;
	}
	return (0);
}

int	unset(t_comm *comm)
{
	int i;
	int j;

	i = 0;
	if (comm->arguments[0] == 0)
	{
		printf(RED"Æ → unset: not enough arguments"RESET"\n");
		return (1);
	}
	i = 0;
	while (g_lo.t_env[i])
	{
		j = 0;
		while (comm->arguments[0][j])
		{
			if (comm->arguments[0][j] != g_lo.t_env[i][j])
				break ;
			j++;
		}
		if (g_lo.t_env[i][j] == '=')
			return (sort_env(i));
		i++;
	}
	return (rm_local(comm));
}
