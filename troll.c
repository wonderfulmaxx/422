#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void trol()
{
	write(STDOUT_FILENO, "I won't to be kill :(\n",23);
}

int main()
{
	signal(SIGINT, trol);
	signal(SIGTERM, trol);
	signal(SIGKILL, trol);
	while (1)
	{
		write(1,"Please love me <3\n",18);
		sleep(2);
	}
	return(0);
}