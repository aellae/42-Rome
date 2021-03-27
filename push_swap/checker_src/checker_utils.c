/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:07:09 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:07:13 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int			is_valid_command(char *str)
{
	if (!ft_strcmp(str, "sa"))
		return (SA);
	if (!ft_strcmp(str, "sb"))
		return (SB);
	if (!ft_strcmp(str, "ss"))
		return (SS);
	if (!ft_strcmp(str, "pa"))
		return (PA);
	if (!ft_strcmp(str, "pb"))
		return (PB);
	if (!ft_strcmp(str, "ra"))
		return (RA);
	if (!ft_strcmp(str, "rb"))
		return (RB);
	if (!ft_strcmp(str, "rr"))
		return (RR);
	if (!ft_strcmp(str, "rra"))
		return (RRA);
	if (!ft_strcmp(str, "rrb"))
		return (RRB);
	if (!ft_strcmp(str, "rrr"))
		return (RRR);
	return (0);
}

int			get_commands(t_stacks *s, int flags)
{
	int		res;
	char	*tmp;
	int		i;

	res = 1;
	i = 0;
	while (gnl(&tmp) > 0)
	{
		if (!(res = is_valid_command(tmp)))
		{
			free(tmp);
			return (0);
		}
		execute_command(s, res);
		if (flags == V_FLAG || flags == CV_FLAG)
			printstack(s, tmp);
		free(tmp);
	}
	free(tmp);
	return (1);
}

int			checkflags(int ac, char **av)
{
	int flags;
	int i;

	flags = 0;
	i = 0;
	while (++i < ac)
	{
		if ((flags == 0 || flags == C_FLAG) && !ft_strcmp(av[i], "-v"))
			flags = flags == 0 ? V_FLAG : CV_FLAG;
		else if ((flags == 0 || flags == V_FLAG) && !ft_strcmp(av[i], "-c"))
			flags = flags == 0 ? C_FLAG : CV_FLAG;
		else if (flags == 0 && (!ft_strcmp(av[i], "-vc") ||
			!ft_strcmp(av[i], "-cv")))
			return (CV_FLAG);
		else
			return (flags);
	}
	return (-1);
}

t_node		*give_order(t_node *stack)
{
	t_node	*tmp;
	t_node	*min;
	t_node	*ret;
	int		i;

	i = 1;
	ret = stack;
	while (stack)
	{
		tmp = ret;
		min = ret;
		while (tmp)
		{
			if ((tmp->num < min->num && !tmp->order) || min->order)
				min = tmp;
			tmp = tmp->next;
		}
		min->order = i;
		i++;
		stack = stack->next;
	}
	return (ret);
}

void		print_branches(t_stacks *s)
{
	int width;

	width = (s->alen + s->blen) * 2 + 5;
	putstr(" ");
	while (width--)
		putstr("-");
	putstr("\n");
}
