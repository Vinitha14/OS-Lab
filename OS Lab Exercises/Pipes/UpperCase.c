/*
	16-09-18
	Shukrithi Rathna
	CED16I031
*/
/*
	Conversion of string to upper case
*/

#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	int i;
	printf("\nEnter string (less than 100 char) for conversion: ");
	gets(s);
	int n=strlen(s);
	//printf("\n%d",n);
	for(i=0;i<n;i++)
	{
		if((s[i]>='a')&&(s[i]<='z'))
			s[i]=s[i]-32;
	}
	printf("Converted string: \n%s\n",s);

	return(0);
}

