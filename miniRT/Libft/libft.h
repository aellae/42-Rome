/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:51:22 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:51:25 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1

typedef struct	s_memory
{
	int				fd;
	char			*buffer;
	struct s_memory	*next;
}				t_memory;

int				ft_atoi(const char *n);
int				ft_concatenate_buffers(t_memory *source, char *line);
void			ft_free_for_all(t_memory *start);
int				ft_read_fd(t_memory **c_pointer, int *list_len, int fd);
int				ft_setup(t_memory **s_pt, t_memory **c_pt,
					char *memory, int fd);
int				get_next_line(int fd, char **line);
t_memory		*ft_new_struct(int fd);
int				ft_check_newline(char *reading);
char			*ft_shift_string(char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);

#endif
