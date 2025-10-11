#include <stdio.h>
#include <signal.h>

void user_defined_signal(int sig, siginfo_t *info, void *ucontex)
{
	printf("\nSignal used SIGINT %d ---> PID %d\n", sig, info->si_pid);
}

void setSigaction(struct sigaction* sig_function)
{
	/* user_defined_signal->sa_handler 
	-> Use this when not setting sa_flag to SA_SIGINFO 
	-> user_defined_signal->sa_flags = 0;
	*/
	sig_function->sa_sigaction = user_defined_signal;
	sig_function->sa_flags = SA_SIGINFO;
}

int main()
{
	/* Returns 0 on sucess
	 * Returns -1 on error 
	 * signum is type of signal
	 * for instance SIGINT
	 * is Crtl + C           
	 * see man 7 signal
	 * */
	char kill;

	struct sigaction user_defined_action;
	setSigaction(&user_defined_action);

	if (sigaction(SIGINT, &user_defined_action, NULL) < 0)
	{
		fprintf(stderr, "Could not properly perform signal action\n");
		return -1;
	}

	while (kill != 'k')
	{
		printf("Enter character: ");
		scanf("%c", &kill);
	}

	return 0;
}
