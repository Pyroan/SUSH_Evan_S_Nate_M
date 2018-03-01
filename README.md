# SUSH_Evan_S_Nate_M
***sush***: A custom shell created for our CMPE-320 (Operating Systems) class.
## Requirements

### Environment Variables
`PS1` - The prompt for the user

`HOME` - Path to the home directory

`PATH` - Path to the external executable directory.

### Commands
##### Internal
`setenv [var] [variable]` - Create or modify the value of the environment variable `var`, and set its current value to *value*

`unsetenv [var]` - Delete environment variable `var` from the environment.

`cd [dir]` - Change working directory to `dir`. `~` refers to the HOME directory

`pwd` - Print working directory

`exit` - Exit *sush*
##### External
`¯\_(ツ)_/¯`

### Tokenization
Each line of input must be tokenized and then parsed into commands. Normally, tokens are space-delimited. However, anything located between two quotes (`" "`) is considered one token, and `>` and `<` are each treated as their own token. Finally, any trialing newlines must be deleted.
