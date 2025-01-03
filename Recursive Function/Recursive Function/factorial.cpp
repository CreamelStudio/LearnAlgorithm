#include <stdio.h>
#include <stdlib.h>
int result = 1;
int fact(int n) {
	if (n < 1) return result;
	result *= n;
	fact(n - 1);
}

int fact2(int n) {
	if (n == 1) return 1;
	return n * fact2(n - 1);
}

int main() {
	printf("5! = %d\n", fact(5));
	printf("5! = %d\n", fact2(5));
	return 0;
}