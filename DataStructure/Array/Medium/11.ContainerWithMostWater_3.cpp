/*
	You are given an integer array height of length n. There are n vertical 
	lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

	Find two lines that together with the x-axis form a container, such that the 
	container contains the most water.

	Return the maximum amount of water a container can store.

	Notice that you may not slant the container.

*/

class Solution {
	int minValue(int x, int y) {
		if (x < y) {
			return x;
		}

		return y;
	}

public:
	int maxArea(vector<int>& height) {
		int currentArea;
		int maxWaterArea = 0;

		int left = 0, right = height.size() - 1;
		while (left < right) {
			currentArea = minValue(height[left], height[right]) * (right - left);

			if (currentArea > maxWaterArea) {
				maxWaterArea = currentArea;
			}

			if (height[left] < height[right]) {
				left++;
			} else {
				right--;
			}
		}

		return maxWaterArea;
	}
};

/*
	Two pointer

	Time complexity - O(n)
	Space complexity - O(1)
	Accepted
*/