/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:08:56 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:08:57 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*create_sequence(int *liis, int *res, int *string)
{
	int *seq;
	int i;
	int j;
	int tmp;

	if (!(seq = malloc(sizeof(int) * (res[0] + 1))))
		return (0);
	seq[0] = res[0];
	i = 1;
	tmp = res[1];
	while (res[0])
	{
		j = tmp;
		while (liis[j] != res[0])
			j--;
		tmp = j;
		seq[i] = string[j];
		res[0]--;
		i++;
	}
	free(res);
	return (seq);
}

int	*computelis(int string[], int start, int end)
{
	int liis[end];
	int i;
	int j;
	int *sequence;

	i = start;
	while (i < end)
		liis[i++] = 1;
	i = start;
	while (++i < end)
	{
		j = start - 1;
		while (++j < i)
			if (string[i] > string[j] && liis[i] < liis[j] + 1)
				liis[i] = liis[j] + 1;
	}
	sequence = create_sequence(liis, max_element(liis, start, end), string);
	return (sequence);
}

int	*lics2(int *string, int n)
{
	int *tmp;
	int *res;
	int i;

	res = 0;
	i = -1;
	while (++i < n)
	{
		if (!res)
			res = computelis(string, i, i + n);
		else
		{
			tmp = computelis(string, i, i + n);
			if (tmp[0] > res[0])
			{
				free(res);
				res = tmp;
			}
			else
				free(tmp);
		}
	}
	return (res);
}

int	*lics(int arr[], int n)
{
	int string[2 * n];
	int i;

	i = -1;
	while (++i < n)
		string[i] = arr[i];
	i = n - 1;
	while (++i < 2 * n)
		string[i] = arr[i - n];
	return (lics2(string, n));
}

int	*calculate_entropy(t_stacks *s)
{
	int		*array;
	t_node	*tmp;
	int		i;
	int		*res;

	tmp = s->a;
	i = 0;
	if (!(array = malloc(sizeof(int) * s->alen * 2)))
		return (0);
	while (tmp)
	{
		array[i++] = tmp->num;
		tmp = tmp->next;
	}
	res = lics(array, s->alen);
	free(array);
	return (res);
}
