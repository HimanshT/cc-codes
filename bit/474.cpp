// Bit Difference

int countBitsFlip(int a, int b) {

	a = a ^ b;
	return (__builtin_popcount(a));

}