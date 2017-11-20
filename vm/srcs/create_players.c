#include "corewar.h"

int		has_nb_magic(char *cor)
{
	char	*magic;
	int		i;
	int		j;
	int		ret;

	j = 0;
	i = 1;
	ret = 1;
	magic = ft_strnew(4);
	if (magic == NULL || (int)ft_strlen(cor) < 4 || cor[0] != '0')
	{
		ft_putendl("Error : something wrong with magic");
		free(magic);
		return (-1);
	}
	while (i < 5)
	{
		magic[i - 1] = cor[i + j];
		i++;
		if (cor[i] == ' ')
			j++;
	}
	if (ft_atoi(magic) == COREWAR_EXEC_MAGIC)
	{
		ft_putendl("Error : something wrong with magic");
		ret = 0;
	}
	free(magic);
	magic = NULL;
	return (ret);
}

char	*find_name(char *cor)
{
	int		i;
	int		j;
	int		len;
	char	*name;

	i = PROG_NAME_LENGTH + 2;
	j = 0;
	len = 0;
	name = NULL;
	if ((int)ft_strlen(cor) < i + 1)
	{
		ft_putendl("Error : Name not well formated");
		return (NULL);
	}
	while (cor[i] == '0' && cor[i + 1] == '0' && i > 3)
		i--;
	len = PROG_NAME_LENGTH - i;
	name = malloc(sizeof(char) * len);
	if (name == NULL)
		return (NULL);
	while (j < len)
	{
		name[j] = cor[i];
		i++;
		j++;
	}
	name[j] = '\0';
	return (name);
}

char	*extract_cor(int fd)
{
	char	*line;
	char	*cor;

	cor = NULL;
	line = NULL;
	ft_printf("debug extract_cor\n");
	while (get_next_line(fd, &line) != 0)
	{
		ft_printf("line = _%s_\n", line);
		cor = ft_strjoin_leakless(cor, line);
		cor = ft_stradd_c_end(cor, '\n');
	}
	if (line)
		free(line);
	ft_printf("COR =\n%s__END\n", cor);
	return (cor);
}

int		create_a_player(int fd, t_play *player)
{
	char *cor;

	cor = extract_cor(fd);
	if (has_nb_magic(cor) != 1)
		return (0);
	player->name = find_name(cor);
	if (player->name == NULL)
		return (0);
	return (1);
}

t_play		*create_players(int *tab, int nb_cor)
{
	t_play	*players;
	int		i;

	i = 0;
	players = malloc(sizeof(t_play) * nb_cor);
	if (players == NULL)
		return (NULL);
	while (i < nb_cor)
	{
		create_a_player(tab[i], &players[i]);
		i++;
	}
	return (players);
}
