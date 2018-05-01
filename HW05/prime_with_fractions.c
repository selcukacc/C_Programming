#include <stdio.h>
#include "sfrac.h"

int main() {
	int n;
	int i;
	
	i = 0;
	for(n = 1; i < 1000; n++) {
		if(isPrime(n)) {
			printf("%d-)%d\n", i+1, n);
			i++;
		}	
	}
	
	return 0;
}
