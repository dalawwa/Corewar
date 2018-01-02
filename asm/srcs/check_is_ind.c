/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_ind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:37:16 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/18 16:34:52 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int             put_in_file_indir(t_champ *champ, char **file, int fd)
{
	int	j;

	j = 0;
	if (**file == ':' && (*file)++)
		j = position_label(champ, *file);
	else
		j = ft_atoi(*file);
	j = change_magic_order_second(j);
	write(fd, &j, 2);
	temp = temp + 2;
	move_in_the_file(file);
	return (1);
}

int		check_is_indirect(int i, char **str)
{
	if (**str == ':')
	{
		(*str)++;
		while (**str && char_label(**str))
			(*str)++;
	}
	else if (((**str == '+' || **str == '-') && (*str)++) || ft_isdigit(**str))
	{
		while (ft_isdigit(**str))
			(*str)++;
	}
	else
	{
		return (0);
	}
	if (**str != '\0' && **str != '\n' && **str != ',' && **str != ' ' && **str != '\t')
		ciao_bye_bye(1);
	position = position + 2;
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
