#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	if (argc < 2) {
		fprintf(stderr,"Usage %s <filename>\n",argv[0]);
		exit(1);
	}

	int f;
	f = creat(argv[1],O_CREAT);

	if (f == -1) {
		printf("creation error\n");
		exit(1);
	}else	printf("Success\n");

	return 0;
}
