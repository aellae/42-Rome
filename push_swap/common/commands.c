/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:07:31 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:07:33 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	c_pb(t_stacks *s)
{
	t_node *next;

	if (!s->a)
		return ;
	next = s->a->next;
	if (next)
		next->prev = s->a->prev;
	if (s->b)
	{
		s->a->prev = s->b->prev;
		s->b->prev = s->a;
	}
	else
		s->a->prev = s->a;
	s->a->next = s->b;
	s->b = s->a;
	s->a = next;
	s->alen--;
	s->blen++;
}

void	c_pa(t_stacks *s)
{
	t_node *next;

	if (!s->b)
		return ;
	next = s->b->next;
	if (next)
		next->prev = s->b->prev;
	if (s->a)
	{
		s->b->prev = s->a->prev;
		s->a->prev = s->b;
	}
	else
		s->b->prev = s->b;
	s->b->next = s->a;
	s->a = s->b;
	s->b = next;
	s->blen--;
	s->alen++;
}

void	c_rra(t_stacks *s)
{
	t_node *tmp;

	if (s->alen < 2)
		return ;
	tmp = s->a;
	tmp->prev->next = tmp;
	tmp->prev->prev->next = 0;
	s->a = s->a->prev;
}

void	c_rrb(t_stacks *s)
{
	t_node *tmp;

	if (s->blen < 2)
		return ;
	tmp = s->b;
	tmp->prev->next = tmp;
	tmp->prev->prev->next = 0;
	s->b = s->b->prev;
}

void	execute_command(t_stacks *s, char command)
{
	if (command == SA || command == SS)
		c_sa(s);
	if (command == SB || command == SS)
		c_sb(s);
	if (command == PA)
		c_pa(s);
	if (command == PB)
		c_pb(s);
	if (command == RA || command == RR)
		c_ra(s);
	if (command == RB || command == RR)
		c_rb(s);
	if (command == RRA || command == RRR)
		c_rra(s);
	if (command == RRB || command == RRR)
		c_rrb(s);
}
