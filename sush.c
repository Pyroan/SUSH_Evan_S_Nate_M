/*****************************************
 *         SUSH: the Ship U Shell        *
 * Evan Schoenberger & Nathaniel Manning *
 *****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "tokenizer.h"

// Environment Variables
// We may have to change these to a Dictionary data structure
// http://stackoverflow.com/questions/4384359/quick-way-to-implement-dictionary-in-c
char *PS1;
char *PATH;
char *HOME;

// Maximum command length
const int COMMAND_BUFFER = 1023;

/****************************
 * INTERNAL COMMANDS FOLLOW *
 ****************************/

/**
 * Create or modify the value of the environment variable var, and
 * sets its current value to value.
 */
void setEnv() {

}

/**
 * Delete environment variable var from the environment.
 */
void unsetEnv() {

}

/**
 * Change directory to given directory.
 */
void cd() {

}

/**
 * Print working directory
 * @author Evan
 */
void pwd() {
   char* wd;
   wd = getcwd(wd, 1023);
	printf("%s", wd);
}

/**
 * Exit sush
 * @author Evan
 */ 
void exitSush() {
   printf("Bye!\n");
	exit(0);
}

/**************************************
 * MAIN() AND INPUT PROCESSING FOLLOW *
 **************************************/

/**
 * The main loop that executes the whole time.
 * I think it's mostly just a loop of waiting for input then executing it.
 * Returns true of a command was successfully found and executed
 */
bool readAndExecute(FILE* inputstream) {
   // Current command to be executed.
   char command[COMMAND_BUFFER];
   
   // Poll for and read input.
	printf("%s ", PS1);
	fgets(command, 1023, inputstream);
	
	if (command == NULL) return false;
	
	char** cmdtok = tokenize(command);
	// TODO execute tokenized command.
	
	return true;
}
 
/**
 * Initializer: try to find .sushrc,
 * Execute it if able.
 * Else (basically do nothing)
 */
void init() {
	// Set default environment variables.
	HOME = getcwd(HOME, 1023);
	PS1 = "$";
	
	FILE *sushrc;
	// Attempt to open the .sushrc file in the open directory
	sushrc = fopen(strcat(HOME, "/.sushrc"), "r");
	
	// This is an extremely ugly way to do this.
	if (sushrc != NULL) {
	   
	   // Run all commands found in .sushrc
	   int stillExecuting = true;
	   do {
	   	stillExecuting = readAndExecute(sushrc);
	   } while (stillExecuting);
		
		fclose(sushrc);
	}
	
}


/**
 * main
 */
int main(int argc, char **argv) {
	// Try to find and execute .sushrc
	init();
	// -- insert other initialization stuff --
	
	// Can move this loop to inside a mainloop if mainloop
	// ever does anything other than process commands.
	while (true) {
		readAndExecute(stdin);
	}
	return 0;
}
