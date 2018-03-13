/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:23:08 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:23:09 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_one_player(t_play **players, int i)
{
	if (players[i]->name)
		free(players[i]->name);
	players[i]->name = NULL;
	if (players[i]->comment)
		free(players[i]->comment);
	players[i]->comment = NULL;
	if (players[i]->body)
		free(players[i]->body);
	players[i]->body = NULL;
	free(players[i]);
	players[i] = NULL;
}

void	free_players(t_play **players, int nb_players)
{
	int	i;

	i = 0;
	if (players)
	{
		while (i < nb_players)
		{
			if (players[i])
				free_one_player(players, i);
			i++;
		}
		free(players);
	}
	players = NULL;
}

void	free_ocp(t_bdd **bdd, int i)
{
	int	j;

	j = 0;
	while (j < bdd[i]->nb_ocp)
	{
		bdd[i]->ocp[j]->fct = NULL;
		free(bdd[i]->ocp[j]);
		bdd[i]->ocp[j] = NULL;
		j++;
	}
}

void	free_bdd(t_bdd **bdd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (bdd)
	{
		while (i < 16)
		{
			free(bdd[i]->name);
			bdd[i]->name = NULL;
			free(bdd[i]->meaning);
			bdd[i]->meaning = NULL;
			free_ocp(bdd, i);
			free(bdd[i]->ocp);
			bdd[i]->ocp = NULL;
			free(bdd[i]);
			i++;
			j = 0;
		}
		free(bdd);
		bdd = NULL;
	}
}
