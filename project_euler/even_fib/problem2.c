#include <stdio.h>

int main(){
	int current = 2;
	int prev = 1;
	int sum = 0;
	int temp = 0;

	while(current < 4000000){
		if(current % 2 == 0){
			sum += current;
		}
		temp = current;
		current += prev;
		prev = temp;
	}

	printf("Sum of even fib under 4mill is %d\n",sum);

	return(0);
}
