// Find position of only set bit

int findPosition(int N) {
	int zeroAtEnd = __builtin_ctz(N);
	int onecount = __builtin_popcount(N);
	if (onecount == 0 || onecount > 1)
		return -1;
	return zeroAtEnd + 1;
}