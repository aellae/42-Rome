/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:28:51 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/04 12:41:40 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define RED "\033[31;1m"
# define GREEN "\033[32;1;4m"
# define GREEN2 "\033[32;1m"
# define YELLOW "\033[33;1;4m"
# define YELLOW2 "\033[33m"
# define CYAN "\033[36;1m"
# define CYAN2 "\033[36m"
# define RESET "\033[0m"
# define W_BGROUND "\e[7m"

typedef struct	s_string
{
	char			*s;
	char			apix;
	struct s_string	*next;
}				t_string;

typedef	struct	s_comm
{
	char			**arguments;
	char			*command;
	int				pipe;
	int				fdin;
	int				fdout;
	struct s_comm	*next;
}				t_comm;

int				skip_spaces(int i, char *s);
int				is_spaces(char c);
void			welcome(void);
char			*charjoin(char *s, char c, int max);
t_comm			*new_node(void);
t_string		*new_list(void);
void			free_comm(t_comm *head);
void			free_list(t_string *head);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *s);
char			*add_str(char *first, char *second);
char			*add_str_notfree(char *first, char *second);
char			*ft_itoa(int n);
void			ft_strcpy(char *dst, const char *src);
char			**ft_split(char const *s, char c);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strdup(char *src);
unsigned char	ft_atochar(const char *str);
void			cute_cat(int i);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_elbowing(char *to_be_changed, char to_inser, int cursor);
int				ft_isprint(int c);

#endif
