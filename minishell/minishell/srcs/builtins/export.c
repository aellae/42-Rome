/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:26:51 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/02 15:59:33 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strfindline(char *str)
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
			return (g_lo.t_local[i]);
		i++;
	}
	return ("");
}

int		export_env(int i, char *s)
{
	int j;

	i++;
	j = 0;
	while (g_lo.t_env[j])
	{
		i = 0;
		while (s[i] != '=')
		{
			if (s[i] != g_lo.t_env[j][i])
				break ;
			i++;
		}
		if (g_lo.t_env[j][i] == '=')
		{
			g_lo.t_env[j] = malloc(strlen(s) + 1);
			ft_strcpy(g_lo.t_env[j], s);
			return (0);
		}
		j++;
	}
	g_lo.t_env[j] = malloc(strlen(s) + 1);
	ft_strcpy(g_lo.t_env[j], s);
	g_lo.t_env[j + 1] = 0;
	return (0);
}

int		export_local(char *s)
{
	int		j;
	char	*local;

	j = 0;
	local = strfindline(s);
	if (*local != 0)
	{
		while (g_lo.t_env[j])
			j++;
		g_lo.t_env[j] = malloc(strlen(local) + 1);
		ft_strcpy(g_lo.t_env[j], local);
		g_lo.t_env[j + 1] = 0;
	}
	return (0);
}

int		export(t_comm *comm)
{
	int		i;
	char	*s;

	s = comm->arguments[0];
	i = -1;
	if (!comm->arguments[0])
		return (env(comm));
	while (s[++i])
		if (s[i] == '=' && s[i + 1])
			return (export_env(i, s));
	return (export_local(s));
}
