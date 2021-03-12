/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:28:21 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/04 12:51:32 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		scan_dollar(t_string **string, char **useful, int *i, int *tmp)
{
	int		flag;
	char	*found;

	flag = 0;
	if ((*string)->s[*i] == '$' && (*string)->apix != '\'' && (flag = 1))
	{
		(*i)++;
		found = strfind(&(*string)->s[*i]);
		*tmp += ft_strlen(found);
		(*useful) = add_str((*useful), found);
		while ((*string)->s[*i] && !is_spaces((*string)->s[*i]))
		{
			(*i)++;
			(*tmp)--;
		}
	}
	else
	{
		(*useful) = charjoin((*useful), (*string)->s[*i], *i + (*tmp));
		(*i)++;
	}
	return (flag);
}

int		find_dollar(t_string **string, t_comm **curr, int *j)
{
	int		i;
	int		flag;
	int		tmp;
	char	*useful;

	i = 0;
	flag = 0;
	useful = malloc(1);
	tmp = 0;
	while ((*string)->s[i])
	{
		if (scan_dollar(string, &useful, &i, &tmp))
			flag = 1;
	}
	if (flag)
	{
		(*curr)->arguments[(*j)++] = useful;
		(*string) = (*string)->next;
	}
	else
		free(useful);
	return (flag);
}

void	set_global(char **evn, int argc, char **argv)
{
	char *level;

	(void)argc;
	(void)argv;
	g_lo.t_env = evn;
	g_lo.t_env_size = 0;
	level = strfind("SHLVL");
	*level = *level + 1;
	while (g_lo.t_env[g_lo.t_env_size])
		g_lo.t_env_size++;
	g_lo.t_q = 0;
	if (!(g_lo.t_local = malloc(sizeof(char *))))
		return ;
	*g_lo.t_local = 0;
	if (!(g_lo.t_user = malloc(strlen(strfind("USER")) + 1)))
		return ;
	ft_strcpy(g_lo.t_user, strfind("USER"));
	g_lo.history = 0;
	if (!(g_lo.paste = malloc(1)))
		return ;
	g_lo.paste[0] = 0;
}

void	cute_cat(int i)
{
	printf(CYAN"\n\n        (\\_/) \n");
	printf("   (   =(^Y^)=\n");
	printf("____\\__(m___m)_______\n\n");
	printf("       Goodbye!\n\n"RESET);
	free_global();
	exit(i);
}

int		goodbye(t_comm *curr)
{
	int i;

	i = -1;
	if (curr && curr->arguments[0] != 0)
	{
		if (curr->arguments[1] != 0)
		{
			printf(RED"Æ → exit: too many arguments"RESET"\n");
			return (1);
		}
		if (curr->arguments[0][0] == '-')
			i++;
		while (curr->arguments[0][++i])
			if (curr->arguments[0][i] < '0' || curr->arguments[0][i] > '9')
			{
				printf(RED"Æ → exit: %s: numeric argument required"RESET"\n",
					curr->arguments[0]);
				cute_cat(255);
			}
		cute_cat(ft_atochar(curr->arguments[0]));
	}
	cute_cat(0);
	return (0);
}
