#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

void afficher(char *s)
{
	write(2, s, ft_strlen(s));
}

void exit_afficher(char *s)
{
	afficher(s);
	exit(1);
}

int main(int argc, char **argv, char **env)
{
	int pfd[2];
	int pid;
	int pip = 0;
	int lastfd = -1;
	int nbarg = 0;

	if (argc == 1)
		return 1;

	for (int word_counter = 1; word_counter <= argc; word_counter++, pip = 0)
	{
		if (argv[word_counter] && strcmp(argv[word_counter], "|") && strcmp(argv[word_counter], ";"))
			nbarg++;
		else if (nbarg)
		{
			if (argv[word_counter])
				pip = (strcmp(argv[word_counter], "|") == 0 ? 1 : 0);
			argv[word_counter] = NULL;
			if (!strcmp(argv[word_counter - nbarg], "cd"))
			{
				if (nbarg == 2)
				{
					if ((chdir(argv[word_counter - nbarg + 1]) == -1))
					{
						afficher("error: cd: cannot change directory to ");
						afficher(argv[word_counter - nbarg + 1]);
						afficher("\n");
					}
				}
				else
					afficher("error: cd: bad arguments\n");
			}
			else
			{
				if ((pip && (pipe(pfd) == -1)) || (pid = fork()) == -1)
					exit_afficher("error: fatal\n");
				if (!pid)
				{
					if ((lastfd != -1 && (dup2(lastfd, 0) == -1)) || (pip && (dup2(pfd[1], 1) == -1)))
						exit_afficher("error: fatal\n");
					if (execve(argv[word_counter - nbarg], &argv[word_counter - nbarg], env) == -1)
					{
						afficher("error: cannot execute ");
						afficher(argv[word_counter - nbarg]);
						exit_afficher("\n");
					}
				}
				else
				{
					waitpid(-1, 0, 0);
					close(pfd[1]);
					if (lastfd != -1)
						close(lastfd);
					lastfd = (pip != 0) ? pfd[0] : -1;
				}
			}
			nbarg = 0;
		}
	}
}