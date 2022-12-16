#include "Shell.h"
/**
 * main - start here.
 * @ac: argument count
 * @av: argument vector
 * Return: whatever it returns shoeld be here
 */
int main(int ac, char **av)
{
	infoTable info[] = { infoStart };
	int fileDire = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fileDire)
		: "r" (fileDire));
	if (ac == 2)
	{
		fileDire = open(av[1], O_RDONLY);
		if (fileDire == -1)
		{
			if (errno == EACCES)
			{
				exit(126);
			}
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(bufFlush);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readFileDire = fileDire;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
