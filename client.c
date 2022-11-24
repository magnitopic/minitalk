#include "server.h"

int	main(void)
{
	kill(pid, SIGUSR1);
	return (0);
}