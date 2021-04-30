#include <stdio.h>

#define LARGENUM 600851475143

int main(){
	long long int largestFactor = LARGENUM - 1;

	for(largestFactor; largestFactor > 0; largestFactor--){
		if(LARGENUM % largestFactor == 0){
			printf("The largest factor of %lld is %lld\n", LARGENUM, largestFactor);
			return(0);
		}
	}

	printf("Something is messed up");

	return (0);
}
