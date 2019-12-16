#include "libft.h"

int	ft_abs(int val)
{
	if(val < 0)
		val *= -1;
	return val;
}