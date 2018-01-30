/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_cor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:39:50 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/30 09:47:31 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			get_opcode(char *str, int fd, int param, int i)
{
	int		o;
	int		m;

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
	g_temp++;
	write(fd, &m, 1);
	return (1);
}

int			find_translation_cor2(t_champ *champ, char **str, int fd, int i)
{
	if (i == 9 || i == 12 || i == 15)
		return (put_in_file_dir(2, champ, str, fd));
	else if ((i == 10 || i == 14) && get_opcode(*str, fd, 3, 0)
			&& (((put_in_file_reg(str, fd)
						|| put_in_file_dir(2, champ, str, fd)
						|| put_in_file_indir(champ, str, fd))
					&& (put_in_file_reg(str, fd)
						|| put_in_file_dir(2, champ, str, fd)))))
		return (put_in_file_reg(str, fd));
	else if (i == 11 && get_opcode(*str, fd, 3, 0)
			&& ((put_in_file_reg(str, fd) && (put_in_file_reg(str, fd)
						|| put_in_file_dir(2, champ, str, fd)
						|| put_in_file_indir(champ, str, fd))
					&& (put_in_file_reg(str, fd)
						|| put_in_file_dir(2, champ, str, fd)))))
		return (1);
	else if (i == 16 && write(fd, "@", 1) && ++g_temp)
		return (put_in_file_reg(str, fd));
	return (1);
}

int			find_translation_cor(t_champ *champ, char **str, int fd, int i)
{
	*str = after_command(*str, i);
	write(fd, &i, 1);
	if (i == 1)
		return (put_in_file_dir(4, champ, str, fd));
	else if ((i == 2 || i == 13) && get_opcode(*str, fd, 2, 0)
			&& ((put_in_file_dir(4, champ, str, fd)
					|| put_in_file_indir(champ, str, fd))))
		return (put_in_file_reg(str, fd));
	else if ((i == 3 && get_opcode(*str, fd, 2, 0) && put_in_file_reg(str, fd)
				&& (put_in_file_reg(str, fd)
					|| put_in_file_indir(champ, str, fd))))
		return (1);
	else if ((i == 4 || i == 5) && write(fd, "T", 1)
			&& ++g_temp && put_in_file_reg(str, fd) && put_in_file_reg(str, fd)
			&& put_in_file_reg(str, fd))
		return (1);
	else if ((i == 6 || i == 7 || i == 8) && get_opcode(*str, fd, 3, 0)
			&& ((put_in_file_reg(str, fd) || put_in_file_dir(4, champ, str, fd)
					|| put_in_file_indir(champ, str, fd))
				&& (put_in_file_reg(str, fd)
					|| put_in_file_dir(4, champ, str, fd)
					|| put_in_file_indir(champ, str, fd))))
		return (put_in_file_reg(str, fd));
	else
		return (find_translation_cor2(champ, str, fd, i));
}

void		launch_cor_conversion(int fd, char *file, t_champ *champ)
{
	int	i;

	i = 0;
	g_position = 0;
	while (*file)
	{
		while (*file == ' ' || *file == '\t')
			file++;
		i = get_the_op_code(file);
		if (i)
			g_temp++;
		find_translation_cor(champ, &file, fd, i);
		while (*file && *file != '\n')
			file++;
		file++;
		g_position = g_position + g_temp;
		g_temp = 0;
	}
}

int			creat_cor(char *f, t_champ *champ, t_header *op, char *s)
{
	char	*name;
	int		fd;

	name = name_dot_cor(s);
	if ((fd = open(name, O_RDWR | O_CREAT, 0666)) > -1)
	{
		create_up_file(fd, op);
		launch_cor_conversion(fd, f, champ);
	}
	close(fd);
	ft_printf("Writing output program to %s\n", name);
	champ = NULL;
	op = NULL;
	f = NULL;
	if (name)
		free(name);
	return (1);
}
