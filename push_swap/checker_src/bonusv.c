/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:06:51 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:06:54 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	printbegin(int width, char *comm)
{
	int i;

	i = -2;
	while (++i < width)
		putstr(" ");
	putstr("\e[43;30m ");
	putstr(comm);
	putstr(" \033[0m\n");
	i = 0;
	while (++i < width / 2 + 3)
		putstr(" ");
	putstr("\e[1;95mA");
	i = 0;
	while (++i < width + 3)
		putstr(" ");
	putstr("\e[1;96mB\n \e[0m");
	i = 0;
	while (++i < (width * 2) + 6)
		putstr("-");
	putstr("\n");
}

void	printa(t_node **a, int width, int i)
{
	if (*a)
	{
		putstr("\e[0;105m");
		while (i < (*a)->order)
		{
			putstr(" ");
			i++;
		}
		putstr("\033[0m");
		(*a) = (*a)->next;
	}
	while (i < width)
	{
		putstr(" ");
		i++;
	}
	putstr(" | ");
}

void	printb(t_node **b, int width, int i)
{
	if (*b)
	{
		putstr("\e[0;106m");
		while (i < (*b)->order)
		{
			putstr(" ");
			i++;
		}
		putstr("\033[0m");
		(*b) = (*b)->next;
	}
	while (i < width)
	{
		putstr(" ");
		i++;
	}
}

void	printstack(t_stacks *s, char *comm)
{
	int			width;
	t_node		*a;
	t_node		*b;
	int			i;
	useconds_t	sec;

	width = s->alen + s->blen;
	putstr("\e[1;1H\e[2J\n");
	printbegin(width, comm);
	a = s->a;
	b = s->b;
	while (a || b)
	{
		putstr("| ");
		printa(&a, width, 0);
		printb(&b, width, 0);
		putstr(" |\n");
	}
	i = 0;
	putstr(" ");
	while (++i < (width * 2) + 6)
		putstr("-");
	putstr("\n");
	sec = 150000;
	usleep(sec);
}

void	print_colour(t_stacks *s)
{
	t_node *a;
	t_node *b;

	a = s->a;
	b = s->b;
	print_branches(s);
	putstr("\e[1;35ma = \e[0;35m");
	while (a)
	{
		ft_putnbr(a->num);
		putstr(" ");
		a = a->next;
	}
	putstr("\e[1;96m\nb = \e[0;36m");
	while (b)
	{
		ft_putnbr(b->num);
		putstr(" ");
		b = b->next;
	}
	putstr("\033[0m\n");
	print_branches(s);
}
