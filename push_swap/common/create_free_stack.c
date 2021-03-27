/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_free_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:07:54 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:07:56 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			add_element(t_stacks *s, char *str)
{
	t_node *new;
	t_node *tmp;

	if (!(new = malloc(sizeof(t_node))))
		return (0);
	new->num = ft_atoi(str);
	new->next = 0;
	new->flag = 0;
	new->order = 0;
	tmp = s->a;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
		s->a = new;
	new->prev = tmp;
	s->alen++;
	return (1);
}

int			add_elements(t_stacks *s, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		add_element(s, &str[i]);
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] == ' ')
			i++;
	}
	return (1);
}

int			check_input(char *s, t_node *stack)
{
	int nb;
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '-' && (i == 0 || s[i - 1] == ' '))
			i++;
		if (s[i] == ' ')
			continue ;
		if (s[i] && (s[i] > '9' || s[i] < '0'))
			return (1);
	}
	if (((nb = ft_atoi(s)) == -1 || nb == 0) && ft_strlen(s) > 2)
		return (1);
	while (stack)
	{
		if (nb == stack->num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stacks	*init_stack(t_stacks *s)
{
	s->a = 0;
	s->b = 0;
	s->alen = 0;
	s->blen = 0;
	s->commands = 0;
	return (s);
}

t_stacks	*create_stack(int ac, char **av)
{
	int			i;
	t_stacks	*s;

	if (!(s = malloc(sizeof(t_stacks))))
		return (0);
	s = init_stack(s);
	i = skipflags(av, 0) - 1;
	while (++i < ac)
	{
		if (is_spaces(av[i]) && !check_input(av[i], s->a))
			add_elements(s, av[i]);
		else if (!check_input(av[i], s->a) && *av[i])
			add_element(s, av[i]);
		else if (*av[i])
		{
			free_stack(s);
			return (0);
		}
	}
	if (s->a)
		s->a->prev = last_node(s->a);
	return (s);
}
