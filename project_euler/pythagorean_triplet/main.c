#include <stdio.h>
#include <omp.h>
#include <stdbool.h>
#include <math.h>

#define SUMMATION 1000

bool isTriplet(int a, int b, int c){
	if( a > b){
		return false;
	} else if( b > c){
		return false;
	}

	if((pow(a, 2) + pow(b, 2)) == pow(c, 2)){
		return true;
	}

	return false;

}

void tripletCheck(int i, int j, int k){
	int product;
	if(isTriplet(i, j, k)){
		// printf("%d %d %d is a tripplet\n", i, j, k);
		if(i + j + k == SUMMATION){
			product = i * j * k;
			printf("The product of the tripplet summing %d is: %d\n", SUMMATION, product);
		}
	}
}



int main() {
	int i, ii, iii, iiii;
	int j, jj, jjj, jjjj;
	int k, kk, kkk, kkkk;
// Test Open MP
#ifndef _OPENMP
	fprintf( stderr, "OpenMp is not supported");
	return 1;
#endif

#pragma omp parallel num_threads(4)
#pragma omp single
	{
		
		#pragma omp task
		for(i = 1; i < 250; i++){
			for(j = 2; j < 1000; j ++){
				for(k = 3; k < 1000; k++){
					tripletCheck(i, j, k);
				}
			}
		}
		#pragma omp task
		for(ii = 250; ii < 500; ii++){
			for(jj = 251; jj < 1000; jj ++){
				for(kk = 252; kk < 1000; kk++){
					tripletCheck(ii, jj, kk);
				}
			}
		}
		#pragma omp task
		for(iii = 500; iii < 750; iii++){
			for(jjj = 501; jjj < 1000; jjj ++){
				for(kkk = 502; k < 1000; k++){
					tripletCheck(iii, jjj, kkk);
				}
			}
		}
		#pragma omp task
		for(iiii = 750; iiii < 1000; iiii++){
			for(jjjj = 751; jjjj < 1000; jjjj ++){
				for(kkkk = 752; kkkk < 1000; kkkk++){
					tripletCheck(iiii, jjjj, kkkk);
				}
			}
		}
		#pragma omp taskwait
	}
	return 0;
}
