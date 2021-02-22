/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:55:08 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:55:09 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	lets_start(int fd, int save)
{
	if (read_input(fd) == -1)
		return (printf(RED"Error\nInput problems\n"RESET));
	printf(YELLOW"\n\tRight Input"RESET);
	printf("\n\n");
	create_window(save);
	free_all();
	return (1);
}

int	main(int argc, char **argv)
{
	int fd;
	int save;

	save = 0;
	if (argc == 3 || argc == 2)
	{
		if (check_name(argv[1]) == -1)
			return (printf(RED"Error\nWrong file type\n"RESET));
		fd = open(argv[1], O_RDONLY);
		if (argc != 2 && check_flag(argv[2]) == -1)
			return (printf(RED"Error\nWrong arguments\n"RESET));
		if (argc == 3)
			save = 1;
	}
	else
	{
		printf(RED"Error\nWrong number of arguments\n"RESET);
		return (-1);
	}
	if (fd < 0)
		return (printf(RED"Error\nImpossible to open file\n"RESET));
	return (lets_start(fd, save));
}
