#include "corewar.h"

int		a_hexa_to_i(unsigned char *s, int len)
{
	// transformer un char *s en decimal a revoir je pense.a tester
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (i < len)
	{
		result += s[i] << (8 * (len - i - 1));
		i++;
	}
	return (result);
}
