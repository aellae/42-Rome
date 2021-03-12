#include "minishell.h"

int		one_command_time(t_string **string, t_comm **curr, int *fd, int *j)
{
	while ((*string) && (ft_strcmp((*string)->s, ";") != 0))
	{
		if (!ft_strcmp((*string)->s, "|") && found_pipe(fd, curr, string, j))
			break ;
		if (!ft_strcmp((*string)->s, ">"))
		{
			if (found_major(curr, string) == 0)
				return (0);
			continue;
		}
		if (!ft_strcmp((*string)->s, "<"))
		{
			if (found_minus(curr, string) == 0)
				return (0);
			continue ;
		}
		if (find_dollar(string, curr, j))
			continue;
		add_arg(string, curr, j);
	}
	return (1);
}

int		scan_string(t_string *string, int size, t_comm *curr, int *fd)
{
	int j;

	while (string)
	{
		if (curr->pipe == 0 && !curr->arguments)
			curr->arguments = malloc(sizeof(char *) * size);
		j = 0;
		free(curr->command);
		curr->command = ft_strdup(string->s);
		if (!(ft_strcmp(curr->command, ">")) || !(ft_strcmp(curr->command, "<"))
			|| !(ft_strcmp(curr->command, ";")) ||
				!(ft_strcmp(curr->command, "|")))
		{
			printf(RED"Æ → syntax error near unexpected token '%s'\n"RESET,
				curr->command);
			return (0);
		}
		string = string->next;
		if (one_command_time(&string, &curr, fd, &j) == 0)
			return (0);
		curr->arguments[j] = 0;
		if (string)
			add_comm(&string, &curr);
	}
	return (1);
}

t_comm	*save_commands(t_string *string)
{
	t_comm		*ret;
	t_comm		*curr;
	t_string	*to_free;
	int			size;
	int			fd[2];

	size = 0;
	to_free = string;
	while (string)
	{
		string = string->next;
		size++;
	}
	string = to_free;
	ret = new_node();
	curr = ret;
	if (scan_string(string, size, curr, fd) == 0)
	{
		free_comm(curr);
		free_list(to_free);
		return (0);
	}
	free_list(to_free);
	return (ret);
}
