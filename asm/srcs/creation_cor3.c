/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_cor3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:00:55 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/26 18:04:07 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*name_dot_cor(char *str)
{
	char	*name;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	name = ft_strnew(j + 3);
	while (i < j - 1)
	{
		name[i] = str[i];
		i++;
	}
	name[i] = 'c';
	i++;
	name[i] = 'o';
	i++;
	name[i] = 'r';
	i++;
	name[i] = '\0';
	return (name);
}

char		*after_command(char *str, int i)
{
	if (i == 1 || i == 9 || i == 12 || i == 14)
		str = str + 4;
	else if (i == 2 || i == 3 || i == 7)
		str = str + 2;
	else if (i == 15)
		str = str + 5;
	else
		str = str + 3;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

int			next_order(char *str, int j)
{
	while (str[j] != ',')
		j++;
	j++;
	while (str[j] == '\t' || str[j] == ' ')
		j++;
	return (j);
}

void		opcod_number(char *str, int *o, int i, int c)
{
	if (str[i] == 'r' && c == 1)
		*o = 0x40;
	else if (str[i] == '%' && c == 1)
		*o = 0x80;
	else if (c == 1)
		*o = 0xC0;
	if (str[i] == 'r' && c == 2)
		*o = 0x10;
	else if (str[i] == '%' && c == 2)
		*o = 0x20;
	else if (c == 2)
		*o = 0x30;
	if (str[i] == 'r' && c == 3)
		*o = 0x4;
	else if (str[i] == '%' && c == 3)
		*o = 0x8;
	else if (c == 3)
		*o = 0xC;
}
