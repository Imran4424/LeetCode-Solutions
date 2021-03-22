class MedianFinder {
	int dataList[100001];
	int index;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    	index = 0;
    }
    
    void addNum(int num) {
        if (0 == index) {
        	dataList[index] = num;
        }

        int targetIndex;

        for (targetIndex = 0; targetIndex < index; targetIndex++) {
        	if (num < dataList[targetIndex]) {
        		break;
        	}
        }

        for (int i = index - 1; i >= targetIndex; i--) {
        	dataList[i + 1] = dataList[i];
        }

        dataList[targetIndex] = num;
        index++;
    }
    
    double findMedian() {
        double median;
        int currentIndex = index - 1;

        // current index even means
	// total number of variables are even
        if (currentIndex % 2 == 0) {
        	median = (double) dataList[currentIndex / 2];
        } else {
        	median = ((double) dataList[currentIndex / 2] + (double) dataList[currentIndex / 2 + 1]) / 2;
        }

        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */