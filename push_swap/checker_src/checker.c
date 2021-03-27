/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:07:01 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:07:02 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	make_commands(t_stacks *s, int flags)
{
	if (!get_commands(s, flags))
	{
		if (flags == C_FLAG || flags == CV_FLAG)
			write(1, "\033[0;31m", 8);
		putstr("Error : command error\n");
		free_stack(s);
		return (1);
	}
	if ((flags == C_FLAG || flags == CV_FLAG))
		print_colour(s);
	if (is_sorted(s))
	{
		if (flags == C_FLAG || flags == CV_FLAG)
			write(1, "\033[0;32m", 8);
		putstr("OK\n");
	}
	else
	{
		if (flags == C_FLAG || flags == CV_FLAG)
			write(1, "\033[0;31m", 8);
		putstr("KO\n");
	}
	free_stack(s);
	return (0);
}

int	main(int ac, char **av)
{
	t_stacks	*s;
	int			flags;

	flags = checkflags(ac, av);
	if (ac == 1 || flags == -1)
		return (1);
	if (!(s = create_stack(ac, av)))
	{
		if (flags == C_FLAG || flags == CV_FLAG)
			write(1, "\033[0;31m", 8);
		putstr("Error : numbers error\n");
		if (s)
			free_stack(s);
		return (1);
	}
	if (!s->a)
		return (0);
	if (flags == V_FLAG || flags == CV_FLAG)
		s->a = give_order(s->a);
	return (make_commands(s, flags));
}
