#include "corewar.h"

unsigned char	*find_body(t_file *file)
{
	unsigned char	*line;
	unsigned char	*body;
	int				i;
	int				red;

	i = 0;
	red = 140 + 4 + COMMENT_LENGTH;
	line = NULL;
	body = NULL;
	while (red < CHAMP_MAX_SIZE + 140 + 4 + COMMENT_LENGTH)
	{
		line = (unsigned char*)ft_strnew(1);
		if (line == NULL)
			return (perror_ptr("Error ", NULL));
		lseek(file->fd, red, SEEK_SET);
		read(file->fd, line, 1);
		body = add_that(body, line[0], i);
		red++;
		free(line);
		line = NULL;
		i++;
	}
	return (body);
}

char	*find_comment(t_file *file)
{
	char *line;

	line = ft_strnew(COMMENT_LENGTH);
	if (line == NULL)
		return (perror_ptr("Error ", NULL));
	lseek(file->fd, 140, SEEK_SET);
	read(file->fd, line, COMMENT_LENGTH);
	return (line);
}

char	*find_name(t_file *file)
{
	char	*line;

	line = ft_strnew(PROG_NAME_LENGTH);
	if (line == NULL)
		return (perror_ptr("Error ", NULL));
	lseek(file->fd, 4, SEEK_SET);
	read(file->fd, line, PROG_NAME_LENGTH);
	return (line);
}

int		check_size(t_file *file)
{
	int size;

	size = 0;
	size = lseek(file->fd, 0, SEEK_END);
	size = size - 140 - 4 - COMMENT_LENGTH;
	if (size < 0)
	{
		ft_printf("Error: File %s is too small to be a champion\n", file->name);
		return (0);
	}
	if (has_nb_magic(file) == 0)
		return (0);
	if (size > 682)
	{
		ft_printf("Error: File %s has too large code (%d bytes > 682 bytes)\n", file->name, size);
		return (0);
	}
	return (size);
}

t_play		*init_player(int i)
{
	t_play *player;

	player = (t_play*)malloc(sizeof(t_play));
	if (player == NULL)
		return (perror_ptr("Error ", NULL));
	player->play_num = i + 1;
	player->play_live_num[0] = (unsigned char)(255);
	player->play_live_num[1] = (unsigned char)(255);
	player->play_live_num[2] = (unsigned char)(255);
	player->play_live_num[3] = (unsigned char)(255 - i);
	player->idx_start = 0;
	player->size = 0;
	player->last_live = 0;
	player->name = NULL;
	player->comment = NULL;
	player->body = NULL;
	player->body_len = -1;
	return (player);
}

t_play		*create_a_player(int i, t_file *file)
{
	t_play	*player;
	int		size;

	size = check_size(file);
	if (size == 0)
		return (NULL);
	player = init_player(i);
	if (player == NULL)
		return (NULL);
	player->size = size;
	player->name = find_name(file);
	if (player->name == NULL)
		return (NULL);
	player->comment = find_comment(file);
	if (player->comment == NULL)
		return (NULL);
	player->body = find_body(file);
	if (player->body == NULL)
		return (NULL);
	player->body = clean_body(player->body, &player);
	if (player->body == NULL)
		return (NULL);
	return (player);
}

int		create_players(t_arena *arena)
{
	int		i;

	i = 0;
	arena->players = (t_play **)malloc(sizeof(t_play *) * arena->nb_players);
	if (arena->players == NULL)
		return (perror_int("Error ", 0));
	while (i < arena->nb_players)
	{
		if ((arena->players[i] = create_a_player(i, arena->files[i])) == NULL)
			return (0);
		i++;
	}
	i = 0;
	while (i < arena->nb_players)
	{
		arena->players[i]->idx_start = MEM_SIZE / arena->nb_players * i;
		i++;
	}
	return (1);
}
