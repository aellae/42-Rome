/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:34:42 by ade-feli          #+#    #+#             */
/*   Updated: 2021/03/04 12:31:49 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <termios.h>
# include <curses.h>

# include "../Libft/libft.h"

typedef struct	s_his
{
	char			*string;
	struct s_his	*previus;
	struct s_his	*next;
}				t_his;

typedef struct	s_global
{
	char	**t_env;
	int		t_q;
	char	**t_local;
	char	*t_user;
	int		t_env_size;
	t_his	*history;
	char	*paste;
	char	*input;
}				t_global;

t_global g_lo;

/*
**  GET_INPUT
*/

char			*get_input(struct termios sys, struct termios our);
t_comm			*save_commands(t_string *string);
t_string		*save_list(char *input);
int				found_pipe(int *fd, t_comm **curr, t_string **string, int *j);
int				found_major(t_comm **curr, t_string **string);
int				found_minus(t_comm **curr, t_string **string);
void			add_comm(t_string **string, t_comm **curr);
void			add_arg(t_string **string, t_comm **curr, int *j);
void			save_history(char *input);
int				check_arrow(char c, int *inside, int *cursor);
int				check_ctrl(char c, int *cursor);
int				copy_paste(char c, int *cursor);
int				skip_world(int *cursor, char c);
int				home_end(char c, int *cursor);
/*
**  INSTRUCTIONS
*/

int				b_echo(t_comm *comm);
int				pwd(t_comm *comm);
int				cd(t_comm *comm);
int				env(t_comm *comm);
int				save_variable(t_comm *comm);
int				export(t_comm *comm);
int				unset(t_comm *comm);
int				search_command(t_comm *curr);

/*
**	UTILS
*/
char			*strfind(char *str);
char			*strfindlocal(char *str);
int				thereis_equal(t_comm *comm);
void			free_global(void);
void			manage_signal(int sig);
void			manage_signal2(int sig);
void			set_global(char **evn, int argc, char **argv);
int				goodbye(t_comm *curr);
int				find_dollar(t_string **string, t_comm **curr, int *j);
int				calc_quote(char c, int quote);
int				newline(char *s, int *cursor);

#endif
