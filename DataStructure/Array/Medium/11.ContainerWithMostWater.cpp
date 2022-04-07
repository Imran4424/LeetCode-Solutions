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
		int heightSize = height.size();
		int verlength, currentArea;
		int maxWaterArea = 0;

		for (int i = 0; i < heightSize; i++) {
			for (int j = i + 1; j < heightSize; j++) {
				verlength = minValue(height[i], height[j]);
				currentArea = verlength * (j - i);

				if (currentArea > maxWaterArea) {
					maxWaterArea = currentArea;
				}
			}
		}

		return maxWaterArea;
	}
};

/*
	Brute force

	Time complexity - O(n^2)
	Space complexity - O(1)
	Result - TLE
*/