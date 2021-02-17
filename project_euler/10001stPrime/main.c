#include <stdio.h>
#include <stdbool.h>

#define PRIMECNT 10001

bool isPrime(unsigned int val){
	unsigned int i;

	if(val == 1){
		return false;
	}

	for(i = val - 1; i > 1; i--) {
		if(val % i == 0){
			return false;
		}
	}

	return true;
}

int main() {
	int ogcounter = PRIMECNT;
	int counter = PRIMECNT;
	unsigned int i = 2;

	while(counter > 0){
		if(isPrime(i)){
			//printf("%d is prime\n", i);
			counter--;
		}
		i++;
	}

	printf("The %d prime number value is %d\n", ogcounter, i - 1);

	return 0;
}
