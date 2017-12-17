/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_ind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:37:16 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/13 15:39:14 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"


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
		ft_putstr("out");
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
