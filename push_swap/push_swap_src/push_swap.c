/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:09:04 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:09:05 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_rot(t_stacks *s, int i)
{
	if (s->commands[i] == RA)
		write(1, "ra\n", 3);
	if (s->commands[i] == RB)
		write(1, "rb\n", 3);
	if (s->commands[i] == RR)
		write(1, "rr\n", 3);
	if (s->commands[i] == RRA)
		write(1, "rra\n", 4);
	if (s->commands[i] == RRB)
		write(1, "rrb\n", 4);
	if (s->commands[i] == RRR)
		write(1, "rrr\n", 4);
}

void	print_commands(t_stacks *s)
{
	int i;

	i = -1;
	while (s->commands[++i])
	{
		if (s->commands[i] == SA)
			write(1, "sa\n", 3);
		if (s->commands[i] == SB)
			write(1, "sb\n", 3);
		if (s->commands[i] == SS)
			write(1, "ss\n", 3);
		if (s->commands[i] == PA)
			write(1, "pa\n", 3);
		if (s->commands[i] == PB)
			write(1, "pb\n", 3);
		print_rot(s, i);
	}
}

int		set_flag(t_stacks *s)
{
	int		*seq;
	int		i;
	t_node	*tmp;
	int		ret;

	seq = calculate_entropy(s);
	tmp = s->a;
	while (tmp)
	{
		i = 0;
		while (++i <= seq[0])
			if (tmp->num == seq[i])
			{
				tmp->flag = 1;
				break ;
			}
		tmp = tmp->next;
	}
	ret = seq[0];
	free(seq);
	return (ret);
}

void	push_disorder(t_stacks *s, int liis)
{
	while (s->alen > liis)
	{
		if (!s->a->flag)
		{
			execute_command(s, PB);
			s->commands = charjoin(s->commands, PB);
			continue ;
		}
		execute_command(s, RA);
		s->commands = charjoin(s->commands, RA);
	}
}

int		main(int ac, char **av)
{
	t_stacks	*s;
	int			liis;

	if (ac == 1)
		return (0);
	if (!(s = create_stack(ac, av)))
	{
		write(1, "\033[0;31m", 8);
		putstr("Error : numbers error\n");
		if (s)
			free_stack(s);
		return (1);
	}
	liis = set_flag(s);
	if (!is_sorted(s) && s->alen > 100)
		push_disorder(s, liis);
	while (!is_sorted(s))
		beautiful_rotations(&s);
	if (!s->commands)
		return (0);
	print_commands(s);
	free_stack(s);
	return (0);
}
