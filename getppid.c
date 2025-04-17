#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Siempre 0.
 */
int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("PID: %u\n", my_pid);
    my_pid = getppid();
    printf("PPID: %u\n", my_pid);
    return (0);
}
