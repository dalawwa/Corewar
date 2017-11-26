#include "corewar.h"

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
	ft_putendl("print_all_process");
	if (arena && arena->list_proc)
	{
		elem = arena->list_proc->first;
		while (i++ < arena->list_proc->nb_proc)
		{
			print_one_process(elem);
			elem = elem->next;
		}
	}
	ft_putendl("print_all_process__END");
}

void		print_regs(t_proc *process)
{
	int	i;

	i = 1;
	while (i < 17)
	{
		ft_printf("reg[%d] = %d - ", i, process->reg[i]);
		i++;
	}
	ft_putchar('\n');
}

void		print_bdd(t_arena *arena)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_putendl("print_bdd");
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
	ft_putendl("print_bdd__END");
}

void	print_arena_fds(t_arena *arena)
{
	int i;

	i = 0;
	ft_putendl("inside print_arena_fds");
	while (arena->fds && arena->fds[i] != -1)
		ft_printf("%d - ", arena->fds[i++]);
	ft_putchar('\n');
}

void	print_arena(t_arena *arena)
{
	if (!arena)
		return ;
	ft_putendl("Inside print_arena");
	print_arena_fds(arena);
}

void print_usage(void)
{
	ft_putendl("print usage");
}
