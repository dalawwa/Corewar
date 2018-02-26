/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_reg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:32:33 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/30 09:18:27 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		put_in_file_reg(char **file, int fd)
{
	int	j;

	j = 0;
	if (**file != 'r')
		return (0);
	j = ft_atoi(++(*file));
	write(fd, &j, 1);
	g_temp = g_temp + 1;
	move_in_the_file(file);
	return (1);
}

void	reg_is_the_last(char **str)
{
	while (**str == '\t' || **str == ' ')
		(*str)++;
	if (**str != '\n' && **str != '\0' && **str != ';' && **str != '#')
	{
		if (**str == ',')
			ciao_bye_bye(3);
		else
			ciao_bye_bye(7);
	}
}

void	reg_is_not_the_last(char **str)
{
	while (**str == '\t' || **str == ' ')
		(*str)++;
	if (**str != ',')
		ciao_bye_bye(9);
	(*str)++;
	while (**str == '\t' || **str == ' ')
		(*str)++;
}

int		check_is_reg(int i, char **str)
{
	int j;

	j = 0;
	if (**str == 'r')
	{
		(*str)++;
		j = ft_atoi(*str);
		if (j > 99 || j < 0)
			ciao_bye_bye(9);
		(*str)++;
		if (j > 9)
			(*str)++;
		g_position = g_position + 1;
		if (i == 1)
			reg_is_not_the_last(str);
		else
			reg_is_the_last(str);
		return (1);
	}
	return (0);
}
