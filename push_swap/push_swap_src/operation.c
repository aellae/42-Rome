/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:09:00 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:09:01 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		test_sa2(t_stacks *s)
{
	t_node *tmp;

	if (s->a->flag == 1 && s->a->next->flag == 0)
	{
		tmp = s->a->prev;
		while (tmp && tmp->flag == 0)
			tmp = tmp->prev;
		if (tmp->num < s->a->next->num)
		{
			s->a->next->flag = 1;
			execute_command(s, SA);
			return (SA);
		}
	}
	return (0);
}

int		test_sa(t_stacks *s)
{
	t_node *tmp;

	if (s->a->flag == 0 && s->a->next->flag == 1)
	{
		tmp = s->a->next->next;
		while (tmp && tmp->flag == 0)
			tmp = tmp->next;
		if (tmp->num > s->a->num)
		{
			s->a->flag = 1;
			execute_command(s, SA);
			return (SA);
		}
	}
	return (test_sa2(s));
}

int		switcheroo(t_stacks *s)
{
	if (s->alen > 2 && s->a->num > s->a->next->num && test_sa(s))
		return (SA);
	if (s->blen && s->a->flag == 1 && s->a->prev->flag == 1)
	{
		if ((s->a->num > s->b->num && s->b->num > s->a->prev->num) ||
			(s->a->num < s->a->prev->num && s->a->prev->num < s->b->num) ||
			(s->a->num < s->a->prev->num && s->a->num > s->b->num))
		{
			s->b->flag = 1;
			execute_command(s, PA);
			return (PA);
		}
	}
	if (s->a->flag == 0)
	{
		execute_command(s, PB);
		return (PB);
	}
	return (0);
}

void	write_rot2(int *a, int *b, t_stacks *s)
{
	while (*a * *b > 0)
	{
		if (*a > 0)
		{
			s->commands = charjoin(s->commands, RR);
			(*a)--;
			(*b)--;
		}
		else
		{
			s->commands = charjoin(s->commands, RRR);
			(*a)++;
			(*b)++;
		}
	}
}

void	write_rot(int a, int b, t_stacks *s)
{
	write_rot2(&a, &b, s);
	while (a > 0)
	{
		s->commands = charjoin(s->commands, RA);
		a--;
	}
	while (a < 0)
	{
		s->commands = charjoin(s->commands, RRA);
		a++;
	}
	while (b > 0)
	{
		s->commands = charjoin(s->commands, RB);
		b--;
	}
	while (b < 0)
	{
		s->commands = charjoin(s->commands, RRB);
		b++;
	}
}
