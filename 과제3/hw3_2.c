/* ID 2015110899        - REPLACE WITH YOUR ID
 * NAME 이원규       - REPLACE WITH YOUR NAME */

//////////////////////////////////////////////////////////////////
// If you have referred any code, leave the comments like this
// to avoid "COPY"
// SOURCE for heapify: https://www.geeksforgeeks.org/heap-sort/
///////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEASURE_TIME	// to measure execution time
// from GJANG: not sure if the time measurement code works with Windows
// If it works, execution time will be printed.
// Otherwise, comment out the line "#define MEASURE_TIME" and compile again.

/////////////////////////////////////////////////////////////////////
// to compute execution time in seconds
/////////////////////////////////////////////////////////////////////
#ifdef MEASURE_TIME
#include<time.h>
#endif

/////////////////////////////////////////////////////////////////////
// homework programming assignment 3-2
/////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// What to do:
// 1) Implement
//    MinHeapify(int arr[], int n, int i)
//    reorders the array elements to satisfy min heap property
// 2) Implement
//    MinHeapSort(int arr[], int n)
//    sort the array in an ascending (increasing) order
///////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
// ***FILL*** if necessary, your functions can be added
/////////////////////////////////////////////////////////////////////

// hw3_1 의 source 참고
void MinHeapify(int arr[], int n, int i)
{
    int minimum = i; // Initialize minimum as root
    int l = 2*i; // left = 2*i + 1
    int r = 2*i+1; // right = 2*i + 2
    int tmp;
    //If left child is lower than root
    if (l < n && arr[l] < arr[minimum])
        minimum = l;

    // If right child is lower than minimum so far
    if (r < n && arr[r] < arr[minimum])
        minimum = r;

    // If minimum is not root
    if (minimum != i)
    {
        tmp=arr[i];
        arr[i]=arr[minimum];
        arr[minimum]=tmp;


        // Recursively heapify the affected sub-tree
        MinHeapify(arr, n, minimum);
    }
}

void MinHeapSort(int arr[], int n)
{
    int arr_result[n+1];  // 오름차순 sorting 결과를 저장할 배열 
    int tmp;
    // Build heap (rearrange array)
    for (int i = n/2; i >= 1; i--)
        MinHeapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n; i>0; i--)
    {
        // minimum value를 arr_result로 옮기고 가장 마지막 요소를 배열의 첫번쨰로 이동
        arr_result[n-i+1]=arr[1];
        arr[1]=arr[i];

        // call min heapify on the reduced heap
        MinHeapify(arr, i, 1);
    }
	// arr_result 배열을 원래 배열 arr에 복사
    memcpy(arr, arr_result, sizeof(int)*(n+1));
}

/////////////////////////////////////////////////////////////////////
// test your implementation
/////////////////////////////////////////////////////////////////////
int main()
{
  int i, N;
  int *A;

  // 0. read input
  fscanf(stdin, "%d", &N);

  // allocate interger arrays and read input values
  // In the textbook, the array indexing is 1-based (i.e. starts with 1)
  // so this template code is written for 1-based indexing
  // (starts with 1, leaving A[0] untouched.
  // If you prefer 0-based indexing, you may modify the example code below
  // ex.) "for (i=1; i<=N; i++) " --> "for (i=0; i<N; i++) "
  // "median = L[1]; " --> "median = L[0]; "
  A = (int*)malloc(sizeof(int)*(N+1));
  for (i=1; i<=N; i++) {
    if ( fscanf(stdin, "%d", A+i) != 1 ) {
      fprintf(stderr, "cannot read integer from standard input.\n");
      free(A);
      exit(0);
    }
  }

#ifdef MEASURE_TIME
  clock_t start, end;
  double cpu_time_used;

  start = clock();
#endif
  /////////////////////////////////////////////////////////////////////
  // ***FILL*** :  invoke Heap4Median_Build(...) to obtain sub-heaps L and R
  /////////////////////////////////////////////////////////////////////
  MinHeapSort(A, N);

#ifdef MEASURE_TIME
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  fprintf(stderr,">> Execution time: %.5f seconds\n",cpu_time_used);
#endif

  // output for evaluation: sorted list
  for (i=1; i<=N; i++) fprintf(stdout, "%d ", A[i]);
  fprintf(stdout, "\n");

  // free memory
  free(A);

  return 0;
}

