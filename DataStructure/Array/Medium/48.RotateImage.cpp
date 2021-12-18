
/*
	You are given an n x n 2D matrix representing an image, rotate the 
	image by 90 degrees (clockwise).

	You have to rotate the image in-place, which means you have to modify the 
	input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

*/

class Solution {
	void transpose(vector<vector<int>>& matrix) {
		int n = matrix.size();

		// row
		for (int i = 0; i < n; i++) {
			// col
			for (int j = i + 1; j < n; j++) {
				// swapping
				// row to column
				// column to row
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
	}

	void relection(vector<vector<int>>& matrix) {
		int n = matrix.size();

		// row
		for (int i = 0; i < n; i++) {
			// col
			for (int j = 0; j < n / 2; j++) {
				// revering each column of matrix
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i][n - 1 - j];
				matrix[i][n - 1 - j] = temp;
			}
		}
	}

public:
	void rotate(vector<vector<int>>& matrix) {
		transpose(matrix);
		relection(matrix);
	}
};