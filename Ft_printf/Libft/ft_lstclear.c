/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:42:28 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/12 14:42:30 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *ptr;
	t_list *tmp;

	if (lst && *lst)
	{
		ptr = *lst;
		*lst = 0;
		while (ptr)
		{
			tmp = ptr;
			ptr = ptr->next;
			del(tmp->content);
			free(tmp);
		}
	}
}
