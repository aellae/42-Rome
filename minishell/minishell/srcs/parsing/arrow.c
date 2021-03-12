#include "minishell.h"

int	up(int *inside, int *cursor)
{
	int i;

	if (!g_lo.history)
		return (2);
	i = -1;
	while (g_lo.history->string[++i])
		if (g_lo.history->string[i] == '\n')
			write(1, "\033[1G\033[K\033[1A\033[K", 16);
	write(1, "\033[1K\033[1G", 8);
	write(1, "\e[32;1mÆ → \e[0m", 18);
	if (*inside != 0)
		if (g_lo.history->previus)
			g_lo.history = g_lo.history->previus;
	write(1, g_lo.history->string, ft_strlen(g_lo.history->string));
	*inside = 1;
	free(g_lo.input);
	g_lo.input = ft_strdup(g_lo.history->string);
	*cursor = ft_strlen(g_lo.input);
	return (2);
}

int	down(int *cursor)
{
	int i;

	if (!g_lo.history)
		return (2);
	if (!g_lo.history->next)
	{
		write(1, "\033[1K\033[1G", 8);
		write(1, "\e[32;1mÆ → \e[0m", 18);
		*g_lo.input = 0;
		*cursor = ft_strlen(g_lo.input);
		return (2);
	}
	i = -1;
	while (g_lo.history->string[++i])
		if (g_lo.history->string[i] == '\n')
			write(1, "\033[1G\033[K\033[1A\033[K", 16);
	write(1, "\033[1K\033[1G", 8);
	write(1, "\e[32;1mÆ → \e[0m", 18);
	g_lo.history = g_lo.history->next;
	write(1, g_lo.history->string, ft_strlen(g_lo.history->string));
	free(g_lo.input);
	g_lo.input = ft_strdup(g_lo.history->string);
	*cursor = ft_strlen(g_lo.input);
	return (2);
}

int	right(int *cursor)
{
	if (*cursor >= ft_strlen(g_lo.input))
		return (1);
	(*cursor)++;
	write(1, "\033[1C", 4);
	return (42);
}

int	left(int *cursor)
{
	if (*cursor == 0)
		return (1);
	(*cursor)--;
	write(1, "\033[1D", 4);
	return (42);
}

int	check_arrow(char c, int *inside, int *cursor)
{
	if (c == '\x1b')
	{
		read(0, &c, 1);
		if (c == '\x5b')
		{
			read(0, &c, 1);
			if (c == '\x41')
				return (up(inside, cursor));
			if (c == '\x42')
				return (down(cursor));
			if (c == '\x43')
				return (right(cursor));
			if (c == '\x44')
				return (left(cursor));
		}
	}
	return (0);
}
