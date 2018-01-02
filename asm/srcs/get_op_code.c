/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:13:33 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/11 16:17:41 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		next_get_the_op_code2(char *str)
{
	if (ft_strnequ(str, "fork", 4))
		return (12);
	if (ft_strnequ(str, "lldi", 4))
		return (14);
	if (ft_strnequ(str, "lld", 3))
		return (13);
	if (ft_strnequ(str, "lfork", 5))
		return (15);
	if (ft_strnequ(str, "aff", 3))
		return (16);
	return (0);
}

int		get_the_op_code2(char *str)
{
	while (*str == ' ' || *str == '\t')
		(*str)++;
	if (ft_strnequ(str, "live", 4))
		return (1);
	if (ft_strnequ(str, "ldi", 3))
		return (10);
	if (ft_strnequ(str, "ld", 2))
		return (2);
	if (ft_strnequ(str, "sti", 3))
		return (11);
	if (ft_strnequ(str, "st", 2))
		return (3);
	if (ft_strnequ(str, "add", 3))
		return (4);
	if (ft_strnequ(str, "sub", 3))
		return (5);
	if (ft_strnequ(str, "and", 3))
		return (6);
	if (ft_strnequ(str, "or", 2))
		return (7);
	if (ft_strnequ(str, "xor", 3))
		return (8);
	if (ft_strnequ(str, "zjmp", 4))
		return (9);
	return (next_get_the_op_code2(str));
}

int		next_get_the_op_code(char *str)
{
	if (ft_strnequ(str, "fork", 4))
		return (12);
	if (ft_strnequ(str, "lldi", 4))
		return (14);
	if (ft_strnequ(str, "lld", 3))
		return (13);
	if (ft_strnequ(str, "lfork", 5))
		return (15);
	if (ft_strnequ(str, "aff", 3))
		return (16);
	return (0);
}

int		get_the_op_code(char *str)
{
	if (ft_strnequ(str, "live", 4))
		return (1);
	if (ft_strnequ(str, "ldi", 3))
		return (10);
	if (ft_strnequ(str, "ld", 2))
		return (2);
	if (ft_strnequ(str, "sti", 3))
		return (11);
	if (ft_strnequ(str, "st", 2))
		return (3);
	if (ft_strnequ(str, "add", 3))
		return (4);
	if (ft_strnequ(str, "sub", 3))
		return (5);
	if (ft_strnequ(str, "and", 3))
		return (6);
	if (ft_strnequ(str, "or", 2))
		return (7);
	if (ft_strnequ(str, "xor", 3))
		return (8);
	if (ft_strnequ(str, "zjmp", 4))
		return (9);
	return (next_get_the_op_code(str));
}
