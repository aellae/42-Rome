#include "minishell.h"

int		calc_quote(char c, int quote)
{
	if (c == '"' && quote == 1)
		quote = -1;
	else if (c == '\'' && quote == 1)
		quote = -2;
	else if (c == '"' && quote == -1)
		quote = 1;
	else if (c == '\'' && quote == -2)
		quote = 1;
	return (quote);
}

int		newline(char *s, int *cursor)
{
	int i;
	int len;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
		{
			len = ft_strlen(s) - 1;
			while (s[len] != '\n')
				len--;
			write(1, "\033[1K\033[1G", 8);
			write(1, &s[len + 1], ft_strlen(s) - len);
			(void)(cursor);
			return (1);
		}
	}
	return (0);
}
