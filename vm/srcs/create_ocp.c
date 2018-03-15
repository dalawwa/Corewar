/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ocp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:22:27 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/15 12:08:18 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		create_ocp(t_bdd *bdd_i, int i, int j)
{
	if (i == 1 || i == 2 || i == 12)
		bdd_i->nb_ocp = 2;
	else if (i == 5 || i == 6 || i == 7)
		bdd_i->nb_ocp = 9;
	else if (i == 9 || i == 10 || i == 13)
		bdd_i->nb_ocp = 6;
	else
		bdd_i->nb_ocp = 1;
	bdd_i->ocp = (t_ocp**)malloc(sizeof(t_ocp*) * bdd_i->nb_ocp);
	if (bdd_i->ocp == NULL)
		return (perror_int("Error ", 0));
	while (j < bdd_i->nb_ocp)
	{
		bdd_i->ocp[j] = (t_ocp*)malloc(sizeof(t_ocp));
		if (bdd_i->ocp[j] == NULL)
			return (perror_int("Error ", 0));
		bdd_i->ocp[j]->type_arg1 = '\0';
		bdd_i->ocp[j]->type_arg2 = '\0';
		bdd_i->ocp[j]->type_arg3 = '\0';
		j++;
	}
	set_args_type(bdd_i, i);
	return (1);
}
