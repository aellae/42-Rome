/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:08:36 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:08:38 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "struct.h"

/*
**	LIBFT
*/
int			ft_atoi(char *str);
void		putstr(char *s);
int			gnl(char **line);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *src);
int			ft_strlen(char *s);
char		*charjoin(char *s, char c);
int			is_spaces(char *s);

/*
**	CHECK INPUT
*/
int			checkflags(int ac, char **av);
int			skipflags(char **av, int i);
int			get_commands(t_stacks *s, int flags);

/*
**	CREATE AND FREE STACK
*/
t_stacks	*create_stack(int ac, char **av);
void		free_list(t_node *head);
void		free_stack(t_stacks *s);

/*
** COMMANDS
*/
void		execute_command(t_stacks *s, char command);
void		c_ra(t_stacks *s);
void		c_rb(t_stacks *s);
void		c_sa(t_stacks *s);
void		c_sb(t_stacks *s);

/*
** UTILS
*/
int			*max_element(int *liis, int start, int end);
int			is_sorted(t_stacks *s);
void		close_ring(t_node *head);
int			absol(int i);
t_node		*last_node(t_node *s);
void		ft_putnbr(int n);
void		ft_putchar(char c);
t_node		*give_order(t_node *stack);
char		choose_flag(char c, char flag);
void		print_branches(t_stacks *s);

/*
** BONUS
*/
void		print_colour(t_stacks *s);
void		printstack(t_stacks *s, char *comm);

#endif
