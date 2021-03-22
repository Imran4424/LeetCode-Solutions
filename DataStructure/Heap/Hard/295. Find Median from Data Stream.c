


typedef struct {
	int dataList[100001];
	int index;
} MedianFinder;

/** initialize your data structure here. */

MedianFinder* medianFinderCreate() {
	MedianFinder *obj = malloc(sizeof(MedianFinder));
	obj -> index = 0;

	return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
	if (obj -> index == 0) {
		obj -> dataList[(obj -> index)++] = num;
		return;
	}
	
	int targetIndex = 0;
	for (; targetIndex < obj -> index; targetIndex++) {
		if ( num < obj -> dataList[targetIndex]) {
			break;
		}
	}

	for (int i = obj -> index - 1; i >= targetIndex; i--) {
		obj -> dataList[i + 1] = obj -> dataList[i];
	}

	obj -> dataList[targetIndex] = num;
	obj -> index++;
}

double medianFinderFindMedian(MedianFinder* obj) {
	int currentIndex = obj -> index - 1;

	double median;

	// current index even means
	// total number of variables are even
	if (currentIndex % 2 == 0) {
		median = (double) obj -> dataList[currentIndex / 2 ];
	} else {
		median = ((double) obj -> dataList[currentIndex / 2] + (double) obj -> dataList[currentIndex / 2 + 1]) / 2;
	}

	return median;
}

void medianFinderFree(MedianFinder* obj) {
	free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/