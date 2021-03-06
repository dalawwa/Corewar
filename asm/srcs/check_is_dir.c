/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:35:27 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/30 09:07:14 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		put_in_file_dir(int i, t_champ *champ, char **file, int fd)
{
	int	j;

	j = 0;
	if (**file != '%')
		return (0);
	(*file)++;
	if (*file && **file == ':' && (*file)++)
		j = position_label(champ, *file);
	else
		j = ft_atoi(*file);
	if (i == 4)
		j = change_magic_order(j);
	else
		j = change_magic_order_second(j);
	write(fd, &j, i);
	g_temp = g_temp + i;
	move_in_the_file(file);
	return (1);
}

void	check_if_nothing_after(char **str)
{
	while (**str == '\t' || **str == ' ')
		(*str)++;
	if (**str != '\0' && **str != '\n' && **str != ';' && **str != '#')
	{
		if (**str == ',')
			ciao_bye_bye(4);
		else
			ciao_bye_bye(7);
	}
}

void	check_if_something_after(char **str)
{
	while (**str == '\t' || **str == ' ')
		(*str)++;
	if (**str != ',')
		ciao_bye_bye(9);
	(*str)++;
	while (**str == '\t' || **str == ' ')
		(*str)++;
	return ;
}

int		check_is_direct(int i, char **str, int opc)
{
	if (**str == '%')
	{
		if (opc > 8 && opc != 13)
			g_position = g_position + 2;
		else
			g_position = g_position + 4;
		(*str)++;
		if (**str != ':' && !(**str >= '0' && **str <= '9')
				&& **str != '-' && **str != '+')
			ciao_bye_bye(9);
		if (**str == ':')
			(*str)++;
		else if (**str == '+' || **str == '-')
			(*str)++;
		while (**str && char_label(**str) == 1)
			(*str)++;
		while (**str == ' ' || **str == '\t')
			(*str)++;
		if (i == 1)
			check_if_something_after(str);
		else
			check_if_nothing_after(str);
		return (1);
	}
	return (0);
}
