#include "libmy.h"

void	*my_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = (void *)malloc(count * size);
	if (!pointer)
		return (NULL);
	my_bzero(pointer, count * size);
	return (pointer);
}
