/*
	Shukrithi Rathna
	21-09-18
	CP command simulation
*/

/*	Input file name followed by output file name are takencommand line
	arguments.
	Example: ./CP in.txt out.txt
*/
#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<sys/types.h>

#define BuffSize 1024
#define REnd 0
#define WEnd 1

int main(int argc, char *argv[])
{
	int fd[2];
	char ReadMsg[BuffSize];
	char WriteMsg[BuffSize];
	pid_t pid;
	int pfd;
	FILE *fp, *fp1;
	
	if (argc != 3) //No output file; argv[0] contains program name; argv[1] contains file name
	{
		fprintf(stderr, "\nInput and Output file name not given\n");
		exit(1); 
	}
// creating pipe
	pfd=pipe(fd);
	//close(fd[WEnd]);
	//close(fd[REnd]);
	if(pfd<0)
		printf("\nPipe creation unsuccessfull");
	else
		pid=fork();
	
	if(pid<0)
		printf("\nFork unsuccessfull");
	else if(pid>0)
	{

		close(fd[REnd]);//Closing reading end of pipe
	
		fp =fopen(argv[1],"r");//Open input file and read	
		fgets(WriteMsg,BuffSize,(FILE*)fp);

		fclose(fp);//Close file

		write(fd[WEnd],WriteMsg,sizeof(WriteMsg)+1);//Write contents of file to pipe

		close(fd[WEnd]);//Closing writing end of pipe
	}
	else
	{
		close(fd[WEnd]);//Closing writing end of pipe
		read(fd[REnd],ReadMsg,BuffSize);//Reading from pipe

		printf("\n Contents of file %s has been written to %s\n", argv[1], argv[2]);

		fp1=fopen(argv[2],"w+");//Open output file and write
		fprintf(fp1,ReadMsg);

		fclose(fp1);//Close file	
		close(fd[REnd]);//Closing reading end of pipe
	}
	return(0);
}
