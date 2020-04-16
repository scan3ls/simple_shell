# hsh - A simple shell

##### Holberton Shell (hsh) is a simple command line shell for Linux. Hsh includes basic features present in the bash shell. This shell was built as a project for Holberton School.

------

HSH builds successfully with a GCC 4.8.5 compiler or later. HSH can compile using `gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o hsh`.

###### Usage
```
./hsh
``` 

#### Syntax Overview

------

General syntax: `command name {arguments}`. Commands are executed by writing the name of the command followed by any arguements. 

```
ls -l /bin
```

##### List of fully implemented commands

`cat` - concatenate and print files to standout output

`ls` - lists all files and directories of current working directory

`pwd` - prints out the current working directory

##### exit

To exit out of the shell, the user may use the `exit` builtin, or press `CTRL+D`