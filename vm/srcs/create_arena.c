#include "corewar.h"

t_arena *create_arena(int ac, char **av)
{
	t_arena *arena;
	int     *fds;
	t_opt	*opts;

	if (!(opts = check_opts(ac, av)))
		return (NULL);
	if (!(arena = (t_arena *)malloc(sizeof(t_arena))))
		return (NULL);
	if (!(fds = get_fds(ac, av)))
	{
		//free_arena(arena);
			return (NULL);
	}
	// là t'as les fds pour create_champs();
	//     // ensuite on créée la mémoire dans arena et on load les champs dedans
    return (arena);

}
