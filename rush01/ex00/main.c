#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	void *ptr = malloc(1000000 * 4);
	if (ptr == NULL)
		write(1, "ERROR", 5);
	return (0);
}
