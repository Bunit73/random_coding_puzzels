#include <omp.h>
#include <stdio.h>
#include <stdbool.h>

void swap(char* xp, char* yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// Function to perform Selection Sort
void selectionSort(char arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

bool containsSameNumbers(int a, int b) {
	char strA[12];
	char strB[12];

	int i;
	int lenA;
	int lenB;

	sprintf(strA, "%d", a);
	sprintf(strB, "%d", b);

	lenA = sizeof(strA) / sizeof(strA[0]);
	lenB = sizeof(strB) / sizeof(strB[0]);

	if(lenA != lenB){
		return false;
	}

	selectionSort(strA, lenA);
	selectionSort(strB, lenB);

	for(i = 0; i < lenA; i++){
		if(strA[i] != strB[i]){
			printf("orig number %s doesnt have the same values of %s\n", strA, strB);
			return false;
		}
	}


	return true;

}

bool containsSameNumLen(int a, int b){
	int lenA = a;
	int lenB = b;

	// Check to see if the same len
	while (lenA > 0 && lenB > 0){
		lenA = lenA / 10;
		lenB = lenB / 10;
	}

	if(lenA != lenB){
		return false;
	}




	return true;
}

bool isPermuted6(int a){
	int i;
	if(a = 125874){
		printf("checking all values of %d\n", a);
	}
	for(i = 2; i < 3; i++){
/*		if(!containsSameNumLen(a, a * i)){
			printf("%d and %d have different lens\n", a, a * i);
			return false;
		}
		*/
		if(!containsSameNumbers(a, a * i)){	
			return false;
		}
	}
	printf("%d contains the same digits for 2x... 6x  \n", a);
	return true;
}



int main()
{
  /* OpenMP does not provide a parallel while loop,
     so we're going to have to make one ourselves... */
	int sj, sstop, tn, tj;
 	bool tstop;

//Test openMP
#ifndef _OPENMP
	fprintf( stderr, "OpenMp is not supported");
	return 1;
#endif

#pragma omp parallel num_threads(4)

  /* Start carefully - we don't want all threads
     to (re!)initialize the two shared variables */
  sj = -1;     // shared loop counter
  sstop = 0;   // shared stopping condition

  #pragma omp parallel private(tn,tj,tstop)
  {
    tn = omp_get_thread_num();
    while (!sstop)
    {
      /* Threads update the shared counter by turns */
      #pragma omp critical
      {
        sj++;      // increment the shared loop counter...
        tj = sj;   // ...and keep a private copy of it
      }
      /* Threads evaulate function foo in parallel */
      tstop = isPermuted6(tj);
      /* Flip sstop for everyone if tstop is true in a thread */
      if (tstop)
      {
        sstop = 1;
        #pragma omp flush(sstop)
      }
      /* When sstop=1, most threads continue to this statment */
      // printf("Thread %d, iteration %d, sstop=%d\n",tn,tj,sstop);
    }
  }
}
