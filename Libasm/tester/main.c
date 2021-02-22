/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:59:34 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/22 11:59:40 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RED "\033[31;1m"
# define GREEN "\033[32;1;4m"
# define GREEN2 "\033[32;1m"
# define YELLOW "\033[33;1;4m"
# define YELLOW2 "\033[33m"
# define CYAN "\033[36;1;4m"
# define CYAN2 "\033[36m"
# define RESET "\033[0m"
#include <fcntl.h>
#include <unistd.h>
#include "../includes/libasm.h"

int one = 1;
int two = 2;
int three = 3;
int n = 8;
int c = 3;
int q = 4;
void	check_strlen()
{
	char *empty = "";
	char *null = 0;
	char *l = "I cavalli non possono vomitare.\nLa motivazione è tutta nella struttura anatomica dell’apparato digerente del cavallo. In generale, lo stomaco degli erbivori non è adatto ad espellere gli alimenti, e il cavallo poi proprio non riesce a vomitare perché la valvola che mette in comunicazione lo stomaco con l’esofago è molto potente e si apre solo in una direzione, verso l’interno.";

	printf(CYAN"FT_STRLEN\n\n"RESET);
	int real;
	int mine;
	mine = ft_strlen(empty);
	real = strlen(empty);
	printf(CYAN2"empty string"RESET);
	if (real == mine)
		printf(GREEN2"\t[ok]\n"RESET);
	else
		printf(RED"\t[ko]\n"RESET);
	 printf(CYAN2"null string"RESET);
	mine = ft_strlen(null);
	if (mine == 0)
		printf(GREEN2"\t[ok]\n"RESET);
	else
		printf(RED"\t[ko]\n"RESET); 
	mine = ft_strlen(l);
	real = ft_strlen(l);
	printf(CYAN2"long string"RESET);
	if (real == mine)
		printf(GREEN2"\t[ok]\n\n"RESET);
	else
		printf(RED"\t[ko]\n\n"RESET);
}

void	check_strcpy()
{
	char *empty = "";
	char *l = "I cavalli non possono vomitare.\nLa motivazione è tutta nella struttura anatomica dell’apparato digerente del cavallo. In generale, lo stomaco degli erbivori non è adatto ad espellere gli alimenti, e il cavallo poi proprio non riesce a vomitare perché la valvola che mette in comunicazione lo stomaco con l’esofago è molto potente e si apre solo in una direzione, verso l’interno.";

	char *mine = malloc(strlen(l) + 1);
	char *real = malloc(strlen(l) + 1);
	mine = ft_strcpy(mine, empty);
	real = strcpy(real, empty);
	printf(CYAN"FT_STRCPY\n\n"RESET);
	printf(CYAN2"empty string"RESET);
	if (strcmp(real, mine) == 0)
		printf(GREEN2"\t[ok]\n"RESET);
	else
		printf(RED"\t[ko]\n"RESET);
	mine = ft_strcpy(mine, l);
	real = strcpy(real, l);
	printf(CYAN2"long string"RESET);
	if (strcmp(real, mine) == 0)
		printf(GREEN2"\t[ok]\n\n"RESET);
	else
		printf(RED"\t[ko]\n\n"RESET);
}

void	check_strcmp()
{
	char *empty = "";
	char *l = "I cavalli non possono vomitare.\nLa motivazione è tutta nella struttura anatomica dell’apparato digerente del cavallo. In generale, lo stomaco degli erbivori non è adatto ad espellere gli alimenti, e il cavallo poi proprio non riesce a vomitare perché la valvola che mette in comunicazione lo stomaco con l’esofago è molto potente e si apre solo in una direzione, verso l’interno.";
	printf(CYAN"FT_STRCMP\n\n"RESET);
	int mine;
	int real;
	mine = ft_strcmp(empty, empty);
	real = strcmp(empty, empty);
	printf(CYAN2"empty strings"RESET);
	if (real == mine)
		printf(GREEN2"\t[ok]"RESET);
	else
		printf(RED"\t[ko]"RESET);
	mine = ft_strcmp(empty, l);
	real = strcmp(empty, l);
	//printf(CYAN2"first empty"RESET);
	if ((real > 0 &&  mine > 0) || (real < 0 &&  mine < 0))
	 	printf(GREEN2"\t[ok]"RESET);
	else
		printf(RED"\t[ko]"RESET);
	mine = ft_strcmp(l, empty);
	real = strcmp(l, empty);
	//printf(CYAN2"second empty"RESET);
	if ((real > 0 &&  mine > 0) || (real < 0 &&  mine < 0))
		printf(GREEN2"\t[ok]\n"RESET);
	else
		printf(RED"\t[ko]\n"RESET);
	mine = ft_strcmp("CIAO", "ciao");
	real = strcmp("CIAO", "ciao");
	printf(CYAN2"basic test");
	if ((real > 0 &&  mine > 0) || (real < 0 &&  mine < 0)|| (real == 0 &&  mine == 0))
	 	printf(GREEN2"\t[ok]"RESET);
	else
	 	printf(RED"\t[ko]"RESET);
	mine = ft_strcmp("cIAO", "Ciao");
	real = strcmp("cIAO", "Ciao");
	if ((real > 0 &&  mine > 0) || (real < 0 &&  mine < 0)|| (real == 0 &&  mine == 0))
		printf(GREEN2"\t[ok]"RESET);
	else
		printf(RED"\t[ko]"RESET);
	mine = ft_strcmp("cia", "ciao");
	real = strcmp("cia", "ciao");
	if ((real > 0 &&  mine > 0) || (real < 0 &&  mine < 0)|| (real == 0 &&  mine == 0))
		printf(GREEN2"\t[ok]"RESET);
	else
		printf(RED"\t[ko]"RESET);
	mine = ft_strcmp("ciao", "ciao");
	real = strcmp("ciao", "ciao");
 	if ((real > 0 &&  mine > 0) ||  (real < 0 &&  mine < 0) || (real == 0 &&  mine == 0))
 		printf(GREEN2"\t[ok]\n\n");
 	else
 		printf(RED"\t[ko]\n\n"RESET);

}

void	check_write()
{
	printf(CYAN"FT_WRITE\n\n"RESET);
	fflush(stdout);
	printf(CYAN2"stdout");
	fflush(stdout);
	printf(GREEN2"\t\t");
	fflush(stdout);
	ft_write(1, "[ok]", 4);
	printf("\n"RESET);
	int fd = open("text.txt", O_WRONLY | O_CREAT, 0755);
	int fdd = open("textft.txt", O_WRONLY | O_CREAT, 0755);
	errno = 0;
	printf(CYAN2"right file"RESET);
	ft_write(fdd, "La parola 'gorilla' deriva da una parola greca che significa 'una tribù di donne pelose'", 88);
	int err = errno;
	write(fd, "La parola 'gorilla' deriva da una parola greca che significa 'una tribù di donne pelose'", 88);
	if (err == errno)
 		printf(GREEN2"\t[ok]\n"RESET);
 	else
 		printf(RED"\t[ko]\n"RESET);
	printf(CYAN2"wrong file"RESET);
	ft_write(5, "I gatti non possono sentire il sapore dolce", 45);
	err = errno;
	write(5, "I gatti non possono sentire il sapore dolce", 45);
	if (err == errno)
 		printf(GREEN2"\t[ok]\n\n");
 	else
 		printf(RED"\t[ko]\n\n"RESET);
}

void	check_read()
{
	printf(CYAN"FT_READ\n\n"RESET);
	fflush(stdout);


	char	buff[100];
	char	buffr[100];
	int fd = 0;
	errno = 0;
	printf(YELLOW2"Type \"42\": "RESET);
	fflush(stdout);							//fflush to print before \n
	int len = ft_read(0, buff, 88);
	buff[len] = 0;
	printf(CYAN2"stdin\t"RESET);
	if (strcmp(buff, "42\n") == 0)
		printf(GREEN2"\t[ok]\n"RESET);
	else
		printf(RED"\t[ko]\n"RESET);
	//read(0, buffr, 88);
	//printf(GREEN2"%s"RESET,buff);
	int err;
	fd = open("text.txt", O_RDONLY);
	errno = 0;
	printf(CYAN2"right file"RESET);
	bzero(buff, 100);
	bzero(buffr, 100);
	ft_read(fd, buff, 89);
	close(fd);
	fd = open("text.txt", O_RDONLY);
	err = errno;
	read(fd, buffr, 89);
	if (!strcmp(buff, buffr) && err == errno)
 		printf(GREEN2"\t[ok]\n"RESET);
 	else
 		printf(RED"\t[ko]\n"RESET);
	printf(CYAN2"wrong file"RESET);
	ft_read(5, "I gatti non possono sentire il sapore dolce", 45);
	err = errno;
	read(5, "I gatti non possono sentire il sapore dolce", 45);
	if (err == errno)
 		printf(GREEN2"\t[ok]\n\n");
 	else
 		printf(RED"\t[ko]\n\n"RESET);

}

void	check_strdup()
{
	char *empty = "";
	char *l = "I cavalli non possono vomitare.\nLa motivazione è tutta nella struttura anatomica dell’apparato digerente del cavallo. In generale, lo stomaco degli erbivori non è adatto ad espellere gli alimenti, e il cavallo poi proprio non riesce a vomitare perché la valvola che mette in comunicazione lo stomaco con l’esofago è molto potente e si apre solo in una direzione, verso l’interno.";
	printf(CYAN"FT_STRDUP\n\n"RESET);
	char *mine = ft_strdup(empty);
	char *real = strdup(empty);
	printf(CYAN2"empty string"RESET);
	if (strcmp(real, mine) == 0)
		printf(GREEN2"\t[ok]\n"RESET);
	else
		printf(RED"\t[ko]\n"RESET);
	mine = ft_strdup(l);
	real = strdup(l);
	printf(CYAN2"long string"RESET);
	if (strcmp(real, mine) == 0)
		printf(GREEN2"\t[ok]\n\n"RESET);
	else
		printf(RED"\t[ko]\n\n"RESET);
}

int		main()
{

	printf(CYAN2"\n██╗     ██╗██████╗  █████╗ ███████╗███╗   ███╗    ████████╗███████╗███████╗████████╗███████╗██████╗\n");
	printf("██║     ██║██╔══██╗██╔══██╗██╔════╝████╗ ████║    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██╔══██╗\n");
	printf("██║     ██║██████╔╝███████║███████╗██╔████╔██║       ██║   █████╗  ███████╗   ██║   █████╗  ██████╔╝\n");
	printf("██║     ██║██╔══██╗██╔══██║╚════██║██║╚██╔╝██║       ██║   ██╔══╝  ╚════██║   ██║   ██╔══╝  ██╔══██╗\n");
	printf("███████╗██║██████╔╝██║  ██║███████║██║ ╚═╝ ██║       ██║   ███████╗███████║   ██║   ███████╗██║  ██║\n");
	printf("╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝\n");
	printf("                                                                          etaranti, mcossu, ade-feli\n"RESET);

	printf(YELLOW"--Mandatory part--\n\n"RESET);
	check_strlen();
	check_strcpy();
	check_strcmp();
	check_write();
	check_read();
	check_strdup();
}
