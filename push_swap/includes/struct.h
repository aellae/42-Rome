/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:08:45 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:08:46 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_node
{
	int				num;
	int				flag;
	int				order;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_stacks
{
	t_node	*a;
	int		alen;
	t_node	*b;
	int		blen;
	char	*commands;
}				t_stacks;

typedef struct	s_rotation
{
	int	len;
	int a;
	int b;
}				t_rotation;

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
# define C_FLAG 69
# define V_FLAG 42
# define CV_FLAG 420

#endif
