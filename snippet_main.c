//Code snippet from the TA site, posting in case he takes it down again.

// Use POSIX/UNIX conforming sources.
// http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_02_01_01
#define _XOPEN_SOURCE 700

//#include <sys/types.h> /* pid_t */ // not needed if _XOPEN_SOURCE defined to 700
#include <unistd.h> /* fork(), execv() */
#include <sys/wait.h> /* waitpid() */
#include <stdio.h> /* printf() */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stddef.h> /* NULL */

/* compile cmd: 'gcc -o prog main.c' */

int main()
{
	pid_t child;
	int rtn;
	const char *cmd = "/bin/sleep";
	const char *args0 = "/bin/sleep";
	const char *args1 = "60";
	const char * const args[] = {args0, args1, (char *)NULL};

	child = fork();
	if (child == 0) {
		/* executed by child process */

		/*
		 * The below cast (char **) quiets the compiler's warning. Casting here
		 * is ok, the function declaration does not specify two levels of const
		 * due to legacy code compatibility.
		 *
		 * http://pubs.opengroup.org/onlinepubs/9699919799/functions/exec.html#tag_16_111_08
		 *
		 * This is just a sample, but the value of 'rtn' will likely be useful
		 * in your full program implementation!
		 *
		 */
		rtn = execv(cmd, (char **)args);

		/* execv should not return on success */
		printf("execv returned value %d", rtn);
	} else {
		/* executed by parent process */
		pid_t child_finished;

		/* The following waitpid() call will return immediately */
		/* child_finished = waitpid(-1, (int *)NULL, WNOHANG); */

		/*
		 * The following waitpid() call will return 60 seconds later (i.e.,
		 * blocks until 'sleep 60' finishes)
		 */
		child_finished = waitpid(-1, (int *)NULL, 0);

		printf("pid %d completed", child_finished);
	}

	return EXIT_SUCCESS;
}
