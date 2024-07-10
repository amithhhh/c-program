#include <stdio.h>
#include <unistd.h>

int main() {

	printf("uid: %d\n gid: %d\n",getuid(),getgid());
	return 0;
}