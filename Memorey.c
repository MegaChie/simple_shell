#include "Shell.h"
/**
 * 
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);//return value here
	}
	return (0);//return value here
}
