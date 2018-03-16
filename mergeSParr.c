#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
clock_t clockTime;
double cpu_time;

void merge(int* array, int start, int end) {
    int middle = (start + end) / 2;
    int temp_index = 0;

    //  temp array 
    int* temp = malloc(sizeof(int) * (end - start + 1));

    // merge sorted data from 2 halves 
    int left = start;
    int right = middle + 1;

    
    while((left <= middle) && (right <= end)) {
        
        if (array[left] < array[right]) {
            
            temp[temp_index] = array[left];
            temp_index++;
            left++;
        }
        else {
            
            temp[temp_index] = array[right];
            temp_index++;
            right++;
        }
    }

    
    while(left <= middle) {
        temp[temp_index] = array[left];
        temp_index++;
        left++;
    }

     
    while(right <= end) {
        temp[temp_index] = array[right];
        temp_index++;
        right++;
    }

     
    int i;
    for(i = start; i <= end; i++) {
        array[i] = temp[i - start];
    }

    //free temp array
    free(temp);
}

void mergeSort(int* array, int start, int end) {
    if(start < end) {
        printf("Thread %d is sorting %d through %d\n", omp_get_thread_num(), start, end);
        int middle = (start + end) / 2;

        // sorts both halves in parallel
        #pragma omp parallel 
        {
            #pragma omp single
            {
                #pragma omp task
                mergeSort(array, start, middle);

                mergeSort(array, middle + 1, end);
            }
        }

        // merge said halves 
        merge(array, start, end);
    }
}

int main( ) {
    int randomNum = 100000;
    int nums[randomNum], i;

    //causes recursive parallel blocks 
    omp_set_nested(1);

    //random numbers - populates
    for(i = 0; i < randomNum; i++) {
        nums[i] = rand( ) % 100;
    }

   

    
    clockTime = clock();
    mergeSort(nums, 0, 24);
    clockTime = clock()-clockTime;

    
     cpu_time = ((double)clockTime)/CLOCKS_PER_SEC;

    printf("\nTime taken for search: %f\n", cpu_time);

    printf("\n");
    return 0;
}

