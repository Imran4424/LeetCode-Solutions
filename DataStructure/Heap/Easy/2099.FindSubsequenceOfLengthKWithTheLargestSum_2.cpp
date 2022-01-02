/*
	You are given an integer array nums and an integer k. You want to find a 
	subsequence of nums of length k that has the largest sum.

	Return any such subsequence as an integer array of length k.

	A subsequence is an array that can be derived from another array by deleting 
	some or no elements without changing the order of the remaining elements.

*/

class Solution {
	typedef pair<int, int> elementPair; 
	vector <elementPair> subArray;
	int kSize;

	void insertionSort(elementPair ePair) {
		int index = kSize - 1;
		int findPos = -1;

		while (index >= 0 && ePair.second > subArray[index].second) {
			findPos = index;
			index--;
		}

		if (-1 != findPos) {
			for (int i = kSize - 1; i > findPos; i--) {
				subArray[i] = subArray[i - 1];
			}

			subArray[findPos] = ePair;
		}
	}
	
public:
	vector<int> maxSubsequence(vector<int>& nums, int k) {
		kSize = k;
		subArray = vector <elementPair> (k, {0, INT_MIN});

		for (int i = 0; i < nums.size(); i++) {
			insertionSort({ i, nums[i] });
		}

		sort(subArray.begin(), subArray.end());

		vector <int> subSequenceArr;

		for (int i = 0 ; i < k; i++) {
			subSequenceArr.push_back(subArray[i].second);
		}


		return subSequenceArr;
	}
};