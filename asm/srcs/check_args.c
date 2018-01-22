/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:21:43 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/09 12:25:38 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		check_args_valid_next(char **str, int opc)
{
	if ((opc == 10 || opc == 14) && (check_is_reg(1, str)
				|| check_is_indirect(1, str) || check_is_direct(1, str, opc))
			&& (check_is_reg(1, str) || check_is_direct(1, str, opc))
			&& check_is_reg(0, str))
		return (1);
	else if (opc == 11 && check_is_reg(1, str)
			&& (check_is_reg(1, str) || check_is_indirect(1, str)
				|| check_is_direct(1, str, opc))
			&& (check_is_reg(0, str) || check_is_direct(0, str, opc)))
		return (1);
	else if (opc == 16 && check_is_reg(0, str))
		return (1);
	return (0);
}

int		check_args_valid(char **str, int opc)
{
	while (**str == '\t' || **str == ' ')
		(*str)++;
	if ((opc == 1 || opc == 9 || opc == 15 || opc == 12)
			&& (check_is_direct(0, str, opc)))
		return (1);
	else if ((opc == 2 || opc == 13) &&
			(check_is_indirect(1, str) || check_is_direct(1, str, opc))
			&& (check_is_reg(0, str)))
		return (1);
	else if (opc == 3 && check_is_reg(1, str)
			&& (check_is_reg(0, str) || check_is_indirect(0, str)))
		return (1);
	else if ((opc == 4 || opc == 5)
			&& check_is_reg(1, str) && check_is_reg(1, str)
			&& check_is_reg(0, str))
		return (1);
	else if ((opc == 6 || opc == 7 || opc == 8)
			&& (check_is_reg(1, str) || check_is_indirect(1, str)
				|| check_is_direct(1, str, opc)) && (check_is_reg(1, str)
				|| check_is_indirect(1, str) || check_is_direct(1, str, opc))
			&& check_is_reg(0, str))
		return (1);
	else if (opc == 10 || opc == 14 || opc == 11 || opc == 16)
		return (check_args_valid_next(str, opc));
	return (0);
}
