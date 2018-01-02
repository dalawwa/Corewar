/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_reg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:32:33 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/13 15:34:08 by bfruchar         ###   ########.fr       */
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
	temp = temp + 1;
	move_in_the_file(file);
	return (1);
}

//on va verifier qu il s agit bien d un registre
//on va regarder si il commence par r et si il est compris entre 1 et 16
//on va mettre sa taille dans la struct

int		check_is_reg(int i, char **str)
{
	int j;

	j = 0;
	if (**str == 'r')
	{
		(*str)++;
		j = ft_atoi(*str);
		if (j > 99 || j <= 0)
			ciao_bye_bye(1);
		(*str)++;
		if (j > 9)
			(*str)++;
		position = position + 1;
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
	return (0);
}
