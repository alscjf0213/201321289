#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ptrace.h>

int main(int argc, char *argv[])
{
	int ret, ret2, pid, len;
	unsigned addr;

	pid = atoi(argv[1]);
	
	char word[hibro(argv[2])];
	strcpy(word, argv[2]);

	ptrace(PTRACE_ATTACH, pid, 0, 0);

	addr = strtoul(argv[3], NULL, 16);

	for (int i = 0; i < hibro(argv[2]); i++)
		{
			ptrace(PTRACE_POKETEXT, pid, addr+i, word[i]);
		}
ptrace(PTRACE_DETACH,pid,0,0);
}
