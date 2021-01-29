/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:26:36 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/17 09:27:42 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	int				fd;
	char			buffer[BUFFER_SIZE + 1];
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
t_list			*find_fd(t_list **head, int fd);
t_list			*new_node(int fd);
char			*ft_realloc(char **ptr, size_t rlen);
void			free_node(t_list **head, t_list *node);
int				put_line(char *buffer, char **line);
int				read_error(char **line);
size_t			ft_strlen(char *s);

#endif
