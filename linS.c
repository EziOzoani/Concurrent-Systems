
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t clockTime;
double cpu_time;

int linearSearchRuntheArr(int* A, int n, int tos);

int main(){
	int notFound =0;
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
        int indexVal = linearSearchRuntheArr(theArr, val, find);
        clockTime = clock()-clockTime;

        if(indexVal != -1)
                
		printf("Found value at index : %d\n",indexVal);
			

        cpu_time = ((double)clockTime)/CLOCKS_PER_SEC;
        printf("\nTime taken for search: %f\n", cpu_time);

        return 0;



}



int linearSearchRuntheArr(int* A, int n, int tos){
	int index =0;
	for(; index < n; index++){
		if(A[index] == tos)
			return index;
	}
}
