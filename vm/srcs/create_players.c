#include "corewar.h"
/*
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
}*/
char	*find_body(int fd)
{
	char *line;

	line = ft_strnew(CHAMP_MAX_SIZE);
	lseek(fd, 2192, SEEK_SET);
	read(fd, line, CHAMP_MAX_SIZE);
	ft_printf("BODY =_%s_\n", line);
	return (line);
}

char	*find_comment(int fd)
{
	char *line;

	line = ft_strnew(COMMENT_LENGTH);
	lseek(fd, 140, SEEK_SET);
	read(fd, line, COMMENT_LENGTH);
	ft_printf("COMMENT =_%s_\n", line);
	return (line);
}

char	*find_name(int fd)
{
	char	*line;

	line = ft_strnew(PROG_NAME_LENGTH);
	lseek(fd, 4, SEEK_SET);
	read(fd, line, PROG_NAME_LENGTH);
	ft_printf("NAME =_%s_\n", line);
	return (line);
}

int		create_a_player(int fd, t_play *player)
{
	player->name = find_name(fd);
	if (player->name == NULL)
		return (0);
	player->comment = find_comment(fd);
	if (player->comment == NULL)
		return (0);
	player->body = find_body(fd);
	if (player->body == NULL)
		return (0);
//	if (has_nb_magic(cor) != 1)
//		return (0);
	return (1);
}

t_play		*create_players(t_arena *arena)
{
	t_play	*players;
	int		i;

	i = 0;
	ft_printf("Let's create %d Player(s) !\n", arena->nb_players);
	players = malloc(sizeof(t_play) * arena->nb_players);
	if (players == NULL)
		return (NULL);
	while (i < arena->nb_players)
	{
		create_a_player(arena->fds[arena->nb_players - 1 - i], &players[i]);
		i++;
	}
	return (players);
}
