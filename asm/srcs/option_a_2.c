/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_a_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:38:55 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/26 18:47:07 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*delete_comments(char *str)
{
	char	*ret;
	int		i;

	temp = 0;
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
	i = 0;
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

int			put_in_file_reg_a(char *str)
{
	int	j;

	j = 0;
	if (str[0] != 'r')
		return (0);
	j = ft_atoi(&str[1]);
	ft_printf("%-18i", j);
	return (1);
}

int			put_in_file_indir_a(t_champ *champ, char *str)
{
	int	j;

	j = 0;
	if (str[1] == ':')
		j = position_label(champ, str);
	else
		j = ft_atoi(&str[1]);
	ft_printf("%-18i", j);
	return (1);
}
