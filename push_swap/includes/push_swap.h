/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:08:41 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:08:42 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "checker.h"
# include "struct.h"

/*
** UTILS
*/
int			not_repeated(char *str, t_stacks *s);
char		*ft_strdup(char *src);
t_node		*last_node(t_node *s);
int			absol(int i);

/*
**	FUNCTIONS
*/
int			*calculate_entropy(t_stacks *s);
void		print_commands(t_stacks *s);
void		apply_rotation(int a, int b, t_stacks *s);

/*
**	LIS
*/
int			*calculate_entropy(t_stacks *s);

/*
**	COMMANDS
*/
void		beautiful_rotations(t_stacks **s);
int			switcheroo(t_stacks *s);
void		write_rot(int a, int b, t_stacks *s);

#endif
