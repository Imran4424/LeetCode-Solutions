

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
	// the grand increment
	digits[digitsSize - 1]++;

	if (digits[digitsSize - 1] <= 9) {
		*returnSize = digitsSize;
		return digits;
	}

	bool allNine = true;
	for (int i = 0; i < digitsSize; i++) {
		if(9 != digits[i]) {
			allNine = false
			break;
		}
	}

	if (!allNine) {
		int carry = 0;
		for (int i = digitsSize - 1; i >= 0; i--) {
			digits[i] = digits[i] + carry;

			if (digits[i] > 9) {
				carry = digits[i] / 10;
				digits[i] = digits[i] % 10;
			} else {
				carry = 0;
			}
		}

		*returnSize = digitsSize;
		return digits;
	}

	int *newNumber = malloc((digitsSize + 1) * sizeof(int));
	int carry = 0;
	for (int i = digitsSize - 1; i >= 0; i--) {
		newNumber[i + 1] = digits[i] + carry;
		if(newNumber[i + 1] > 9) {
			carry = newNumber[i + 1] / 10;
			newNumber[i + 1] %= 10;
		} else {
			carry = 0;
		}
	}

	newNumber[0] = carry;

	*returnSize = digitsSize + 1;
	return newNumber;
}