/*
	Shukrithi Rathna
	CED16I031
*/
/*
	Bidirectional Pipe
*/
#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<sys/types.h>

#define BuffSize 50
#define REnd 0
#define WEnd 1
int  main()
{
	int fd1[2],fd2[2];
	char ReadMsg1[BuffSize];
	char WriteMsg1[BuffSize]="Hello from Parent";
	char ReadMsg2[BuffSize];
	char WriteMsg2[BuffSize]="Hello from Child";

	pid_t pid;
	
	// creating pipes
	if(pipe(fd1)<0)
		printf("\nPipe 1 creation unsuccessfull");
	if(pipe(fd2)<0)
		printf("\nPipe 2 creation unsuccessfull");
	
	pid=fork();
	if(pid<0)
		printf("\nFork unsuccessfull");
	else if(pid>0)
	{
		printf("\nParent process\t Writing to pipe 1");
		close(fd1[REnd]);
		close(fd2[WEnd]);
//Writing 		
		write(fd1[WEnd],WriteMsg1,sizeof(WriteMsg1)+1);
		
		printf("\nParent Reading from Pipe 2");
		read(fd2[REnd],ReadMsg2,BuffSize);
		printf("\n%s\n",ReadMsg2);
		
//Closing writing end
		close(fd1[WEnd]);
				
		close(fd2[REnd]);
	}
	else
	{
		printf("\nChild process\tReading from pipe 1");
//Closing writing end
		close(fd1[WEnd]);
		close(fd2[REnd]);
//Reading		
		read(fd1[REnd],ReadMsg1,BuffSize);
		printf("\n%s\n",ReadMsg1);
		printf("\nWriting to Pipe2\n");
		write(fd2[WEnd],WriteMsg2,BuffSize);	

//Closing reading end
		close(fd1[REnd]);
		
		close(fd2[WEnd]);		
	}
	
	return(0);
}
