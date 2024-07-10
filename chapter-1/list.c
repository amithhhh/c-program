#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	DIR *dp;	//variable used to store directory address
	struct dirent *dirp;
	if (argc < 3) {
		printf("usage: ./list ls <folder name> \n");
		exit(1);
	}
	if ((dp = opendir(argv[2])) == NULL) {		//opendir: used to open directory
		printf("can't open the folder: %s",argv[2]);
		exit(1);
	}
	while ((dirp = readdir(dp)) != NULL) {		//readdir:	used to read all the details in that directory. all the details is stored in dirp.
		printf("%s\n",dirp->d_name);
	}
	return 0;
}
