/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:35:27 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/08 13:58:32 by bfruchar         ###   ########.fr       */
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
	temp = temp + i;
	move_in_the_file(file);
	return (1);
}

int		check_is_direct(int i, char **str, int opc)
{
	if (**str == '%')
	{
		if (opc > 8 && opc != 13)
			position = position + 2;
		else
			position = position + 4;
		(*str)++;
		if (**str != ':' && !(**str >= '0' && **str <= '9') && **str != '-' && **str != '+')
			ciao_bye_bye(1);
		if (**str == ':')
			(*str)++;
		else if (**str == '+' || **str == '-')
			(*str)++;
		while (**str && char_label(**str) == 1)
			(*str)++;
		while (**str == ' ' || **str == '\t')
			(*str)++;
		if (i == 1)
		{
			while (**str == '\t' || **str == ' ')
				(*str)++;
			if (**str != ',')
				ciao_bye_bye(1);
			(*str)++;
			while (**str == '\t' || **str == ' ')
				(*str)++;
		}
		return (1);
	}
	else
		return (0);
	return (0);
}
