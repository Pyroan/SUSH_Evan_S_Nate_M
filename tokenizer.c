#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"
/**
 * Splits the passed in line into an array of
 * tokens.
 * @author Evan
 */
/**
 * 1. A token consists of one or more non-whitespace characters. ✔️
 * 2. Each token is separated by one or more spaces. ✔️
 * 3. < and > are special characters. When encountered, they are treated
 *       as their own token, regardless of spacing.
 * 4. When " is encountered, all characters until the next " are treated
 *       as one token.
 * 5. Trailing new line must be deleted. ✔️
 */
char **commandTokens;

char** tokenize (char *line) {
	// Delete trailing newline in line
	int j = 0;
	while (line[j] != '\0') {
		j++;
	}
	if (line[j-1] == '\n') line[j-1] = 0;
	// holy crap that actually worked. Dirty.
	
	// Clear commandTokens
	memset(commandTokens, '\0', 1023);
	
	// Tokenize the string.
	int i = 0;
	char *nextToken = strtok(line, " ");
	while (nextToken != NULL)
	{
		commandTokens[i] = nextToken;
		nextToken = strtok(NULL, " ");
		i++;
	}
	
	return commandTokens;
}

/*
// For testing.
int main(void) {
	commandTokens = malloc (1023 * sizeof(char));

	char testString[1023];
	fgets(testString, 1023, stdin);
	printf("testString: %s", testString);
	tokenize(testString);
	
	// print each token.
	int i = 0;
	while (commandTokens[i] != NULL)
	{
		printf("Token %d: %s\n", i, commandTokens[i]);
		i++;
	}
	free(commandTokens);
	return 0;
}
*/
