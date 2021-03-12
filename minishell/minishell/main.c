/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:25:35 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/04 12:31:27 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtins(t_comm *curr)
{
	int i;

	i = 0;
	if (!ft_strcmp(curr->command, "echo") && (i = 1))
		g_lo.t_q = b_echo(curr);
	else if (!ft_strcmp(curr->command, "pwd") && (i = 1))
		g_lo.t_q = pwd(curr);
	else if (!ft_strcmp(curr->command, "cd") && (i = 1))
		g_lo.t_q = cd(curr);
	else if (!ft_strcmp(curr->command, "env") && (i = 1))
		g_lo.t_q = env(curr);
	else if (!ft_strcmp(curr->command, "export") && (i = 1))
		g_lo.t_q = export(curr);
	else if (!ft_strcmp(curr->command, "unset") && (i = 1))
		g_lo.t_q = unset(curr);
	else if (!ft_strcmp(curr->command, "exit") && (i = 1))
		g_lo.t_q = goodbye(curr);
	return (i);
}

void	make_comm(t_comm *head)
{
	t_comm	*curr;
	int		equal;
	char	*tmp;

	curr = head;
	while (curr)
	{
		if (curr->command[0] == '$')
			if ((tmp = strfind(&curr->command[1])))
				ft_strcpy(curr->command, tmp);
		equal = thereis_equal(curr);
		if (equal == 1)
			g_lo.t_q = save_variable(curr);
		else if (equal == -1)
			g_lo.t_q = 127;
		if (builtins(curr) == 1)
			;
		else if (!equal && *curr->command != 0)
			g_lo.t_q = search_command(curr);
		if (curr->fdout != 0)
			close(curr->fdout);
		if (curr->fdin != 0)
			close(curr->fdin);
		curr = curr->next;
	}
}

void	make_config(struct termios *sys, struct termios *our)
{
	tcgetattr(0, sys);
	tcgetattr(0, our);
	our->c_iflag &= ~(IXON);
	our->c_lflag &= ~(ECHO | ICANON | IEXTEN);
	our->c_cc[VMIN] = 1;
	our->c_cc[VTIME] = 0;
}

int		main(int argc, char **argv, char **evn)
{
	char			*input;
	t_comm			*head_comm;
	struct termios	sys_config;
	struct termios	our_config;

	welcome();
	set_global(evn, argc, argv);
	make_config(&sys_config, &our_config);
	while (1)
	{
		write(1, "\e[32;1mÆ → \e[0m", 18);
		signal(SIGQUIT, manage_signal);
		signal(SIGINT, manage_signal);
		if ((input = get_input(sys_config, our_config)) == 0)
			return (-1);
		head_comm = save_commands(save_list(input));
		make_comm(head_comm);
		free_comm(head_comm);
	}
	free_global();
	return (0);
}
