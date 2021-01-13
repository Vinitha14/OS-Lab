/*
	16-09-18
	Shukrithi Rathna
	CED16I031
*/
/*
	Conversion of string to lower case
*/

#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	int i;
	printf("\nConversion to lower case");
	printf("\nEnter string (less than 100 char) for conversion: ");
	gets(s);
	int n=strlen(s);
	//printf("\n%d",n);
	for(i=0;i<n;i++)
	{
		if((s[i]>='A')&&(s[i]<='Z'))
			s[i]=s[i]+32;
	}
	printf("Converted string: \n%s\n",s);

	return(0);
}

