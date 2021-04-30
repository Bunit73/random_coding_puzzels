#include <stdio.h>
#include <omp.h>
#include <gmp.h>

#define UPPER_LIMIT 1000000

unsigned int factorial(int val){
	int f = val;
	int i = val;

	if(i == 0){
		return 1;
	}

	for(i = val; i > 1 ; i--){
		f *= i  -1;
	}

	printf("Factorial %d is %d\n", val, f);

	return f;
}

unsigned int combonation(int n, int r){
	int numerator = 0;
	int denom = 1;
	
	printf("%d nCr %d\n", n, r);
	
	numerator = factorial(n);
	denom = factorial(r) * factorial(n - r);

	return numerator / denom;

}

int loopThroughCombos(int lowerBound, int upperBound){
	int i, k;
	int count = 0;

	for(i = lowerBound; i <= upperBound; i++){
		for(k = 1; k <= i; k++){
			if(combonation(i, k) > UPPER_LIMIT){
				count++;
			}
		}
	}

	return count;

}

int main() {
	int a, b, c, d;
	a = b = c = d = 0;
	#ifndef _OPENMP
		fprintf( stderr, "OpenMp is not supported");
		return 1;
	#endif

	#pragma omp parallel num_threads(4)
	#pragma omp single
		{
	#pragma omp task
	a = loopThroughCombos(1, 25);

	#pragma omp task
	b = loopThroughCombos(26, 50);

	#pragma omp task
	c = loopThroughCombos(51, 75);
	
	#pragma omp task
	d = loopThroughCombos(76,100);

	#pragma omp taskwait
		}

	printf("%d\n", a + b + c + d);
	

	return 0;
}
