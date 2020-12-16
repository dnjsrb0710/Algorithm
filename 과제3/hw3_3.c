/* ID 2015110899       - REPLACE WITH YOUR ID
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
// homework programming assignment 3-3
/////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// function to find median using min heap and max heap
// to find median value from an array, use the following heap architecture
// 1) store all the data to heap L and heap R
// 2) all values in L < any value in R
// 3) if the number of total items is N,
//   odd  N: number of items in L = N/2+1, number of items in R = N/2
//   even N: number of items in L = number of items in R = N/2
//     i.e. n_L = n_R or n_L = n_R+1
// 4) keep L as max heap, keep R as min heap, then the median is root(L)
//   *in many definitions of median, when N is even, the median is
//    defined as an average of item N/2 and item N/2+1, but we assume
//    it is root(L) (item ceiling(N/2)) to make the problem simple
//   *all values in L <= root(L), so it also satisfies definition of median
//   *Reference:
// https://www.quora.com/How-do-you-find-the-median-from-a-set-of-even-numbers
// https://www.dkfindout.com/us/math/averages/more-about-medians/
//
// What to do:
// 1) Implement
//    Heap4Median_AddItem(int L[], int *p_n_L, int R[], int *p_n_R, int value)
//    to add a value to L and R
//    heaps L and R should satisfy the above conditions
// 2) Implement
//    Heap4Median_Build(int A[], int N, int L[], int *p_n_L, int R[], int *p_n_R)
//    For an unsorted array, it builds heaps L and R from empty heaps
//    A: size N array
//    L: size ceil(N/2) array,  R: size floor(N/2) array
//    the array memory should be allocated in advance
// 3) Implement
//    Heap4Median_Sort(int L[], int n_L, int R[], int n_R, int A[], int p_N)
//    For Heap4Median given by L and R (with their number of elements by n_L and n_R)
//    fill the array A in an ascending order
///////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
// ***FILL*** if necessary, your functions can be added
/////////////////////////////////////////////////////////////////////

// hw3_1, hw3_2 source 들
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



void MaxHeapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i; // left = 2*i + 1
    int r = 2*i+1; // right = 2*i + 2
    int tmp;
    //If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        tmp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=tmp;


        // Recursively heapify the affected sub-tree
        MaxHeapify(arr, n, largest);
    }
}

//SOURCE for MaxHeapSort: https://www.geeksforgeeks.org/heap-sort/
void MaxHeapSort(int arr[], int n)
{
    int tmp;
    // Build heap (rearrange array)
    for (int i = n/2; i >= 1; i--)
        MaxHeapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n; i>1; i--)
    {
        // Move current root to end
        tmp=arr[1];
        arr[1]=arr[i];
        arr[i]=tmp;

        // call max heapify on the reduced heap
        MaxHeapify(arr, i, 1);
    }
}

// 교수님 권유 참조 자료 : http://pages.cs.wisc.edu/~mcw/cs367/lectures/heaps.html
void minheapifyup(int arr[],int n){
    int tmp;

    if(n != 1 && arr[n] < arr[n/2]){
        tmp=arr[n];
        arr[n]=arr[n/2];
        arr[n/2]=tmp;
        minheapifyup(arr,n/2);
    }

}

// 교수님 권유 참조 자료 : http://pages.cs.wisc.edu/~mcw/cs367/lectures/heaps.html
void maxheapifyup(int arr[],int n){
    int tmp;

    if(n != 1 && arr[n] > arr[n/2]){
        tmp=arr[n];
        arr[n]=arr[n/2];
        arr[n/2]=tmp;
        maxheapifyup(arr,n/2);
    }

}






void Heap4Median_AddItem(int L[], int *p_n_L, int R[], int *p_n_R, int value)
{
    if(*p_n_R<*p_n_L){

            if(L[1]>value){
                (*p_n_R)++;
                R[*p_n_R]=L[1];
                minheapifyup(R,*p_n_R);
                L[1]=value;
                MaxHeapify(L,*p_n_L,1);
            }

            else{
                (*p_n_R)++;
                R[*p_n_R]=value;
                minheapifyup(R,*p_n_R);
            }
    }
    else{

        if(R[1]<value){
            (*p_n_L)++;
            L[*p_n_L]=R[1];
            maxheapifyup(L,*p_n_L);
            R[1]=value;
            MinHeapify(R,*p_n_R,1);
        }

        else{
            (*p_n_L)++;
            L[*p_n_L]=value;
            maxheapifyup(L,*p_n_L);
        }



    }
}

void Heap4Median_Build(int A[], int N, int L[], int *p_n_L, int R[], int *p_n_R)
{

    *p_n_L=0;
    *p_n_R=0;

    for(int i=1;i<=N;i++){
        Heap4Median_AddItem(L , p_n_L , R , p_n_R , A[i]);
    }


}

void Heap4Median_Sort(int L[], int n_L, int R[], int n_R, int A[], int *p_N)
{
    MaxHeapSort(L, n_L);
    MinHeapSort(R,n_R);
    memcpy(A+n_L, R, sizeof(int)*(n_R+1));
    memcpy(A, L, sizeof(int)*(n_L+1));

}

/////////////////////////////////////////////////////////////////////
// test your implementation
/////////////////////////////////////////////////////////////////////
int main()
{
  int i, N;
  int *A, *L, *R;
  int n_L, n_R;

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

  L = (int*)malloc(sizeof(int)*(N/2+1+1));
  R = (int*)malloc(sizeof(int)*(N/2+1+1));

#ifdef MEASURE_TIME
  clock_t start, end;
  double cpu_time_used;

  start = clock();
#endif
  /////////////////////////////////////////////////////////////////////
  // ***FILL*** :  invoke Heap4Median_Build(...) to obtain sub-heaps L and R
  /////////////////////////////////////////////////////////////////////
  Heap4Median_Build(A, N, L, &n_L, R, &n_R);

  // output for evaluation: print median only
  fprintf(stdout,"%d\n",L[1]);

  Heap4Median_Sort(L, n_L, R, n_R, A, &N);

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
  free(L);
  free(R);

  return 0;
}

