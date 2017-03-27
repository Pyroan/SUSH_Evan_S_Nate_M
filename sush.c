/*****************************************
 *         SUSH: the Ship U Shell        *
 * Evan Schoenberger & Nathaniel Manning *
 *****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tokenizer.h"
 
// Environment Variables
char *PS1 = "$";
char *PATH;
char *HOME;


/**
 * Initializer: try to find .sushrc,
 * Execute it if able.
 * Else (basically do nothing)
 */
void init() {
	
}

/**
 * The main loop that executes the whole time.
 * TODO figure out the structure.
 * I think it's mostly just a loop of waiting for input then executing it.
 */
void mainLoop() {
	while (true) {
		printf("%s ", PS1);
	}
}

int main(int argc, char **argv) {
	// Try to find and execute .sushrc
	init();
	// -- insert other itialization stuff --
	mainLoop();
	return 0;
}
