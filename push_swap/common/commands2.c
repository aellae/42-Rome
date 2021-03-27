/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:07:37 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:07:39 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	c_ra(t_stacks *s)
{
	t_node *tmp;

	if (s->alen < 2)
		return ;
	tmp = s->a;
	tmp->prev->next = s->a;
	s->a = s->a->next;
	tmp->next = 0;
}

void	c_rb(t_stacks *s)
{
	t_node *tmp;

	if (s->blen < 2)
		return ;
	tmp = s->b;
	tmp->prev->next = s->b;
	s->b = s->b->next;
	tmp->next = 0;
}

void	c_sa(t_stacks *s)
{
	t_node *next;

	if (s->alen < 2)
		return ;
	if (s->alen == 2)
	{
		c_ra(s);
		return ;
	}
	next = s->a->next;
	next->prev = s->a->prev;
	s->a->prev = next;
	next->next->prev = s->a;
	s->a->next = next->next;
	next->next = s->a;
	s->a = next;
}

void	c_sb(t_stacks *s)
{
	t_node *next;

	if (s->blen < 2)
		return ;
	if (s->blen == 2)
	{
		c_rb(s);
		return ;
	}
	next = s->b->next;
	next->prev = s->b->prev;
	s->b->prev = next;
	next->next->prev = s->b;
	s->b->next = next->next;
	next->next = s->b;
	s->b = next;
}
