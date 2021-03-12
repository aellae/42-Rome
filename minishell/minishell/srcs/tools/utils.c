/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:27:44 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/04 12:54:03 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strfindlocal(char *str)
{
	int j;
	int i;

	i = 0;
	while (g_lo.t_local[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[j] != g_lo.t_local[i][j])
				break ;
			j++;
		}
		if (g_lo.t_local[i][j] == '=')
			return (&g_lo.t_local[i][j + 1]);
		i++;
	}
	return ("");
}

char	*strfind(char *str)
{
	int i;
	int j;

	if ((ft_strlen(str)) == 0)
		return ("$");
	if (str[0] == '?' && str[1] == 0)
		return (ft_itoa(g_lo.t_q));
	i = 0;
	while (g_lo.t_env[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[j] != g_lo.t_env[i][j])
				break ;
			j++;
		}
		if (g_lo.t_env[i][j] == '=' && (!str[j] || is_spaces(str[j])))
			return (&g_lo.t_env[i][j + 1]);
		i++;
	}
	return (strfindlocal(str));
}

void	free_global(void)
{
	int i;

	i = 0;
	free(g_lo.t_user);
	while (g_lo.t_local[i])
		free(g_lo.t_local[i++]);
	while (g_lo.t_env[g_lo.t_env_size])
		free(g_lo.t_env[g_lo.t_env_size++]);
	free(g_lo.t_local);
}

void	manage_signal(int sig)
{
	write(1, &sig, 3);
	if (sig == SIGINT)
	{
		free(g_lo.input);
		g_lo.input = malloc(1);
		g_lo.input[0] = 0;
		write(1, "\e[32;1m\nÆ → \e[0m", 19);
		signal(SIGINT, manage_signal);
	}
	if (sig == SIGQUIT)
	{
		free(g_lo.input);
		g_lo.input = malloc(1);
		g_lo.input[0] = 0;
		write(1, "\e[32;1m\nÆ → \e[0m", 19);
		signal(SIGQUIT, manage_signal);
	}
}

void	manage_signal2(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		signal(SIGINT, manage_signal);
	}
	if (sig == 3)
	{
		printf("\n");
		signal(SIGINT, manage_signal);
	}
}
