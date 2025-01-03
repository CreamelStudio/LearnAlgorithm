#include <stdio.h>

int power(int x, int n) {
	if (n == 0) return 1;
	return x * power(x, n - 1);
}

int main() {
	printf("Power 5^3 = %d", power(5, 3));
}