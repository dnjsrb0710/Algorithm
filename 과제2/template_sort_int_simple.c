// 2015110899 이원규
/* ID: COMP319004
 * Name: Algorithms
 * School of Electronics Engineering, Kyungpook National University
 */

#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////
// print integer array
/////////////////////////////////////////////////////////////
void print_int_array( FILE *fp, int A[], int N )
  // A[]: array to print
  // N:   size of the array
  // fp:  file pointer, stdout or stderr for screen display
{
  int i;
  fprintf(fp,"%d\n",N);
  for (i=0; i<N; i++) fprintf(fp,"%d ",A[i]);
  fprintf(fp,"\n");
}

/////////////////////////////////////////////////////////////
// read integers from a text file
/////////////////////////////////////////////////////////////
int *read_int_textfile( const char infile[], int *pN )
  // returns an array of integers, with its size stored in
  // the memory indicated by integer pointer variable pN
  // the retured memory should freed by the caller
{
  int *A, tmp;
  int i;
  FILE *fp;

  // check for input file name
  if ( infile == NULL ) {
    fprintf(stderr, "NULL file name\n");
    return NULL;
  }

  // check for file existence
  fp = fopen(infile,"r");
  if ( !fp ) {
    fprintf(stderr, "cannot open file %s\n",infile);
    return NULL;
  }
  else {
    // check for number of elements
    if ( fscanf(fp, "%d", pN) != 1 || *pN <= 0 ) {
      fprintf(stderr, "cannot read number of elements %s\n",infile);
      return NULL;
    }
    else {
      A = (int*)malloc(sizeof(int)*(*pN));
      for (i=0; i<(*pN); i++) {
	if ( fscanf(fp, "%d", &tmp) != 1 ) {
	  fprintf(stderr, "cannot read value at %d/%d\n",i+1,(*pN));
	  *pN = i;	// read data items
	  return A;
	}
	else A[i] = tmp;
      }
    }
    fclose(fp);
    return A;
  }
}

/////////////////////////////////////////////////////////////
// write integers to a text file
/////////////////////////////////////////////////////////////
void write_int_textfile( const char outfile[], int A[], int N )
  // write the given array of int integers, with its sie N
  // to file whose name given by outfile[]
  // uses print_int_array
{
  FILE *fp;

  // check for output filename
  if ( outfile == NULL ) {
    fprintf(stderr, "NULL file name\n");
    return;
  }

  // check for file existence
  fp = fopen(outfile,"w");
  if ( !fp ) {
    fprintf(stderr, "cannot open file for write %s\n",outfile);
  }
  else {
    print_int_array(fp,A,N);
    fclose(fp);
  }
}

/////////////////////////////////////////////////////////////
// insertion sort
/////////////////////////////////////////////////////////////
void insertion_sort ( int arr[], int n ) {
  //* source: https://gmlwjd9405.github.io/2018/05/06/algorithm-insertion-sort.html
    int i,j,key;
    //인덱스0은 이미 정렬되어있다.
    for(i=1;i<n;i++){
        key=arr[i];

        //j는 음수가 아니고 key갑보다 배열값이 크면 j번째를 j+1번쨰로 이동
        for(j=i-1;j>=0&&arr[j]>key;j--){
            arr[j+1]=arr[j];//오른쪽으로 이동
        }
        arr[j+1]=key;

    }





}

/////////////////////////////////////////////////////////////
// selection sort
/////////////////////////////////////////////////////////////
void selection_sort(int arr[], const int n) {
   //* source: https://gmlwjd9405.github.io/2018/05/06/algorithm-selection-sort.html
  int i,j,least,tmp;
  //마지막숫자는 정렬할 필요가 없다.
  for(i=0;i<n-1;i++){
    least=i;
    //최소값 탐색.
    for(j=i+1;j<n;j++){
        if(arr[j]<arr[least])
            least=j;
    }
    //최소값이 자기 자신이면 이동x
    if(i!=least){
        tmp=arr[i];
        arr[i]=arr[least];
        arr[least]=tmp;
    }
  }

}

/////////////////////////////////////////////////////////////
// bubble sort
/////////////////////////////////////////////////////////////
void bubble_sort(int arr[], int n) {
  /* sample reference
   * source: https://ko.wikipedia.org/ */
  int i, j;
  int temp;
  for (i=n-1; i>0; i--) {
    for (j=0; j<i; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}


/////////////////////////////////////////////////////////////
// main function
/////////////////////////////////////////////////////////////
int main()
  /* Input file name by scanf read, typed in the terminal */
{
  int numElements;
  int *A;	// to store data to be sorted

  /* for file name, max length 1023 including path */
  char infile[1024], outfile[1024];
  int method;	// which sorting method

  /* file name given by keyboard */
  printf("Input file name? ");
  scanf("%s",infile);
  printf("Output file name? ");
  scanf("%s",outfile);

  printf("Method (1: insertion, 2: selection, 3: bubble)? ");
  scanf("%d",&method);

  /* read text file of integers:
   * number_of_intergers integer1 integer2 ... */
  A = read_int_textfile(infile, &numElements);

  if ( A != NULL && numElements > 0 ) {
    switch ( method ) {
      case 1:	// insertion sort
	insertion_sort(A, numElements);
	break;
      case 2:	// selection sort
	selection_sort(A, numElements);
	break;
      case 3:	// bubble sort
	bubble_sort(A, numElements);
	break;
      default:
	break;
    }

    // save results
    write_int_textfile(outfile, A, numElements);

    // once allocated, should be freed after use
    free(A);
  }

  return 0;
}

