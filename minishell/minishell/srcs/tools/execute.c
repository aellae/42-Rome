/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:26:45 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/02 16:09:29 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_command(char **command, char **folder)
{
	int i;

	i = 0;
	while (folder[i])
		free(folder[i++]);
	free(folder);
	free(command);
	return (0);
}

int	execute_command(char **command, int fdout, int fdin, char **folder)
{
	pid_t	pid;
	int		wstatus;

	errno = 0;
	signal(SIGINT, manage_signal2);
	signal(SIGQUIT, manage_signal2);
	pid = fork();
	if (pid == 0)
	{
		if (fdout != 0)
			dup2(fdout, 1);
		if (fdin != 0)
			dup2(fdin, 0);
		if (execve(command[0], command, g_lo.t_env) == -1)
			printf("Could not execute command\n");
		return (free_command(command, folder));
	}
	else
		wait(&wstatus);
	free(command[0]);
	free_command(command, folder);
	return (wstatus);
}

int	given_path(char **command, t_comm *curr, struct stat f, char **folder)
{
	if (!(command[0] = malloc(ft_strlen(curr->command) + 1)))
		return (0);
	ft_strcpy(command[0], curr->command);
	if (lstat(command[0], &f) != -1)
		return (execute_command(command, curr->fdout, curr->fdin, folder));
	free_command(command, folder);
	return (0);
}

int	find_folder(char **folders, struct stat f, t_comm *curr, char **command)
{
	int i;

	i = 0;
	while (folders && folders[i])
	{
		command[0] = add_str_notfree(folders[i], "/");
		command[0] = add_str(command[0], curr->command);
		if (lstat(command[0], &f) != -1)
			return (execute_command(command, curr->fdout, curr->fdin, folders));
		i++;
		free(command[0]);
	}
	free_command(command, folders);
	printf(RED "Æ → %s: command not found\n" RESET, curr->command);
	return (127);
}

int	search_command(t_comm *curr)
{
	char		*path;
	char		**folders;
	char		**command;
	struct stat	f;
	int			j;

	path = strfind("PATH");
	folders = ft_split(path, ':');
	if (!(command = malloc(sizeof(char *) * 20)))
		return (0);
	j = 0;
	while (curr->arguments[j])
	{
		command[j + 1] = curr->arguments[j];
		j++;
	}
	command[j + 1] = 0;
	if (lstat(curr->command, &f) != -1 || *curr->command == '/')
		return (given_path(command, curr, f, folders));
	else
		return (find_folder(folders, f, curr, command));
	free_command(command, folders);
	printf(RED "Æ → %s: command not found\n" RESET, curr->command);
	return (127);
}
