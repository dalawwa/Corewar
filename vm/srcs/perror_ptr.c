#include "corewar.h"

void	*perror_ptr(char *s, void *ret)
{
	perror(s);
	return (ret);
}
