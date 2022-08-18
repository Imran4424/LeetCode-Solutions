
class Solution {
	int maxVal(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

public:
	int longestCommonSubsequence(string textOne, string textTwo) {
		// always keep textOne shortest
		// if not swap them
		if (textTwo.size() < textOne.size()) {
			string temp = textOne;
			textOne = textTwo;
			textTwo = temp;
		}


		// previous column
		int *previous = new int[textOne.size() + 1];
		// current column
		int *current = new int[textOne.size() + 1];

		// intializing previous column
		for (int i = 0; i <= textOne.size(); i++) {
			previous[i] = 0;
		}

		for (int col = textTwo.size() - 1; col >= 0; col--) {
			for (int row = textOne.size() - 1; row >= 0; row--) {
				if (textOne[row] == textTwo[col]) {
					// previous row - previous, previous column - row + 1
					current[i][j] = 1 + previous[row + 1];
				} else {
					// previous row - row + 1, current column - current
					// current row - row, previous column - previous
					current[i][j] = maxVal(current[row + 1], previous[row]);
				}
			}

			previous = current;
		}


		return previous[0];
	}
};

/*
	If you don't understand, just look at solution animation and the equation of this solution and previous one

*/