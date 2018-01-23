/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:08:07 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/23 20:05:23 by bfruchar         ###   ########.fr       */
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
	{
		j++;
//		ft_putnbr(j);
	}
//	ft_putchar(' ');
//	j++;
	while (str[j] == '\t' || str[j] == ' ')
		j++;
	return (j);
}

int			get_opcode_a(char **str, int i)
{
	int		o;
	int		m;
	int		param;

	if (i == 11 || i == 4 || i == 8)
		param = 3;
	else
		param = 2;
	m = 0;
	o = 0;
	i=0;
//	i = next_order_space(str, i);
	opcod_number(str[1], &o, i, 1);
	m = o;
	if (param > 1)
	{
	//	i = next_order_space(str, i);
		opcod_number(str[2], &o, i, 2);
		m = m + o;
	}
	if (param > 2)
	{
	//	i = next_order_space(str, i);
		opcod_number(str[3], &o, i, 3);
		m = m + o;
	}
	temp++;
	return (m);
}

void		launch_writing_out(char *file, t_champ *champ, header_t *op, char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		co;
	char	**opti;

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
			ft_printf("\n%20c%-4i\n\n", ' ', co);
		}
		else
		{
			j = get_opcode_a(opti, co);
			ft_printf("\n%20c%-4i%-6i", ' ', co, j);
			ft_printf("\n%20c%-4i%-6i\n\n", ' ', co, j);
		}
		position +=  temp;
		temp = 0;
		i++;
		if (opti)
			free(opti);
	}
	//	tab = ft_strsplit(file, '\n');
	//	while (tab[i] != NULL)
	//	{
	//		tab[i] = delete_comments(tab[i]);
	//		ft_printf("%-5i(%-3i) : %s\n", position, position, tab[i]);
	//		ft_printf("%20c\n%20c\n", ' ', ' ');
	//		i++;
	//	}
	while (champ->next != NULL)
	{
		ft_printf("%s\n%i\n\n", champ->label, champ->position);
		champ = champ->next;
	}
	ft_printf("%s\n%i\n\n", champ->label, champ->position);
	ft_putchar('\n');
	ft_putstr(str);
}
