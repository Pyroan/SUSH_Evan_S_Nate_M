#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/****************************************
 * A separate test of the init function *
 ****************************************/
 // Successfully finds .sushrc :D

char *HOME;

/**
 * Initializer: try to find .sushrc,
 * Execute it if able.
 * Else (basically do nothing)
 */
void init() {
	// Set default environment variables.
	HOME = getcwd(HOME, 1023);
	printf("Home: %s\n", HOME);
	FILE *sushrc;
	sushrc = fopen(strcat(HOME, "/.sushrc"), "r");
	// TODO Rm this random debugging crap.
	if (sushrc != NULL)
		printf("HOLY CRAP WE ACTUALLY FOUND .sushrc!\n");
	
	
}

/**
 * main
 */
int main(int argc, char **argv) {
	// Try to find and execute .sushrc
	init();
	// -- insert other initialization stuff --
	return 0;
}
