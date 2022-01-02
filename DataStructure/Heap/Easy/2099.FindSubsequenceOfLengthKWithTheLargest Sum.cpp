/*
	You are given an integer array nums and an integer k. You want to find a 
	subsequence of nums of length k that has the largest sum.

	Return any such subsequence as an integer array of length k.

	A subsequence is an array that can be derived from another array by deleting 
	some or no elements without changing the order of the remaining elements.

*/

class Solution {
	typedef pair<int, int> elementPair; 

	class FixedMinHeap {
		int size;
		priority_queue<elementPair, vector<elementPair>, greater<elementPair> > minHeap;
	public:
		FixedMinHeap(int size) {
			this->size = size;
		}

		void push(int val, int index) {
			if (minHeap.size() == size) {
				if (val < minHeap.top().first) {
					return;
				}

				minHeap.pop();
			}

			minHeap.push({ val, index });
		}

		elementPair top() {
			return minHeap.top();
		}

		void pop() {
			minHeap.pop();
		}

		bool isEmpty() {
			return minHeap.empty();
		}
	};
    
public:
	vector<int> maxSubsequence(vector<int>& nums, int k) {
		FixedMinHeap myMinHeap(k);

		for (int i = 0; i < nums.size(); i++) {
			myMinHeap.push(nums[i], i);
		}


		FixedMinHeap orderdHeap(k);

		while(!myMinHeap.isEmpty()) {
			elementPair hand = myMinHeap.top();
			orderdHeap.push(hand.second, hand.first);
			myMinHeap.pop();
		}


		vector <int> subArray;

		while(!orderdHeap.isEmpty()) {
			subArray.push_back(orderdHeap.top().second);
			orderdHeap.pop();
		}

		return subArray;
	}
};