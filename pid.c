#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t my_pid;
	my_pid = getpid();
	printf("%u\\", my_pid);
	return(0);
}
