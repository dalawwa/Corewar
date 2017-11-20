#include "corewar.h"

void	free_opts(t_opt **opts)
{
	free(*opts);
}

void	free_fds(int **fds)
{
	free(*fds);
}

void	free_arena(t_arena **arena)
{
	if (!arena || !*arena)
		return ;
	if ((*arena)->opts)
		free_opts(&(*arena)->opts);
	if ((*arena)->fds)
		free_fds(&(*arena)->fds);
	free(*arena);
}
