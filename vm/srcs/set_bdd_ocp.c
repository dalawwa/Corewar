/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bdd_ocp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:53:59 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:54:00 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_ptr_op_3(t_bdd *bdd_i, int i, int j)
{
	if (i == 9)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_ldi;
			j++;
		}
	}
	else if (i == 10)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_sti;
			j++;
		}
	}
	else if (i == 11)
		bdd_i->ocp[j]->fct = &op_fork;
	else if (i == 12)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_lld;
			j++;
		}
	}
}

void	set_ptr_op_2(t_bdd *bdd_i, int i, int j)
{
	if (i == 5)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_and;
			j++;
		}
	}
	else if (i == 6)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_or;
			j++;
		}
	}
	else if (i == 7)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_xor;
			j++;
		}
	}
	else if (i == 8)
		bdd_i->ocp[j]->fct = &op_zjmp;
}


void	set_ptr_op_1(t_bdd *bdd_i, int i, int j)
{
	if (i == 0)
		bdd_i->ocp[j]->fct = &op_live;
	else if (i == 1)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_ld;
			j++;
		}
	}
	else if (i == 2)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_st;
			j++;
		}
	}
	else if (i == 3)
		bdd_i->ocp[j]->fct = &op_add;
	else if (i == 4)
		bdd_i->ocp[j]->fct = &op_sub;
	else if (i == 14)
		bdd_i->ocp[j]->fct = &op_lfork;
}

void	set_ptr_op(t_bdd *bdd_i, int i, int j)
{
	if (i <= 4 || i == 14)
		set_ptr_op_1(bdd_i, i, 0);
	else if (i > 4 && i <= 8)
		set_ptr_op_2(bdd_i, i, 0);
	else if (i > 8 && i <= 12)
		set_ptr_op_3(bdd_i, i, 0);
	else if (i == 13)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_lldi;
			j++;
		}
	}
	else if (i == 15)
		bdd_i->ocp[j]->fct = &op_aff;
}

int		set_bdd_ocp(t_arena *arena)
{
	int	i;

	i = 0;
	while (i < NB_OP)
	{
		arena->bdd[i]->nb_ocp = 0;
		create_ocp(arena->bdd[i], i);
		if (arena->bdd[i]->ocp == NULL)
			return (0);
		i++;
	}
	set_ocp_and_size(arena->bdd);
	i = 0;
	while (i < NB_OP)
	{
		set_ptr_op(arena->bdd[i], i, 0);
		i++;
	}
	return (1);
}
