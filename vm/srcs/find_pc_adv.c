/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pc_adv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:22:55 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/15 12:23:47 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

int		get_adv(int adv)
{
	int		tmp;

	tmp = ft_abs(adv) % MEM_SIZE;
	return (adv < 0 ? (MEM_SIZE - tmp) : tmp);
}

int		find_pc_ad_stop(int pc, int adv, int i)
{
	if (adv < 0x8000 && adv >= 0)
	{
		pc = pc + (adv % IDX_MOD);
		if (pc >= MEM_SIZE)
			return (0);
	}
	else if (adv >= 0x8000)
	{
		adv = IDX_MOD - (adv % IDX_MOD);
		if (adv == 512)
			adv = 0;
		pc = pc - adv;
		if (pc < 0)
			return (0);
	}
	else
	{
		while (i-- > adv)
		{
			if (pc == 0)
				pc = MEM_SIZE;
			pc--;
		}
	}
	return (pc);
}

int		find_pc_adv(int pc, int adv, int stop)
{
	int	adv_tmp;

	adv_tmp = 0;
	if (stop == 0)
	{
		if (adv < 0x8000)
		{
			pc = pc + (adv % IDX_MOD);
			if (pc >= MEM_SIZE)
				pc = pc - MEM_SIZE;
		}
		else
		{
			adv_tmp = IDX_MOD - (adv % IDX_MOD);
			if (adv_tmp == 512)
				adv_tmp = 0;
			pc = pc - adv_tmp;
			if (pc < 0)
				pc = MEM_SIZE + pc;
		}
	}
	else
		return (find_pc_ad_stop(pc, adv, 0));
	return (pc);
}
