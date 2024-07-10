#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	int fd = open("dup.txt",O_WRONLY | O_CREAT | O_TRUNC,0644);
	int new_fd;

	if (fd == -1) {
		fprintf(stderr,"Opening Error\n");
		exit(1);
	}
	if ((new_fd = dup(fd)) < 0){
		perror("dup");
		exit(1);
	}
	dprintf(fd,"original");
	dprintf(new_fd,"duplicate");
	return 0;
}
