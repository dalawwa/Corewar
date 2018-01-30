/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:08:07 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/30 09:49:05 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		write_on_terminal(int co, t_champ *champ, char **opti, int j)
{
	if (co == 1 || co == 9 || co == 12)
	{
		ft_printf("\n%20c%-10i", ' ', co);
		find_translat_a(champ, opti, co);
		ft_printf("\n\n");
	}
	else
	{
		j = get_opcode_a(opti, co);
		ft_printf("\n%20c%-4i%-6i", ' ', co, j);
		find_translat_a(champ, opti, co);
		ft_printf("\n\n");
	}
}

void		start_writing_prog(t_header *op)
{
	ft_printf("Dumping annotated program on standard output\n");
	ft_printf("Program size : %i bytes\n", g_position);
	ft_printf("Name : \"%s\"\nComment : \"%s\"\n\n",
			op->prog_name, op->comment);
	g_position = 0;
}

int			write_beg_line(char **opti, int j, t_champ *champ, int co)
{
	ft_printf("%-5i(%-3i) : %7c%-10s", g_position, g_temp, ' ', opti[0]);
	j = 1;
	while (opti[j] != NULL)
	{
		ft_printf("%-18s", opti[j]);
		j++;
	}
	write_on_terminal(co, champ, opti, j);
	g_position += g_temp;
	return (j);
}

void		check_if_print_label(t_champ *test)
{
	while (test->next != NULL && test->position >= g_position)
	{
		if (test->position == g_position)
			ft_printf("%-11i:%4c%s:\n", g_position, ' ', test->label);
		test = test->next;
	}
}

void		l_writing_out(char *file, t_champ *champ, t_header *op, int i)
{
	char	**tab;
	int		j;
	int		co;
	char	**opti;
	t_champ	*test;

	start_writing_prog(op);
	tab = ft_strsplit(file, '\n');
	while (tab[i] != NULL)
	{
		test = champ;
		check_if_print_label(test);
		tab[i] = delete_comments(tab[i]);
		j = 0;
		while (tab[i][j] == ' ' || tab[i][j] == '\t')
			j++;
		co = get_the_op_code(&tab[i][j]);
		temp_advance(co);
		opti = ft_strsplit(tab[i], ' ');
		j = write_beg_line(opti, j, champ, co);
		i++;
		if (opti)
			free(opti);
	}
}
