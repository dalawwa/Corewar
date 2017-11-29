#include "corewar.h"

void	print_opts(t_arena *arena)
{
	int	i;

	i = 0;
	if (!arena || !arena->opts)
		return ;
	ft_printf("Opts:\nhas %d fds\nhas_d: %d | d: %d\nhas_s: %d | s: %d\nhas_v: %d | v: %d\n", arena->opts->fds_nb, arena->opts->has_d, arena->opts->d, arena->opts->has_s, arena->opts->s, arena->opts->has_v, arena->opts->v);
	ft_printf("Printing opts->fds\n");
	if (!arena->opts->fds)
		ft_printf("opts->fds = NULL\n");
	else
	{
		while (i < arena->opts->fds_nb)
		{
			ft_printf("%d\n", arena->opts->fds[i]);
			i++;
		}
	}
	ft_printf("EOF_print_opts\n");
}

void print_tab_cors(int *tab)
{
	int i;

	i = 0;
	ft_putendl("print_tab_cors");
	while (tab && tab[i] != -1)
	{
		ft_putnbr(tab[i]);
		i++;
		if (tab[i] != -1)
			ft_putstr(" - ");
	}
	ft_putendl("\nprint_tab_cors__END");
}

void		print_one_process(t_proc *process)
{
	ft_printf("Process num %d :\nPlayer : %s\nCarry = %d - pc = %d\n", process->process_num, process->player->name, process->carry, process->pc);
	print_regs(process);
}

void		print_all_process(t_arena *arena)
{
	int	i;
	t_proc	*elem;

	i = 0;
	elem = NULL;
	ft_putendl("__________print_all_PROCESS");
	if (arena && arena->list_proc)
	{
		elem = arena->list_proc->first;
		while (i++ < arena->list_proc->nb_proc)
		{
			print_one_process(elem);
			elem = elem->next;
		}
	}
	ft_putendl("__________print_all_PROCESS__END");
}

void		print_regs(t_proc *process)
{
	int	i;

	i = 1;
	while (i <= REG_NUMBER)
	{
		ft_printf("reg[%d] = %.2x%.2x", i, process->reg[i][0], process->reg[i][1]);
		i++;
		if (i <= REG_NUMBER)
			ft_putstr(" - ");
	}
	ft_putchar('\n');
}

void		print_bdd(t_arena *arena)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_putendl("__________print_BDD");
	if (arena)
	{
		while (i < 16)
		{
			ft_printf("\nNAME = %s\nOpcode = %.2x Meaning = %s Nb_cycle = %d Nb_args = %d has_ocp = %d Nb_ocp = %d\nOCPs:\n", arena->bdd[i]->name, arena->bdd[i]->opcode, arena->bdd[i]->meaning, arena->bdd[i]->nb_cycle, arena->bdd[i]->nb_args, arena->bdd[i]->has_ocp, arena->bdd[i]->nb_ocp);
			while (j < arena->bdd[i]->nb_ocp)
			{
				ft_printf("OCP Numero %d : ocp = %.2x size_adv = %d type_arg1 = %c - type_arg2 = %c - type_arg3 = %c\n", j + 1, arena->bdd[i]->ocp[j]->ocp, arena->bdd[i]->ocp[j]->size_adv, arena->bdd[i]->ocp[j]->type_arg1, arena->bdd[i]->ocp[j]->type_arg2, arena->bdd[i]->ocp[j]->type_arg3);
				j++;
			}
			j = 0;
			i++;
		}
	}
	ft_putendl("__________print_BDD__END");
}

void	print_arena_fds(t_arena *arena)
{
	int i;

	i = 0;
	ft_putendl("__________print_FDS");
	while (arena->fds && i < arena->nb_players)
	{
		ft_printf("%d", arena->fds[i++]);
		if (i < arena->nb_players)
			ft_printf(" - ");
		else
			ft_putchar('\n');
	}
	ft_putendl("__________print_FDS__END");
}

void	print_arena(t_arena *arena)
{
	ft_putendl("____________PRINT ARENA______________");
	if (arena)
	{
		print_bdd(arena);
		ft_putchar('\n');
		print_opts(arena);
//		print_arena_fds(arena);
		ft_putchar('\n');
		print_players(arena);
		ft_putchar('\n');
		print_mem(arena);
		ft_putchar('\n');
		print_all_process(arena);
		ft_putchar('\n');
//		print_arena_fds(arena);
	}
	else
		ft_putendl("ARENA = NULL");
	ft_putendl("____________PRINT ARENA______________END");
}

void print_usage(void)
{
	ft_putendl("print usage");
}
