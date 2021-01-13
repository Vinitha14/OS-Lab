/*
	Shukrithi Rathna
	04-09-18
	Zombie Process
*/

/*	Child becomes a zombie if it exits
	while parent is sleeping
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	pid_t cpid;
	cpid=fork();
	if(cpid>0)
		sleep(100);
	else
		exit(0);
	return(0);
}
