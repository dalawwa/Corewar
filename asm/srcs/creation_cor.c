/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_cor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:39:50 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/19 17:41:32 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		change_magic_order(int i)
{
		i = ((i >> 24) & 0xff) | ((i >> 8) & 0xff00) | ((i << 8) & 0xff0000) | ((i << 24) & 0xff000000);
		return (i);
}

#include "../includes/asm.h"
void	create_up_file(int fd, header_t *op)
{
	int	i;
	int	j;

	j = COREWAR_EXEC_MAGIC;
	i = 0;
	j = change_magic_order(j);
	write(fd, &j, 4);
	while (op->prog_name[i])
	{
		write(fd, &op->prog_name[i], 1);
		i++;
	}
	while (i < 128)
	{
		write(fd, "\0", 1);
		i++;
	}
	position = change_magic_order(position);
	write(fd, "\0\0\0\0", 4);
	write(fd, &position, 4);
	i = 0;
	while (op->comment[i])
	{
		write(fd, &op->comment[i], 1);
		i++;
	}
	while (i < 2052)
	{
		write(fd, "\0", 1);
		i++;
	}
	return ;
}

char	*name_dot_cor(char *str)
{
	char	*name;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	name = ft_strnew(j + 3);
	while (i < j - 1)
	{
		name[i] = str[i];
		i++;
	}
	name[i] = 'c';
	i++;
	name[i] = 'o';
	i++;
	name[i] = 'r';
	i++;
	name[i] = '\0';
	return (name);
}

//obtenir le nom du fichier et creer un char *.cor qui servira a enregistrer le new file
//create and launch with OPEN (READ &WRITE) with the file.cor
//create file with magic numbers, name of the program, then command
//then use the file to print everything to have a good asm

int		launch_creation_cor(char *file, t_champ *champ, header_t *op, char *str)
{
	char	*name;
	int		fd;

	name = name_dot_cor(str);
	if ((fd = open(name, O_RDWR | O_CREAT, 0666)) > -1)
	{
		create_up_file(fd, op);
	}
	file = NULL;
	champ  = NULL;
	op = NULL;
	return (1);
}
