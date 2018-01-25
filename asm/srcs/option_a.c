/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:08:07 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/24 17:44:42 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*delete_comments(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t' || str[i] == ',')
			str[i] = ' ';
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ';' || str[i] == '#')
		{
			ret = ft_memalloc(i + 1);
			ret[i + 1] = '\0';
			while (i--)
				ret[i] = str[i];
			return (ret);
		}
		i++;
	}
	return (str);
}

int			next_order_space(char *str, int j)
{
	while (str[j] != ' ')
		j++;
	while (str[j] == '\t' || str[j] == ' ')
		j++;
	return (j);
}

int			get_opcode_a(char **str, int i)
{
	int		o;
	int		m;
	int		param;

	if (i == 11 || i == 4 || i == 8 || i == 5 || i == 6 || i == 10 || i == 7)
		param = 3;
	else
		param = 2;
	m = 0;
	o = 0;
	i=0;
	opcod_number(str[1], &o, i, 1);
	m = o;
	if (param > 1)
	{
		opcod_number(str[2], &o, i, 2);
		m = m + o;
	}
	if (param > 2)
	{
		opcod_number(str[3], &o, i, 3);
		m = m + o;
	}
	return (m);
}

int		put_in_file_reg_a(char *str)
{
	int	j;

	j = 0;
	if (str[0] != 'r')
		return (0);
	j = ft_atoi(&str[1]);
	ft_printf("%-18i", j);
	return (1);
}

int		put_in_file_indir_a(t_champ *champ, char *str)
{
	int	j;

	j = 0;
	if (str[1] == ':')
		j = position_label(champ, str);
	else
		j = ft_atoi(&str[1]);
	ft_putchar('c');
	ft_printf("%-18i", j);
	return (1);
}

int		put_in_file_dir_a(int i, t_champ *champ, char *str)
{
	int	j;

	j = 0;
	i = 0;
	if (*str != '%')
		return (0);
	(str)++;
	if (str && *str == ':' && (str)++)
		j = position_label(champ, str);
	else
		j = ft_atoi(str);
	ft_printf("%-18i", j);
	return (1);
}


int			find_translat_a2(t_champ *champ, char **str, int i)
{
	if (i == 9 || i == 12 || i == 15)
		return (put_in_file_dir_a(2, champ, str[1]));
	else if ((i == 10 || i == 14) && (((put_in_file_reg_a(str[1])
						|| put_in_file_dir_a(2, champ, str[1])
						|| put_in_file_indir_a(champ, str[1]))
					&& (put_in_file_reg_a(str[2])
						|| put_in_file_dir_a(2, champ, str[2])))))
		return (put_in_file_reg_a(str[3]));
	else if (i == 11 && ((put_in_file_reg_a(str[1]) && (put_in_file_reg_a(str[2])
						|| put_in_file_dir_a(2, champ, str[2])
						|| put_in_file_indir_a(champ, str[2]))
					&& (put_in_file_reg_a(str[3])
						|| put_in_file_dir_a(2, champ, str[3])))))
		return (1);
	else if (i == 16)
		return (put_in_file_reg_a(str[1]));
	return (1);
}

int			find_translat_a(t_champ *champ, char **str, int i)
{
	if (i == 1)
		return (put_in_file_dir_a(4, champ, str[1]));
	else if ((i == 2 || i == 13)
			&& ((put_in_file_dir_a(4, champ, str[1]) || put_in_file_indir_a(champ, str[1])))
			&& (put_in_file_reg_a(str[2])))
		return (1);
	else if ((i == 3
				&& put_in_file_reg_a(str[1])
				&& (put_in_file_reg_a(str[2])
					|| put_in_file_indir_a(champ, str[2]))))
		return (1);
	else if ((i == 4 || i == 5)
			&& put_in_file_reg_a(str[1]) && put_in_file_reg_a(str[2])
			&& put_in_file_reg_a(str[3]))
		return (1);
	else if ((i == 6 || i == 7 || i == 8) && ((put_in_file_reg_a(str[1]) || put_in_file_dir_a(4, champ, str[1])
					|| put_in_file_indir_a(champ, str[1]))
				&& (put_in_file_reg_a(str[2])
					|| put_in_file_dir_a(4, champ, str[2])
					|| put_in_file_indir_a(champ, str[2]))))
		return (put_in_file_reg_a(str[3]));
	return (find_translat_a2(champ, str, i));
}

void		launch_writing_out(char *file, t_champ *champ, header_t *op)
{
	char	**tab;
	int		i;
	int		j;
	int		co;
	char	**opti;
	t_champ	*test;

	i = 0;
	ft_printf("Dumping annotated program on standard output\n");
	ft_printf("Program size : %i bytes\n", position);
	ft_printf("Name : \"%s\"\nComment : \"%s\"\n\n", op->prog_name, op->comment);
	position = 0;
	tab = ft_strsplit(file, '\n');
	while (tab[i] != NULL)
	{
		tab[i] = delete_comments(tab[i]);
		j = 0;
		while (tab[i][j] == ' ' || tab[i][j] == '\t')
			j++;
		co = get_the_op_code(&tab[i][j]);
		if (co == 1 || co == 4 || co == 3 || co == 5 || co == 7)
			temp +=4;
		if (co == 2 || co == 11)
			temp += 6;
		if (co == 8 || co == 6)
			temp += 7;
		if (co == 9 || co == 12)
			temp += 2;
		if (co == 10)
			temp += 5;
		if (co)
			temp++;
		opti = ft_strsplit(tab[i], ' ');
		ft_printf("%-5i(%-3i) : %7c%-10s", position, temp, ' ', opti[0]);
		j = 1;
		while (opti[j] != NULL)
		{
			ft_printf("%-18s", opti[j]);
			j++;
		}
		if (co == 1 || co == 9 || co == 12)
		{
			ft_printf("\n%20c%-10i", ' ', co);
			find_translat_a(champ, opti, co);
			ft_printf("\n\n");
//			ft_printf("\n%20c%-4i\n\n", ' ', co);
		}
		else
		{
			j = get_opcode_a(opti, co);
			ft_printf("\n%20c%-4i%-6i", ' ', co, j);
			find_translat_a(champ, opti, co);
			ft_printf("\n\n");
//			ft_printf("\n%20c%-4i%-6i\n\n", ' ', co, j);
		}
		position +=  temp;
		test = champ;
		while (test->next != NULL && test->position >= position)
		{
			if (test->position == position)
				ft_printf("%-11i:%4c%s:\n", position, ' ', test->label);
			test = test->next;
		}
		temp = 0;
		i++;
		if (opti)
			free(opti);
	}
}
