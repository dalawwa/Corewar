/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:13:33 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/06 09:17:27 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		next_get_the_op_code(char *str)
{
	if (ft_strequ(str, "fork"))
		return (12);
	if (ft_strequ(str, "lld"))
		return (13);
	if (ft_strequ(str, "lldi"))
		return (14);
	if (ft_strequ(str, "lfork"))
		return (15);
	if (ft_strequ(str, "aff"))
		return (16);
	return ('0');
}

int		get_the_op_code(char *str)
{
	if (ft_strequ(str, "live"))
		return (1);
	if (ft_strequ(str, "ld"))
		return (2);
	if (ft_strequ(str, "st"))
		return (3);
	if (ft_strequ(str, "add"))
		return (4);
	if (ft_strequ(str, "sub"))
		return (5);
	if (ft_strequ(str, "and"))
		return (6);
	if (ft_strequ(str, "or"))
		return (7);
	if (ft_strequ(str, "xor"))
		return (8);
	if (ft_strequ(str, "zjmp"))
		return (9);
	if (ft_strequ(str, "ldi"))
		return (10);
	if (ft_strequ(str, "sti"))
		return (11);
	return (next_get_the_op_code(str));
}
