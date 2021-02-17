#include <stdio.h>
#include <omp.h>

#define LEN 100

int sumOfSquares(int val){
	int i;
	int sum = 0;

	for(i = 0; i <= val; i++){
		sum += (i * i);
	}

	return sum;
}

int squareOfSum(int val){
	int i;
	int sum = 0;

	for(i = 0; i <= val; i ++){
		sum += i;
	}

	return sum * sum;

}

int main(){
	int sumOfSqrs;
	int sqrOfSums;
	int diff;

	printf("Finding the diff of sum of sqrs and sqr of sums for %d numbers\n", LEN);
	// Test Open MP
#ifndef _OPENMP
	fprintf( stderr, "OpenMp is not supported");
	return 1;
#endif

#pragma omp parallel num_threads(2)
#pragma omp single
	{
	
	#pragma omp task
		sumOfSqrs = sumOfSquares(LEN);
	#pragma omp task
		sqrOfSums = squareOfSum(LEN);

	#pragma omp taskwait
	}

	diff = sqrOfSums - sumOfSqrs;

	printf("The Sum of Squares is %d\n", sumOfSqrs);
	printf("The Square of Sums is %d\n", sqrOfSums);
	printf("The diff in sums are %d\n", diff);

	return (0);
}
