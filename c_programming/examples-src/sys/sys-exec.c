#include <stdio.h>
#include <unistd.h>

void error_msg(const char *error)
{
	fprintf(stderr,"%s\n",error);
}
int main()
{
	//const char *pathname = "/usr/bin/echo";
	pid_t pid = fork();
	if (pid == 0)
	{
		printf("%d\n",getppid());
		const char *pathname = "/home/jarronracelis/a.out";
		if (execl(pathname, "a.out", "this", NULL) < 0)
			return -1;
		/*
		char *const arguments[] = {"echo", "-e", "\\033[33mHello World\nI am good", NULL};
		if (execv(pathname,arguments) < 0)
			return -1;
		*/
	}
	printf("%d\n",pid);
	printf("Hello world\n");
	return 0;
}
