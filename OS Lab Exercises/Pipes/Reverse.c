/*
	CED16I031
	Shukrithi Rathna
*/
/*
	Reversing case of string using
	Bidirectional Pipe
*/
#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>


#define BuffSize 50
#define REnd 0
#define WEnd 1

void UpperLower(char s[], int n);
void UpperLower(char s[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if((s[i]>='a')&&(s[i]<='z'))
			s[i]=s[i]-32;
		else if((s[i]>='A')&&(s[i]<='Z'))
			s[i]=s[i]+32;
	}

}


int  main()
{
	int fd1[2],fd2[2];
	char ReadMsg1[BuffSize];
	char WriteMsg1[BuffSize]="Hello FROM Parent";
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
		printf("\nParent process\tWriting to pipe ");
		printf("\n%s",WriteMsg1);
		close(fd1[REnd]);
		close(fd2[WEnd]);

//Writing 		
		write(fd1[WEnd],WriteMsg1,sizeof(WriteMsg1)+1);
		
		printf("\nParent Reading from Pipe ");
		read(fd2[REnd],ReadMsg2,BuffSize);
		printf("\n%s\n",ReadMsg2);
		
//Closing writing end
		close(fd1[WEnd]);
				
		close(fd2[REnd]);
	}
	else
	{
		printf("\nChild process\tReading from pipe ");

		close(fd1[WEnd]);//Closing writing end
		
		close(fd2[REnd]);

		read(fd1[REnd],ReadMsg1,BuffSize);//Reading		
		
		printf("\n%s\n",ReadMsg1);;
		UpperLower(ReadMsg1,strlen(ReadMsg1));
		//printf("\nChild process\tReWriting to pipe ");
		write(fd2[WEnd],ReadMsg1,BuffSize);	

//Closing reading end
		close(fd1[REnd]);
		
		close(fd2[WEnd]);		
	}
	
	return(0);
}
