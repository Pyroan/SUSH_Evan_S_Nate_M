#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h> // TODO remove this when done testing
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

// true if everything is being concatenated as one token, false otherwise
bool stringFlag = false;

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
    if (stringFlag)
    {
       char temp[1023];
       strcpy(temp, commandTokens[i-1]);
       
       strcat(temp, " ");
       strcat(temp, nextToken);
       strcpy(commandTokens[i-1], temp);
       // Check for closing quotes.
       stringFlag = false;
       for (int j = 0; temp[j] != 0; j++)
       {
         if (temp[j] == '"')
         {
           stringFlag = stringFlag ? false:true;
         }
       }
    } 
    else
    {
      commandTokens[i] = nextToken;
      // Check for < and > and quotes.
      for (int j=0; commandTokens[i][j] != 0; j++)
      {
        // HANDLE REDIRECTION
        if (commandTokens[i][j] == '>' || commandTokens[i][j] == '<')
        {
          // further split up the token.
          char original[1023];
          strcpy(original, nextToken);
                  
          char redirect = commandTokens[i][j];
          
          if (j != 0)
          {  
            // Copy up to j into the token list
            commandTokens[i] = malloc(1023);
            strncpy(commandTokens[i], original, j);
            i++;
          }
          // Move to the next token
          commandTokens[i] = malloc(1);
          strncpy(commandTokens[i], &redirect, 1);
          
          if (original[j+1] != 0) {
            i++;
            commandTokens[i] = malloc(1023);
            strcpy(commandTokens[i], &original[j+1]);
          }
        } 
        // HANDLE QUOTES
        else if (commandTokens[i][j] == '"')
        {
          stringFlag = stringFlag ? false:true;
        }
      }
      i++;
    }
		nextToken = strtok(NULL, " ");
		
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