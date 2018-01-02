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

#include "../includes/asm.h"

void	move_in_the_file(char **str)
{
	while (**str && **str != ',' && **str != '\n')
		(*str)++;
	if (**str == '\n')
		return ;
	(*str)++;
	while (**str && (**str == ' ' || **str == '\t'))
		(*str)++;
	return ;
}

//get the position of the label
int	position_label(t_champ *champ, char *file)
{
	size_t	i;

	i = 0;
	while (char_label(file[i]) == 1)
		i++;
	while (champ)
	{
		if (i >= ft_strlen(champ->label))
		{
			if (!ft_strncmp(file, champ->label, i))
				return (champ->position - position);
		}
		else if (!ft_strncmp(file, champ->label, ft_strlen(champ->label)))
			return (champ->position - position);
		champ = champ->next;
	}
	ciao_bye_bye(12);
	return (0);
}

//changer ordre du nombre magique
//++ changer autre nombre parce que pas print dans le bon ordre sinon
int		change_magic_order(int i)
{
		i = ((i >> 24) & 0xff) | ((i >> 8) & 0xff00) | ((i << 8) & 0xff0000) | ((i << 24) & 0xff000000);
		return (i);
}

int		change_magic_order_second(int i)
{
	i = ((i >> 8) & 0xff) | ((i << 8) & 0xff00);
	return (i);
}

//creation du debut du fichier ou on va recuperer les donnes qui sont dans header_t c a d le name et le comment
// check pour resoudre soucis
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


//on va creer un nouveau char * pour transformer le fchier .s en .cor
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

//on avance dans le fichier apres la commande
char		*after_command(char *str, int i)
{
		if (i == 1 || i == 9 || i == 12 || i == 14)
		str = str + 4;
	else if (i == 2 || i == 3 || i == 7)
		str = str + 2;
	else if (i == 15)
		str = str + 5;
	else
		str = str + 3;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}
//move into the file to calculate opcode
int	next_order(char *str, int j)
{
	while (str[j] != ',')
		j++;
	j++;
	while (str[j] == '\t' || str[j] == ' ')
		j++;
	return (j);
}

//opcode depends on register, direct or else
void	opcod_number(char *str, int *o, int i, int c)
{
	if (str[i] == 'r' && c == 1)
		*o = 0x40;
	else if (str[i] == '%' && c == 1)
		*o = 0x80;
	else if (c == 1)
		*o = 0xC0;
	if (str[i] == 'r' && c == 2)
		*o = 0x10;
	else if (str[i] == '%' && c == 2)
		*o = 0x20;
	else if (c == 2)
		*o = 0x30;
	if (str[i] == 'r' && c == 3)
		*o = 0x4;
	else if (str[i] == '%' && c == 3)
		*o = 0x8;
	else if (c == 3)
		*o = 0xC;
}

//calculation to get opcode number and to print it after command number
int		get_opcode(char *str, int fd, int param, int i)
{
	int	o;
	int	m;

	m = 0;
	o = 0;
	opcod_number(str, &o, i, 1);
	m = o;
	if (param > 1)
	{
		i = next_order(str, i);
		opcod_number(str, &o, i, 2);
		m = m + o;
	}
	if (param > 2)
	{
		i = next_order(str, i);
		opcod_number(str, &o, i, 3);
		m = m + o;
	}
	temp++;
	write(fd, &m, 1);
	return (1);
}

//on va executer la traduction en fonction de la commande et des options
int		find_translation_cor(t_champ *champ, char **str, int fd, int i)
{
	*str = after_command(*str, i);
	write(fd, &i, 1);
	if (i == 1)
		return (put_in_file_dir(4, champ, str, fd));
	else if ((i == 2 || i == 13) && get_opcode(*str, fd, 2, 0) && ((put_in_file_dir(4, champ, str, fd) || put_in_file_indir(champ, str, fd))))
		return (put_in_file_reg(str, fd));
	else if ((i == 3 && get_opcode(*str, fd, 2, 0) && put_in_file_reg(str, fd) && (put_in_file_reg(str, fd) || put_in_file_indir(champ, str, fd))))
		return (1);
	else if ((i == 4 || i == 5) && write(fd, "T", 1) && ++temp && put_in_file_reg(str, fd) && put_in_file_reg(str, fd) && put_in_file_reg(str, fd))
		return (1);
	else if ((i == 6 || i == 7 || i == 8) && get_opcode(*str, fd, 3, 0) && ((put_in_file_reg(str, fd) || put_in_file_dir(4, champ, str, fd) || put_in_file_indir(champ, str, fd)) && (put_in_file_reg(str, fd) || put_in_file_dir(4, champ, str, fd) || put_in_file_indir(champ, str, fd))))
		return (put_in_file_reg(str, fd));
	else if (i == 9 || i == 12 || i == 15)
		return (put_in_file_dir(2, champ, str, fd));
	else if (( i == 10 || i == 14) && get_opcode(*str, fd, 3, 0) && (((put_in_file_reg(str, fd) || put_in_file_dir(2, champ, str, fd) || put_in_file_indir(champ, str, fd)) && (put_in_file_reg(str, fd) || put_in_file_dir(2, champ, str, fd)))))
		return (put_in_file_reg(str, fd));
	else if (i == 11 && get_opcode(*str, fd, 3, 0) && ((put_in_file_reg(str, fd) && (put_in_file_reg(str, fd) || put_in_file_dir(2, champ, str, fd) || put_in_file_indir(champ, str, fd)) && (put_in_file_reg(str, fd) || put_in_file_dir(2, champ, str, fd)))))
		return (1);
	else if (i == 16 && write(fd, "@", 1) && ++temp)
		return (put_in_file_reg(str, fd));
	return (1);
}

//on lance la conversion depuis ici !!!
void		launch_cor_conversion(int fd, char *file, t_champ *champ)
{
	int	i;

	i = 0;
	position = 0;
	while (*file)
	{
		while (*file == ' ' || *file == '\t')
			file++;
		i = get_the_op_code(file);
		if (i)
			temp++;
		//here we need a function to write in function of the op code the good code in the cor file
		//then we ll read the file until the next line
		find_translation_cor(champ, &file, fd, i);
		while (*file && *file != '\n')
			file++;
		file++;
		position = position + temp;
		temp = 0;
	}
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
		launch_cor_conversion(fd, file, champ);
	}
	close(fd);
	ft_printf("Writing output program to %s\n", name);
	champ  = NULL;
	op = NULL;
	file = NULL;
	return (1);
}
