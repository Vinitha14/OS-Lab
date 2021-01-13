/*
	Shukrithi Rathna
	18-09-18
*/
/*
	ps and grep command in a piped fashion
	input - search string for grep 
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 
#include <sys/stat.h>
#include <fcntl.h>

#define BuffSize 25
#define REnd 0
#define WEnd 1

int main(int argc, char *argv[])
{
	int fd[2];
	char ReadMsg[BuffSize];
	char WriteMsg[BuffSize];
	pid_t pid,cpid;
	int i;

// creating pipe
	if(pipe(fd)<0)
		fprintf("stderr","\nPipe creation unsuccessfull");
	printf("\nSearch:");
		gets(ReadMsg);
	pid=fork();
	
	if(pid<0)
		printf("\nFork unsuccessfull");
	else if(pid>0)
	{
		printf("\nParent process\t Writing to pipe");

		close(fd[REnd]);//Closing reading end
		
		dup2(fd[1], 1);
		
		char *argv[] = {"ps",NULL}; // create argument vector
   		execvp(argv[0], argv);

		close(fd[WEnd]);//Closing writing end
	}
	else
	{
		printf("\nChild process\tReading from pipe");
		
		dup2(fd[0], STDIN_FILENO);  
		
		close(fd[WEnd]);
		close(fd[REnd]);
		
		char *argv[] = {"grep",ReadMsg,NULL}; // create argument vector
   		execvp(argv[0], argv);
	}
	return(0);
}
