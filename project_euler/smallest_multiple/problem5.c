#include <stdio.h>
#include <stdbool.h>

int main(){
	int i;
	int multiple = 1;

	for(i = 1; i <= 20; i++){
		if(multiple % i != 0){
			multiple++;
			i=1;
		}
	}	

	printf("The smallest multiple for 1 to 20 is %d\n", multiple);

	return(0);
}
