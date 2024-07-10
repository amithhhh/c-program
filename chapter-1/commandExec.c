#include <stdio.h>
#include <string.h>
#include <unistd.h> //pid_t is located here
#include <stdlib.h>
#include <sys/wait.h> //waitpid() is located here
#define MAXLINE 4096

int main(void) {
	char buffer[MAXLINE];
	pid_t pid;
	int status;
	printf("%%");

	while (fgets(buffer,MAXLINE,stdin) != NULL) {
		if (buffer[strlen(buffer) - 1] == '\n') {
			buffer[strlen(buffer) - 1] = 0; //execlp will not work with '\n' at the end
		}
		
		if ((pid = fork()) < 0) {
			printf("[-] Fork Error\n");
		}else if (pid == 0) {
			execlp(buffer,buffer,(char *)0);
			printf("[-] Execution Error\n");
			exit(127);
		}
		
		if ((pid = waitpid(pid,&status,0)) < 0) {
			printf("[-] Wait Error\n");
		}
		return 0;
	}
}

