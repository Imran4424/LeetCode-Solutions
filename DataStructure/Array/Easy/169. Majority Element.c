
int currentSize;

typedef struct ElementCount
{
	int data;
	int count;
} ElementCount;

int elementIndex(ElementCount *elements, int target) {
	for(int i = 0; i < currentSize; i++) {
		if (target == elements[i].data) {
			return i;
		}
	}

	elements[currentSize].data = target;
	elements[currentSize].count = 0;

	return currentSize++;
}

int majorityElement(int* nums, int numsSize) {
	currentSize = 0;
	ElementCount elements[numsSize];
	int maximum = 0;
	int maxElement = -1;

	for(int i = 0; i < numsSize; i++) {
		int index = elementIndex(elements, nums[i]);

		elements[index].count++;

		if(elements[index].count > maximum) {
			maximum = elements[index].count;
			maxElement = nums[i];
		}
	}

	return maxElement;
}