#include <stdio.h>
#include <unistd.h>

int main() {
	
	if ((getuid() == 0))
		printf("[+] Access granted");
	else
		printf("[-] Access denied");
	return 0;

}
