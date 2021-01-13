/*
	Shukrithi Rathna
	CED16I031	
	Case Conversion using pipe	
*/

#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

#define BuffSize 25
#define REnd 0
#define WEnd 1
void Upper(char s[], int n);
void Upper(char s[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if((s[i]>='a')&&(s[i]<='z'))
			s[i]=s[i]-32;
	}
	printf("\nUppercase: \n%s\n",s);
}

void Lower(char s[], int n);
void Lower(char s[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if((s[i]>='A')&&(s[i]<='Z'))
			s[i]=s[i]+32;
	}
	printf("Lowercase string: \n%s\n",s);
}

int  main()
{
	int fd[2];
	char ReadMsg[BuffSize];
	char WriteMsg[BuffSize];
	pid_t pid;
	int pfd,n;
	
	
// creating pipe
	pfd=pipe(fd);

	if(pipe(fd)<0)
		fprintf("stderr","\nPipe creation unsuccessfull");
	pid=fork();
	
	if(pid<0)
		fprintf("stderr","\nFork unsuccessfull");
	else if(pid>0)
	{
		printf("\nParent process\t Writing to pipe");
		printf("\nEnter string (less than 100 char) for conversion: ");
		gets(WriteMsg);

		close(fd[REnd]);//Closing reading end

		//open(fd[WEnd]);
		write(fd[WEnd],WriteMsg,sizeof(WriteMsg)+1);//Writing 		
		
		close(fd[WEnd]);//Closing writing end
	}
	else
	{
		printf("\nChild process\tReading from pipe");

		close(fd[WEnd]);//Closing writing end

		//open(fd[REnd]);	
		read(fd[REnd],ReadMsg,BuffSize);//Reading	
		
		n=strlen(ReadMsg);
		
		Upper(ReadMsg,n);
		Lower(ReadMsg,n);

		close(fd[REnd]);//Closing reading end
		
	}
		

	return(0);
	
}
