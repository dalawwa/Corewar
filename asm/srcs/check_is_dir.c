/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:35:27 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/13 15:37:05 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

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
	return (0);
}
