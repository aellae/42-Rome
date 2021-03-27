/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:09:09 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:09:11 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	apply_doublerot(int *a, int *b, t_stacks *s)
{
	while (*a * *b > 0)
	{
		if (*a > 0)
		{
			execute_command(s, RR);
			(*a)--;
			(*b)--;
		}
		else
		{
			execute_command(s, RRR);
			(*a)++;
			(*b)++;
		}
	}
}

void	apply_rotation(int a, int b, t_stacks *s)
{
	apply_doublerot(&a, &b, s);
	while (a > 0)
	{
		execute_command(s, RA);
		a--;
	}
	while (a < 0)
	{
		execute_command(s, RRA);
		a++;
	}
	while (b > 0)
	{
		execute_command(s, RB);
		b--;
	}
	while (b < 0)
	{
		execute_command(s, RRB);
		b++;
	}
}

int		test_rot(int a, int b, t_stacks **s)
{
	char comm;

	comm = 0;
	if (absol(b) * 2 > (*s)->blen + 1)
		return (0);
	if (absol(a) * 2 > (*s)->alen + 1)
		return (0);
	apply_rotation(a, b, *s);
	if (is_sorted(*s) || (comm = switcheroo(*s)))
	{
		write_rot(a, b, *s);
		if (comm)
			(*s)->commands = charjoin((*s)->commands, comm);
		return (1);
	}
	apply_rotation(-a, -b, *s);
	return (0);
}

void	beautiful_rotations(t_stacks **s)
{
	int i;
	int n;

	i = 0;
	while (1)
	{
		if (test_rot(i, 0, s) || test_rot(0, i, s) || test_rot(-i, 0, s)
			|| test_rot(0, -i, s) || test_rot(i, i, s) || test_rot(-i, -i, s))
			return ;
		n = 0;
		while (++n < i / 2 + 1)
		{
			if (test_rot(i, n, s) || test_rot(n, i, s) || test_rot(-i, -n, s)
				|| test_rot(-n, -i, s) || test_rot(i - n, n, s) ||
				test_rot(n, i - n, s) || test_rot(-i + n, -n, s) ||
				test_rot(-n, -i + n, s) || test_rot(i - n, -n, s) ||
				test_rot(-n, i - n, s) || test_rot(-i + n, n, s) ||
				test_rot(n, -i + n, s) || test_rot(i - n, i, s) ||
				test_rot(i, i - n, s) || test_rot(-i + n, -i, s) ||
				test_rot(-i, -i + n, s))
				return ;
		}
		i++;
	}
}
