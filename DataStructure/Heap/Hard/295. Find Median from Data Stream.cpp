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
    }
    
    double findMedian() {
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */