#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"
/**
 * Splits the passed in line into an array of
 * tokens.
 * @author Evan
 */
/**
 * 1. A token consists of one or more non-whitespace characters.
 * 2. Each token is separated by one or more spaces.
 * 3. < and > are special characters. When encountered, they are treated
 *       as their own token, regardless of spacing.
 * 4. When " is encountered, all characters until the next " are treated
 *       as one token.
 * 5. Trailing new line must be deleted.
 */
char** tokenize (char *line) {
	char thing[10][1023];
	int i = 0;
	while (line != "\n")
	{
		strcpy(&thing[i][0], strtok(line, " "));
		i++;
	}
	return thing;
}

/*
// For testing.
int main(void) {
	char* testString;
	fgets(testString, 1023, stdin);
	char** testTokens = tokenize(testString);
	
	return 0;
}
*/
