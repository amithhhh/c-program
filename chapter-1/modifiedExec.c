#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAXLINE 4096

static void sig_int(int);

int main() {

	pid_t pid;
	int status;
	char buffer[MAXLINE];
	bool choice = true;

	if (signal(SIGINT,sig_int) == SIG_ERR)
		printf("[-] Signal Error\n");

	while (choice) {
		printf("%% ");

		while ((fgets(buffer,MAXLINE,stdin)) != NULL) {
			if (buffer[strlen(buffer) - 1] == '\n') {
				buffer[strlen(buffer) - 1] = 0;
			}
			if ((pid = fork()) < 0) {
				printf("[-] Fork Error\n");
				exit(1);
			}else if (pid == 0) {
				execlp(buffer,buffer,(char *)0);
				printf("[-] Execution Error\n");
				exit(127);
			}

			if ((pid = waitpid(pid,&status,0)) < 0) {
				printf("[-] Waitpid Error\n");
			}
			
		}
	}
	return 0;
}

static void sig_int(int sig_no) {
	printf("%% Interupted\n");
}
