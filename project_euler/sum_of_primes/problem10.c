#include <stdio.h>
#include <stdbool.h>

#define ceiling 2000000 

bool isPrime(int val){ 
	int i = val - 1;
	if(val == 1){
		return false;
	}

	for(i; i > 1; i--){
		if(val % i == 0){
			return false;
		}
	}	

	return true;
}

int main(){
	int sum = 0;
	int i;

	for(i = 1; i < ceiling; i++){
		if(isPrime(i)){
			sum += i;
		}		
	}

	printf("The sum of all primes below %d is %d\n", ceiling, sum);

	return (0);
}
