//Box plot

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int size=0;
void *runner2(void *arg)
{
  int i,j,flag;
  int *array=(int *)arg;
int l;
   l=size/2;
    if(l%2==0)
    {
      int p,q;
      p=(l/2);
      q=(l/2)-1; 
      float k=(float)(array[q]+array[p])/2;
      printf("\nq2: %f\n",k);
    }
   else
    {
      int p=((l+1)/2)-1;
      printf("\nq2: %d\n",array[p]);   
    }
}
void *runner3(void *arg)
{
  int i,j,flag;
  int *array=(int *)arg;
 int l;
   l=size/2;
    if(l%2==0)
    {
      int p,q;
      p=((size+1)/2)+(l/2);
      q=((size+1)/2)+(l/2)-1; 
      float k=(float)(array[q]+array[p])/2;
      printf("\nq3: %f\n",k);
    }
   else
    {
      int p=((size+1)/2)+((l+1)/2)-1;
      printf("\nq3: %d\n",array[p]);   
    }
  //printf("\nq3: %d\n",array[size/2+size/4+1]);
}
void *runner4(void *arg)
{
   int *array=(int *)arg;
   printf("\nMax: %d\n",array[size-1]);
}
void *runner5(void *arg)
{
   int *array=(int *)arg;
   printf("\nMin : %d\n",array[0]);
}
void *runner1(void *arg)
{
  int i,j,flag;
  int *array=(int *)arg;
  for(i=0;i<size;i++)
  {
    for(j=i;j>0;j--)
    {
      if(array[j]<array[j-1])
      {
        int temp=array[j];
        array[j]=array[j-1];
        array[j-1]=temp;
      }
    }
  }

int l,m;
if(size%2==0)
{
 l=(size/2);
 m=(size/2)-1;
float k=(float)(array[l]+array[m])/2;
   printf("\nq1: %f\n",k);
}
else
{
 l=((size+1)/2)-1;
//printf("%d",size);
    printf("\nq1: %d\n",array[l]);
}
  pthread_t tid2,tid3,tid4,tid5;
  pthread_attr_t attr; 
  pthread_attr_init(&attr);
  int p2=pthread_create(&tid2,&attr,runner2,(void *)array);
  int p3=pthread_create(&tid3,&attr,runner3,(void *)array);
  int p4=pthread_create(&tid4,&attr,runner4,(void *)array);
  int p5=pthread_create(&tid5,&attr,runner5,(void *)array);
}


int main(int argc,char *argv[])
{
  pthread_t tid1;
  int *array = (int*)malloc((argc - 1)*sizeof(int));
  int i = 1;
  for(i = 1; i < argc ; i++){
    array[i-1] = atoi(argv[i]);
    size++;
  }
  pthread_attr_t attr; 
  pthread_attr_init(&attr);
  int p1=pthread_create(&tid1,&attr,runner1,(void *)array);
  
  if(p1<0)
  {
    fprintf(stderr,"\nThread not created\n");
    exit(0);
  }
  pthread_exit(NULL);
  return 0;
}

