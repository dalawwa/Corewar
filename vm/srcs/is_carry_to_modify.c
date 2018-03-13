/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_carry_to_modify.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:23:48 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:23:49 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_carry_to_modify(t_exe *exe)
{
	if (exe->opcode == 2 || exe->opcode == 13)
	{	
		if (exe->arg1->d_value == 0)
			exe->process->carry = 1;
		else
			exe->process->carry = 0;
	}
	return (0);
}
