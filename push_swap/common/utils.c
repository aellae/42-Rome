/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:08:17 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:08:18 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		*max_element(int *liis, int start, int end)
{
	int *res;

	if (!(res = malloc(sizeof(int) * 2)))
		return (0);
	res[0] = -1;
	while (start < end)
	{
		if (liis[start] > res[0])
		{
			res[0] = liis[start];
			res[1] = start;
		}
		start++;
	}
	return (res);
}

int		is_sorted(t_stacks *s)
{
	t_node *tmp;

	if (s->b)
		return (0);
	tmp = s->a;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	close_ring(t_node *head)
{
	t_node *tmp;

	tmp = head;
	while (tmp && tmp->next)
	{
		tmp->flag = 0;
		tmp = tmp->next;
	}
	tmp->flag = 0;
	tmp->next = head;
}

void	free_list(t_node *head)
{
	t_node *prev;
	t_node *nxt;

	if (!head)
		return ;
	prev = head;
	while (prev)
	{
		nxt = prev->next;
		free(prev);
		prev = nxt;
	}
}

void	free_stack(t_stacks *s)
{
	free_list(s->a);
	free_list(s->b);
	if (s->commands)
		free(s->commands);
	free(s);
}
