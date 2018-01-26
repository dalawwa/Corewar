#include "corewar.h"

void	free_opts(t_opt *opts)
{
	if (opts)
	{
		free(opts);
		opts = NULL;
	}
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
			i++;
		}
		free(players);
	}
	players = NULL;
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
//			ft_printf("nb_ocp to free dans bdd[%d] = %d\n", i, bdd[i]->nb_ocp);
			while (j < bdd[i]->nb_ocp)
			{
				bdd[i]->ocp[j]->fct = NULL;
//				ft_printf("free : bbd[%d]->ocp[%d]\n", i, j);
				free(bdd[i]->ocp[j]);
				bdd[i]->ocp[j] = NULL;
				j++;
			}
//			ft_putchar('\n');
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
		if ((*arena)->default_adv)
			free((*arena)->default_adv);
		if ((*arena)->list_proc)
			free_list_proc((*arena)->list_proc);
		if ((*arena)->files)
			free_files((*arena)->files);
		free(*arena);
		arena = NULL;
	}
}
