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
// Or some other kind of data structure. Some kind of associative array.
// http://stackoverflow.com/questions/4384359/quick-way-to-implement-dictionary-in-c
char *PS1;
char *PATH;
char *HOME;
char *CWD;

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
 * @author Evan
 * TODO Handle chdir error codes.
 */
void cd(char* newPath) {
   CWD = strcat(CWD, newPath);
   chdir(CWD);
}

/**
 * Print working directory
 * @author Evan
 */
void pwd() {
	printf("%s \n", CWD);
}

/**
 * Exit sush
 * @author Evan
 */ 
void exitSush() {
   printf("Bye!\n");
	exit(0);
}

/**
 * Added mostly for debugging
 * @author Evan
 */
void echo(char* message) {
	printf("%s\n", message);
}

/**************************************
 * MAIN() AND INPUT PROCESSING FOLLOW *
 **************************************/

/**
 * The main loop that executes the whole time.
 * I think it's mostly just a loop of waiting for input then executing it.
 * Returns true of a command was successfully found and executed
 */
bool readAndExecute(char* command) {
	
	if (command == NULL) return false;
	
	tokenize(command);
	
	// Parse and Execute Commands
	
	// ATM I can't/don't want to figure out a better way to do this.
	if (strcmp(commandTokens[0], "exit") == 0)
	{
		exitSush();
	} 
	// Pwd
	else if (strcmp(commandTokens[0], "pwd") == 0)
	{
		pwd();
	} 
	// Cd
	else if (strcmp(commandTokens[0], "cd") == 0)
	{
		if (commandTokens[1] == NULL)
			cd(HOME);
		else
			cd(commandTokens[1]);
	} 
	// Echo
	else if (strcmp(commandTokens[0], "echo") == 0)
	{
		echo(commandTokens[1] == NULL ? "" : commandTokens[1]);
	}
	// Comments starting with # are ignored.
	else if (commandTokens[0][0] == '#')
	{
		return false;
	}
	// Unrecognized Command.
	else
	{
		fprintf(stderr, "Command \"%s\" not recognized\n", commandTokens[0]);
	 	return false;
	}
	return true;
}
 
/**
 * Initializer: Set environment variables,
 * try to find .sushrc, execute it if able.
 * Else (basically do nothing)
 */
void init() {
	// Set default environment variables.
	HOME = getcwd(HOME, 1023);
	CWD = getcwd(CWD, 1023);
	PS1 = "$";
	
  // Allocate memory for the commandTokens.
	commandTokens = malloc (COMMAND_BUFFER * sizeof(char));
	
	
	FILE *sushrc;
	// Attempt to open the .sushrc file in the open directory
	sushrc = fopen(strcat(HOME, "/.sushrc"), "r");	
	// Execute commands in .sushrc
	if (sushrc != NULL) {
	   // Run all commands found in .sushrc
	   char* command = malloc(COMMAND_BUFFER * sizeof(char));
	   while (fgets(command, COMMAND_BUFFER, sushrc))
	   	readAndExecute(command);
	   // free memory
	   free(command);		
		fclose(sushrc);
	}
}

void mainLoop() {
	char *command = malloc(COMMAND_BUFFER * sizeof(char));
	
	// Run until we hit the EOF for stdin (aka ^D)
	while (true) {
 	  // Poll for and read input.
		printf("%s ", PS1);
		fgets(command, COMMAND_BUFFER, stdin);
		
		// Break if we get an EOF.
		// putting it here instead of the while statement
		// prevents an error where the program thinks
		// EOF is a command.
		if (feof(stdin) !=0) break;
				
		readAndExecute(command);
	}
	// This only gets executed on ctrl+d but hey
	free(command);
	printf("\n");
}

/**
 * main -- call init and start the main loop
 */
int main(int argc, char **argv) {
	// Try to find and execute .sushrc
	init();
	// -- insert other initialization stuff --
	
	mainLoop();
	return 0;
}
