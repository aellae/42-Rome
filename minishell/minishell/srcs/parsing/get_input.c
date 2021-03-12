/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:26:57 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/02 15:50:53 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		flags(char c, int *slash, int *quote)
{
	if (c == '\n')
		write(1, "\n", 1);
	if (*slash != 1)
		*quote = calc_quote(c, *quote);
	*slash = 0;
	if (c == '\\' && *slash == 0 && *quote != -2)
		*slash = 1;
	return (1);
}

void	print_line(void)
{
	write(1, "\033[1K\033[1G", 8);
	write(1, "\e[32;1mÆ → \e[0m", 18);
	write(1, g_lo.input, ft_strlen(g_lo.input));
}

void	init_scan_input(int *quote, int *arrow, int *slash)
{
	*quote = 1;
	*arrow = 0;
	*slash = 0;
}

void	scan_input(int *i, int input_len, int cursor, int inside)
{
	int		quote;
	char	c;
	int		arrow;
	int		slash;

	init_scan_input(&quote, &arrow, &slash);
	while ((*i = read(0, &c, 1)))
	{
		if (check_ctrl(c, &cursor) || copy_paste(c, &cursor) ||
			skip_world(&cursor, c) || home_end(c, &cursor) ||
			(arrow = check_arrow(c, &inside, &cursor)))
			continue;
		if (quote == 1 && c == '\n' && slash == 0)
			break ;
		if (flags(c, &slash, &quote) && !ft_isprint(c) && c != '\n')
			continue ;
		g_lo.input = ft_elbowing(g_lo.input, c, cursor++);
		if (newline(g_lo.input, &cursor))
			;
		else
			print_line();
		input_len = ft_strlen(g_lo.input);
		while (input_len-- > cursor)
			write(1, "\033[1D", 4);
	}
}

char	*get_input(struct termios sys, struct termios our)
{
	int		i;

	if (!(g_lo.input = malloc(1)))
		return (0);
	g_lo.input[0] = 0;
	tcsetattr(0, TCSAFLUSH, &our);
	scan_input(&i, 0, 0, 0);
	tcsetattr(0, TCSAFLUSH, &sys);
	write(1, "\n", 1);
	save_history(g_lo.input);
	g_lo.input = g_lo.history->string;
	if (!*g_lo.input)
	{
		free(g_lo.input);
		return ("");
	}
	if (i == 0 && *g_lo.input == 0)
	{
		free(g_lo.input);
		goodbye(0);
	}
	return (g_lo.input);
}
