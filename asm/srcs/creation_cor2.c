/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_cor2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:55:28 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/30 09:47:50 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		move_in_the_file(char **str)
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

int			position_label(t_champ *champ, char *file)
{
	size_t		i;

	i = 0;
	while (char_label(file[i]) == 1)
		i++;
	while (champ)
	{
		if (i >= ft_strlen(champ->label))
		{
			if (!ft_strncmp(file, champ->label, i))
			{
				return (champ->position - g_position);
			}
		}
		else if (!ft_strncmp(file, champ->label, ft_strlen(champ->label)))
			return (champ->position - g_position);
		champ = champ->next;
	}
	ciao_bye_bye(12);
	return (0);
}

int			change_magic_order(int i)
{
	i = ((i >> 24) & 0xff) | ((i >> 8) & 0xff00)
		| ((i << 8) & 0xff0000) | ((i << 24) & 0xff000000);
	return (i);
}

int			change_magic_order_second(int i)
{
	i = ((i >> 8) & 0xff) | ((i << 8) & 0xff00);
	return (i);
}

void		create_up_file(int fd, t_header *op)
{
	int		i;
	int		j;

	i = 0;
	j = change_magic_order(COREWAR_EXEC_MAGIC);
	write(fd, &j, 4);
	while (op->prog_name[i])
		write(fd, &op->prog_name[i++], 1);
	while (i++ < 128)
		write(fd, "\0", 1);
	g_position = change_magic_order(g_position);
	write(fd, "\0\0\0\0", 4);
	write(fd, &g_position, 4);
	i = 0;
	while (op->comment[i])
		write(fd, &op->comment[i++], 1);
	while (i++ < 2052)
		write(fd, "\0", 1);
	return ;
}
