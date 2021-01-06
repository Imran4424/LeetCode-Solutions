

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
	for (int i = digitsSize - 1; i >= 0; i--) {
		// checking the current digit
		// if it's less than 9 then just increment and return it
		if (digits[i] < 9) {
			digits[i]++;
			*returnSize = digitsSize;
			return digits;
		}

		// if it's greater than 9 then simply assign 0
		// cause always remain will be zero and carry will be 1
		digits[i] = 0;
	}

	int *newNumber = malloc((digitsSize + 1) * sizeof(int));
	for(int i = 1; i <= digitsSize; i++) {
		newNumber[i] = 0;
	}
	newNumber[0] = 1;

	*returnSize = digitsSize + 1;
	return newNumber;
}



























