/*
	Shukrithi Rathna
	CED16I031	
	Inverse of Matrix
*/

/*
	Inverse of a matrix using threads.
	Takes 3x3 matrix as input.
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define N 3

//Threads call these functions
void *determinant(void *param[]); 
void *adjoint(void *param[]);

int determinantOfMatrix(int mat[N][N], int n);
void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n);

//global variables
int det;
int m[N][N];//input matrix
int adj[N][N];//adjoint matrix

int main()
{
	int i,j;
//	int  *ptr[2];
	float inverse[N][N];
	printf("\nEnter the matrix:\n");
	for(i=0;i<N;i++)
	{	
		for(j=0;j<N;j++)
		{
			scanf("%d",&m[i][j]);
		}
	}

	pthread_t tid[2];//the thread identifiers
	pthread_attr_t attr;// set of thread attributes
	pthread_attr_init(&attr);
	
	pthread_create(&tid[0],&attr,determinant,NULL);//Create thread for determinant
	pthread_create(&tid[1],&attr,adjoint,NULL);//Create thread for adjoint
	
	pthread_join(tid[0],NULL);//wait for the determinant thread to exit
	if(det==0)
	{
		pthread_cancel(tid[1]);
		printf("\nDeterminant = 0 . Inverse cannot be computed\n");
	
	}
	else	
	{
		pthread_join(tid[1],NULL);//wait for the adjoint thread to exit
		printf("\nDeterminant %d\nAdj:\n",det);
		for(i=0;i<N;i++)
		{	
			for(j=0;j<N;j++)
			{
				printf("%d ",adj[i][j]);
			}
			printf("\n");
		}
		for (i=0;i<N;i++) 
    	{
    		for (j=0;j<N;j++) 
    		{
    			inverse[i][j] = adj[i][j]/(float)(det); 
    		}
    	}
    	printf("\nInverse:\n");
    	for(i=0;i<N;i++)
		{	
			for(j=0;j<N;j++)
			{
				printf("%f ",inverse[i][j]);
			}
			printf("\n");
		}
	}
		return(0);
}

void *determinant(void *param[])
{
	 det=0; 
	 int i;
	 int temp[N][N]; // To store cofactors 
     int sign=1;  // To store sign multiplier 
    //Base case:if matrix contains single element 
    if (N==1) 
        printf("\nOnly one element"); 
  
    
  
     // Iterate for each element of first row 
    for(i=0;i<N;i++) 
    { 
        // Getting Cofactor of m[0][i] 
        getCofactor(m,temp,0,i,N); 
        det+=sign*m[0][i] * determinantOfMatrix(temp,N-1); 
  
        // terms are to be added with alternate sign 
        sign=-sign; 
       // printf("\nDet: %d",det);
    } 
    pthread_exit(NULL);
  
}
void *adjoint(void *param[]) 
{ 
    if (N == 1) 
    { 
        adj[0][0] = 1; 
        return; 
    } 
  
    // temp is used to store cofactors 
    int sign=1,temp[N][N]; 
  	int i,j;
    for (i=0;i<N;i++) 
    { 
        for (j=0;j<N;j++) 
        { 
            //Get cofactor of m[i][j] 
            getCofactor(m,temp,i,j,N); 
            // sign of adj[j][i] positive if sum of row and column is even. 
            if((i+j)%2==0)
	            sign=1;
	        else
	        	sign=-1;  
            // Interchanging rows and columns to get the 
            // transpose of the cofactor matrix 
            adj[j][i] = (sign)*(determinantOfMatrix(temp, N-1)); 
        } 
    } 
    pthread_exit(NULL);
} 
void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n) 
{ 
    int i=0,j=0; 
    int row,col;
  
    //for each element in the matrix 
    for (row=0;row<n;row++) 
    { 
        for (col=0;col<n;col++) 
        { 
            //  Copying into temporary matrix only those elements
            //  which are not in given row and column 
            if (row!=p&&col!=q) 
            { 
                temp[i][j++]=mat[row][col]; 
                  // Row is filled, so increase row index and 
                // reset col index 
                if (j==n-1) 
                { 
                    j=0; 
                    i++; 
                } 
            } 
        } 
    } 
}
int determinantOfMatrix(int mat[N][N], int n) 
{ 
    int D = 0; // Initialize result   
    //If matrix contains single element 
    if (n == 1) 
        return mat[0][0]; 
  
    int temp[N][N]; // To store cofactors 
  	int f;
    int sign = 1;  // To store sign multiplier 
  
    // Iterate for each element of first row 
    for (f=0;f<n;f++) 
    { 
        // Getting Cofactor of mat[0][f] 
        getCofactor(mat,temp,0,f,n); 
        D+=sign * mat[0][f] * determinantOfMatrix(temp, n - 1); 
        // terms are to be added with alternate sign 
        sign=-sign; 
    } 
  
    return D; 
} 

	
