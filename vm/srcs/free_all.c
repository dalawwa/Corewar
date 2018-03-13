/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:23:02 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:23:03 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_opts(t_opt *opts)
{
	if (opts)
	{
		free(opts);
		opts = NULL;
	}
}

void	free_list_proc(t_proc_base *list)
{
	if (list)
	{
		while (list->first != NULL)
			kill_process(list->first, list);
		free(list);
		list = NULL;
	}
}

void	free_files(t_file **files)
{
	int	i;

	i = 0;
	if (files)
	{
		while (i < 4)
		{
			if (files[i])
			{
				if (files[i]->name)
					free(files[i]->name);
				files[i]->name = NULL;
				free(files[i]);
				files[i] = NULL;
			}
			i++;
		}
		free(files);
		files = NULL;
	}
}

void	free_arena(t_arena **arena)
{
	if (*arena)
	{
		if ((*arena)->opts)
			free_opts((*arena)->opts);
		if ((*arena)->players)
			free_players((*arena)->players, (*arena)->nb_players);
		if ((*arena)->bdd)
			free_bdd((*arena)->bdd);
		if ((*arena)->list_proc)
			free_list_proc((*arena)->list_proc);
		if ((*arena)->files)
			free_files((*arena)->files);
		free(*arena);
		arena = NULL;
	}
}
