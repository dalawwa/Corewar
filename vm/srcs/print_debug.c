#include "corewar.h"

void	print_opts(t_arena *arena)
{
	int	i;

	i = 0;
	ft_putendl("__________PRINT_OPTS");
	if (!arena || !arena->opts)
		return ;
	ft_printf("Opts:\nhas_d: %d | d: %d\nhas_s: %d | s: %d\nhas_v: %d | v: %d\nhas_a: %d | a_stealth: %d\nhas_b: %d | b_stealth: %d\n", arena->opts->has_d, arena->opts->d, arena->opts->has_s, arena->opts->s, arena->opts->has_v, arena->opts->v, arena->opts->has_a, arena->opts->a_stealth, arena->opts->has_b, arena->opts->b_stealth);
	ft_printf("EOF_PRINT_OPS_END_____\n\n");
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
	ft_putendl("__________print_ONE_PROCESS");
	ft_printf("Process num %d :\nPlayer : %s\nCarry = %d - pc = %d\n", process->process_num, process->player->name, process->carry, process->pc);
	print_regs(process);
	ft_putendl("__________print_ONE_PROCESS__END");
}

void		print_files(t_arena *arena)
{
	int	i;

	i = 0;
	ft_putendl("__________print_FILES");
	ft_printf("%d files to print\n", arena->nb_players);
	if (arena && arena->files)
	{
		while (i < arena->nb_players)
		{
			if (arena->files[i])
			{
				ft_printf("file %d : Name = %s - fd = %d\n", i + 1, arena->files[i]->name, arena->files[i]->fd);
				i++;
			}
		}
	}
	ft_putendl("__________print_FILES__END");
}

void		print_exe(t_exe *exe)
{
	ft_putendl("__________print_EXE");
	if (exe)
	{
		ft_printf("EXE from Process %d :\nOpcode = %.2x - OCP = %.2x\nBDD_op = %s\n", exe->process->process_num, exe->opcode, exe->ocp, exe->bdd_op->name);
		ft_printf("Arg1 : type = %c - ", exe->arg1->type);
		if (exe->arg1->type == 'r')
			ft_printf("value = %.2x - data = %.2x%.2x %.2x%.2x - d_value = %d - d_data = %d\n", exe->arg1->value[0], exe->arg1->data[0], exe->arg1->data[1], exe->arg1->data[2], exe->arg1->data[3], exe->arg1->d_value, exe->arg1->d_data);
		else if (exe->arg1->type == 'd' && exe->arg1->size == 2)
			ft_printf("value = %.2x%.2x - data = %.2x%.2x - d_value = %d - d_data = %d\n", exe->arg1->value[0], exe->arg1->value[1], exe->arg1->data[0], exe->arg1->data[1], exe->arg1->d_value, exe->arg1->d_data);
		else if (exe->arg1->type == 'd' && exe->arg1->size == 4)
			ft_printf("value = %.2x%.2x %.2x%.2x - data = %.2x%.2x %.2x%.2x - d_value = %d - d_data = %d\n", exe->arg1->value[0], exe->arg1->value[1], exe->arg1->value[2], exe->arg1->value[3], exe->arg1->data[0], exe->arg1->data[1], exe->arg1->data[2], exe->arg1->data[3], exe->arg1->d_value, exe->arg1->d_data);
		else if (exe->arg1->type == 'i')
			ft_printf("value = %.2x%.2x - data = %.2x%.2x %.2x%.2x - d_value = %d - d_data = %d\n", exe->arg1->value[0], exe->arg1->value[1], exe->arg1->data[0], exe->arg1->data[1], exe->arg1->data[2], exe->arg1->data[3], exe->arg1->d_value, exe->arg1->d_data);
		if (exe->arg2)
		{
			ft_printf("Arg2 : type = %c - ", exe->arg2->type);
			if (exe->arg2->type == 'r')
				ft_printf("value = %.2x - data = %.2x%.2x %.2x%.2x - d_value = %d - d_data = %d\n", exe->arg2->value[0], exe->arg2->data[0], exe->arg2->data[1], exe->arg2->data[2], exe->arg2->data[3], exe->arg2->d_value, exe->arg2->d_data);
			else if (exe->arg2->type == 'd' && exe->arg2->size == 2)
				ft_printf("value = %.2x%.2x - data = %.2x%.2x - d_value = %d - d_data = %d\n", exe->arg2->value[0], exe->arg2->value[1], exe->arg2->data[0], exe->arg2->data[1], exe->arg2->d_value, exe->arg2->d_data);
			else if (exe->arg2->type == 'd' && exe->arg2->size == 4)
				ft_printf("value = %.2x%.2x %.2x%.2x - data = %.2x%.2x %.2x%.2x - d_value = %d - d_data = %d\n", exe->arg2->value[0], exe->arg2->value[1], exe->arg2->value[2], exe->arg2->value[3], exe->arg2->data[0], exe->arg2->data[1], exe->arg2->data[2], exe->arg2->data[3], exe->arg2->d_value, exe->arg2->d_data);
			else if (exe->arg2->type == 'i')
				ft_printf("value = %.2x%.2x - data = %.2x%.2x %.2x%.2x - d_value = %d - d_data = %d\n", exe->arg2->value[0], exe->arg2->value[1], exe->arg2->data[0], exe->arg2->data[1], exe->arg2->data[2], exe->arg2->data[3], exe->arg2->d_value, exe->arg2->d_data);
			if (exe->arg3)
			{
				ft_printf("Arg3 : type = %c - ", exe->arg3->type);
				if (exe->arg3->type == 'r')
					ft_printf("value = %.2x - data = %.2x%.2x %.2x%.2x - d_value = %d - d_data = %d\n", exe->arg3->value[0], exe->arg3->data[0], exe->arg3->data[1], exe->arg3->data[2], exe->arg3->data[3], exe->arg3->d_value, exe->arg3->d_data);
				else if (exe->arg3->type == 'd' && exe->arg3->size == 2)
					ft_printf("value = %.2x%.2x - data = %.2x%.2x - d_value = %d - d_data = %d\n", exe->arg3->value[0], exe->arg3->value[1], exe->arg3->data[0], exe->arg3->data[1], exe->arg3->d_value, exe->arg3->d_data);
				else if (exe->arg3->type == 'd' && exe->arg3->size == 4)
				ft_printf("value = %.2x%.2x %.2x%.2x - data = %.2x%.2x %.2x%.2x - d_value = %d - d_data = %d\n", exe->arg3->value[0], exe->arg3->value[1], exe->arg3->value[2], exe->arg3->value[3], exe->arg3->data[0], exe->arg3->data[1], exe->arg3->data[2], exe->arg3->data[3], exe->arg3->d_value, exe->arg3->d_data);
				else if (exe->arg3->type == 'i')
				ft_printf("value = %.2x%.2x - data = %.2x%.2x %.2x%.2x - d_value = %d - d_data = %d\n", exe->arg3->value[0], exe->arg3->value[1], exe->arg3->data[0], exe->arg3->data[1], exe->arg3->data[2], exe->arg3->data[3], exe->arg3->d_value, exe->arg3->d_data);
			}
		}
	}
	ft_putendl("__________print_EXE__END");
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
		ft_printf("mn_proc = %d - Total proc = %d\n", arena->list_proc->nb_proc, arena->list_proc->total_proc);
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
		ft_printf("reg[%d] = %.2x%.2x %.2x%.2x", i, process->reg[i][0], process->reg[i][1], process->reg[i][2], process->reg[i][3]);
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
				ft_printf("OCP Numero %d : ocp = %.2x size_adv = %d type_arg1 = %c - type_arg2 = %c - type_arg3 = %c - Size_arg1 = %d - Size_arg2 = %d - Size_arg3 = %d\n", j + 1, arena->bdd[i]->ocp[j]->ocp, arena->bdd[i]->ocp[j]->size_adv, arena->bdd[i]->ocp[j]->type_arg1, arena->bdd[i]->ocp[j]->type_arg2, arena->bdd[i]->ocp[j]->type_arg3, arena->bdd[i]->ocp[j]->size_arg1, arena->bdd[i]->ocp[j]->size_arg2, arena->bdd[i]->ocp[j]->size_arg3);
				j++;
			}
			j = 0;
			i++;
		}
	}
	ft_putendl("__________print_BDD__END");
}

void	print_arena(t_arena *arena)
{
	ft_putendl("____________PRINT ARENA______________");
	if (arena)
	{
//		if (arena->opts)
//			print_opts(arena);
//		ft_putchar('\n');
//		if (arena->files)
//			print_files(arena);
//		ft_putchar('\n');
		if (arena->bdd)
			print_bdd(arena);
//		ft_putchar('\n');
//		print_mem(arena);
//		ft_putchar('\n');
		if (arena->list_proc)
			print_all_process(arena);
		ft_putchar('\n');
		if (arena->players)
			print_players(arena);
		//ft_putchar('\n');
		}
		else
			ft_putendl("ARENA = NULL");
		ft_putendl("____________PRINT ARENA______________END");	
}

void print_usage(void)
{
	ft_putendl("print usage");
}
