/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:45:13 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/25 13:20:20 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			char_label(char c)
{
	if ((c >= 97 && c <= 122) || c == 95 || (c >= 48 && c <= 57))
		return (1);
	return (0);
}

int			line_is_valid(char *str)
{
	int		op;

	op = get_the_op_code(str);
	if (op == 0)
		return (0);
	if (op)
		position++;
	if (op == 1 || op == 9 || op == 12 || op == 14)
		str = str + 4;
	else if (op == 2 || op == 3 || op == 7)
		str = str + 2;
	else if (op == 15)
		str = str + 5;
	else
		str = str + 3;
	if (op != 1 && op != 9 && op != 12 && op != 15)
		position++;
	check_args_valid(&str, op);
	return (1);
}

char		*ft_strjoin_without_empty(char *file, char *line, int j)
{
	char	*tmp;

	tmp = NULL;
	while (line[j] == '\t' || line[j] == ' ')
		j++;
	if (line[j] && line[j] != '#' && line[j] != ';' && line_is_valid(&line[j]))
	{
		tmp = ft_strjoin_leakless(file, &line[j]);
		tmp = ft_strjoin_leakless(tmp, "\n");
	}
	else
		return (file);
	return (tmp);
}

int			label_or_not(char *line)
{
	int		j;

	j = 0;
	while (line[j] == '\t' || line[j] == ' ')
		j++;
	while (line[j] && char_label(line[j]) == 1)
		j++;
	if (j > 0 && line[j] == ':')
	{
		j++;
		while (line[j] == ' ' || line[j] == '\t')
			j++;
		if (line[j] == '\n' || line[j] == '\0' || line[j] == '#')
			return (1);
		return (1);
	}
	else if (line[j] && line[j] != ' ' && line[j] != '\0' && line[j] != ';'
			&& line[j] != '\n' && line[j] != '\t' && char_label(line[j]) == 1
			&& line[j] != ',')
		ciao_bye_bye(1);
	return (0);
}

t_champ		*get_champ_data(char **file, int fd, int i)
{
	char	*line;
	t_champ	*new;

	line = NULL;
	new = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] && line[i] != '#' && line[i] != ';'
				&& label_or_not(line) == 1)
		{
			new = ft_lstadd_lines(new, line, i);
			while (line[i] != ':')
				i++;
			i++;
		}
		*file = ft_strjoin_without_empty(*file, line, i);
		size_line++;
		i = 0;
		if (line)
			free(line);
	}
	if (line)
		free(line);
	return (new);
}
