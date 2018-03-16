 
#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <time.h>

clock_t clockTime;
double cpu_time;
int linearSParr(int*A, int n , int tos);

int main(){

        int val, iter =0, find;
	val = 100000;
        int theArr[val] , i;

	 //  random numbers to sort through

 
	    for(i = 0; i < val; i++) 
	     	{
        		theArr[i] = rand( ) % 100;
       		}

        //random variable to find
	find = rand( ) % 100;

        //printf("\n Value to find: %d\n", find);

	clockTime = clock();
        int indexVal = linearSParr(theArr, val, find);
	clockTime = clock()-clockTime;

        if(indexVal != -1)
		printf("Found value at index :  %d\n", indexVal);

	cpu_time = ((double)clockTime)/CLOCKS_PER_SEC;
	printf("\nTime taken for search: %f\n", cpu_time);
	
        return 0;
}


int linearSParr(int* A, int n, int tos)
{

	int index;
	int indexFound =-1;

	#pragma omp parallel for
        for(index=0;index < n;index++)
	{
                if(A[index] == tos)
                        indexFound = index+1 ;

        }
	return indexFound;
}


