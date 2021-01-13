/*
	Shukrithi Rathna
	9-10-18
	Merge and Quick sort using threads
*/

/*
	Input array for calculation is 
	taken as command line argument
	with first arg as size of array.
	Array size should be less than 100
*/
//multi threading, processing, programming, tasking
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>


void QuickSort(int a[], int beg, int end);
int Partition(int a[],int beg, int end);
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);

//Threads call these functions
void *Mergesort(void *param[]); 
void *Quicksort(void *param[]);
//void *mode(void *param[]);
 
int main(int argc, char *argv[])
{
	pthread_t tid[2];//the thread identifiers
	pthread_attr_t attr;// set of thread attributes
	int i;
	if (argc<3)
	{
		fprintf(stderr,"Wrong input");
		return -1;
	}
	if (atoi(argv[1]) < 0)
	{
		fprintf(stderr,"\n First argument must be >= 0\n");
		return -1;
	}
	pthread_attr_init(&attr);
	
	pthread_create(&tid[0],&attr,Mergesort,argv);//Create thread for merge sort
	pthread_create(&tid[1],&attr,Quicksort,argv);//Create thread for quick sort
	//pthread_create(&tid[2],&attr,mode,argv);//Create thread for mode
	
	for(i=0;i<2;i++)
	{
		pthread_join(tid[i],NULL);//wait for the thread to exit
	}
	//pthread_join(tid[0],NULL);
	printf("\nArray Sorted\n");
}

//The threads will begin control in their appropriate functions

void *Quicksort(void *param[])
{
	int i,j,sum=0;
	int n=atoi(param[1]);
	int mid;
    int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=atoi(param[i+2]);
	}
    i=0; j=n-1;
   	QuickSort(a,0,n-1);
    printf("\nQuick Sort\n");
    printf("\t\t\t");
    for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	pthread_exit(NULL);
	
}

void *Mergesort(void *param[])
{
	int i,j,sum=0;
	int n=atoi(param[1]);
	int mid;
    int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=atoi(param[i+2]);
	}
    i=0; j=n-1;
    mergesort(a,i,j);
    printf("\nMerge Sort\n");
    printf("\t\t\t");
    for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	pthread_exit(NULL);
	
}

void mergesort(int a[],int i,int j)
{
    int mid;
        
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);        //left recursion
        mergesort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[50];    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;
    
    while(i<=j1 && j<=j2)    //while elements in both lists
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    
    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];
        
    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];
        
    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}

void QuickSort(int a[],int beg, int end)
{
    int j;
    if(beg<end)
    {
        j=Partition(a,beg,end);
        QuickSort(a,beg,j-1);
        QuickSort(a,j+1,end);
    }
}

int Partition(int a[], int beg, int end)
{
    int i=beg,j=end,k,temp;
    int pivot=a[beg];
    while(i<=j)
    {
        while((a[i]<=pivot)&&i<=end)
            i++;
        while((a[j]>pivot)&&j>=beg)
            j--;
        //swap a[i] and a[j];
        
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[beg];
    a[beg]=a[j];
    a[j]=temp;
    return(j);
}

