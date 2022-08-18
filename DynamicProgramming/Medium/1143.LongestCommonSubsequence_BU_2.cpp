
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


		int *previous = new int[textOne.size() + 1];



		for (int i = 0; i <= textOne.size(); i++) {
			previous[i] = 0;
		}

		for (int col = textTwo.size() - 1; col >= 0; col--) {

			int *current = new int[textOne.size() + 1];

			for (int row = textOne.size() - 1; row >= 0; row--) {
				if (textOne[row] == textTwo[col]) {
					current[i][j] = 1 + previous[row + 1];
				} else {
					current[i][j] = maxVal(previous[row], current[row + 1]);
				}
			}

			previous = current;
		}


		return previous[0];
	}
};