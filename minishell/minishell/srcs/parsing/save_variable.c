/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:27:31 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/02 16:10:26 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_command(t_comm *comm)
{
	char	*command;
	char	*args;
	int		i;
	int		j;

	command = malloc(strlen(comm->arguments[0]) + 1);
	args = malloc(strlen(comm->arguments[0]) + 1);
	i = 0;
	while (comm->arguments[0][i] && !is_spaces(comm->arguments[0][i]))
	{
		command[i] = comm->arguments[0][i];
		i++;
	}
	command[i] = 0;
	free(comm->command);
	comm->command = command;
	j = 0;
	if (is_spaces(comm->arguments[0][i]))
		i++;
	while (comm->arguments[0][i])
		args[j++] = comm->arguments[0][i++];
	args[j] = 0;
	free(comm->arguments[0]);
	comm->arguments[0] = args;
}

int		search_var(t_comm *comm, int check_error, char *error, int i)
{
	while (comm->command[++i])
	{
		if (comm->command[i] == '=' && comm->command[i + 1])
		{
			i++;
			if (comm->arguments[0])
			{
				get_command(comm);
				if (check_error)
					printf(RED"Æ → %s: command not found"RESET"\n", error);
				free(error);
				return (0);
			}
			if (check_error)
			{
				printf(RED"Æ → %s: command not found"RESET"\n", error);
				free(error);
				return (-1);
			}
			free(error);
			return (1);
		}
	}
	free(error);
	return (0);
}

int		thereis_equal(t_comm *comm)
{
	int		i;
	char	*error;
	int		check_error;

	i = 0;
	check_error = 0;
	if (!(error = malloc(ft_strlen(comm->command) + 1)))
		return (0);
	ft_strcpy(error, comm->command);
	while (error[i] && error[i] != '=')
	{
		if (error[i] != '=' && (error[i] < 'A' ||
			(error[i] > 'Z' && error[i] < 'a') || error[i] > 'z'))
			check_error = 1;
		i++;
	}
	error[i] = 0;
	return (search_var(comm, check_error, error, -1));
}

void	save_variable2(char *comm)
{
	int i;
	int j;

	i = 0;
	while (g_lo.t_local[i])
	{
		j = 0;
		while (comm[j] != '=')
		{
			if (comm[j] != g_lo.t_local[i][j])
				break ;
			j++;
		}
		if (g_lo.t_local[i][j] == '=')
		{
			free(g_lo.t_local[i]);
			g_lo.t_local[i] = malloc(strlen(comm) + 1);
			ft_strcpy(g_lo.t_local[i], comm);
			return ;
		}
		i++;
	}
	g_lo.t_local[i] = malloc(strlen(comm) + 1);
	ft_strcpy(g_lo.t_local[i], comm);
	g_lo.t_local[i + 1] = 0;
}

int		save_variable(t_comm *comm)
{
	int i;
	int j;

	i = 0;
	while (g_lo.t_env[i])
	{
		j = 0;
		while (comm->command[j] != '=')
		{
			if (comm->command[j] != g_lo.t_env[i][j])
				break ;
			j++;
		}
		if (g_lo.t_env[i][j] == '=')
		{
			g_lo.t_env[i] = malloc(strlen(comm->command) + 1);
			ft_strcpy(g_lo.t_env[i], comm->command);
			return (0);
		}
		i++;
	}
	save_variable2(comm->command);
	return (0);
}
