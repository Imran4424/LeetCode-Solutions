/*
	You are visiting a farm that has a single row of fruit trees arranged 
	from left to right. The trees are represented by an integer array 
	fruits where fruits[i] is the type of fruit the ith tree produces.

	You want to collect as much fruit as possible. However, the owner 
	has some strict rules that you must follow:

	You only have two baskets, and each basket can only hold a single 
	type of fruit. There is no limit on the amount of fruit each basket 
	can hold.
	
	Starting from any tree of your choice, you must pick exactly one 
	fruit from every tree (including the start tree) while moving to 
	the right. The picked fruits must fit in one of your baskets.
	Once you reach a tree with fruit that cannot fit in your baskets, 
	you must stop.

	Given the integer array fruits, return the maximum number of fruits 
	you can pick.

 

	Example 1:

	Input: fruits = [1,2,1]
	Output: 3
	Explanation: We can pick from all 3 trees.

	Example 2:

	Input: fruits = [0,1,2,2]
	Output: 3
	Explanation: We can pick from trees [1,2,2].
	If we had started at the first tree, we would only pick from trees [0,1].

	Example 3:

	Input: fruits = [1,2,3,2,2]
	Output: 4
	Explanation: We can pick from trees [2,3,2,2].
	If we had started at the first tree, we would only pick from trees [1,2].

	 

	Constraints:

	    1 <= fruits.length <= 105
	    0 <= fruits[i] < fruits.length

*/

class Solution {
	unordered_map <int, int> uniqueTree;
public:
	int totalFruit(vector<int>& fruits) {
		int maxWindow = 0;
		int currentWindow = 0;
		int index = 0;
		int lastIndex = 0;

		for (int i = 0; i < fruits.size(); i++) {
			lastIndex = i;

			uniqueTree[fruits[i]]++;

			if (uniqueTree.size() > 2) {
				break;
			}

			currentWindow++;
		}

		maxWindow = currentWindow;

		if (uniqueTree.size() <= 2) {
			// you found the solution now return it
			return maxWindow;
		}

		while(uniqueTree.size() > 2) {
			if (uniqueTree[fruits[index]] > 1) {
				uniqueTree[fruits[index++]]--;
			} else {
				uniqueTree.erase(fruits[index++]);
			}
			
			// but this logic currentWindow by 1 than the actual
			currentWindow--;
		}

		// so
		currentWindow++;
		
		for (int i = lastIndex; i < fruits.size(); i++) {
			// this is a nested loop but
			// it using sliding window technique
			lastIndex++;
			for (; lastIndex < fruits.size(); lastIndex++) {
				uniqueTree[fruits[lastIndex]]++;


				if (uniqueTree.size() > 2) {
					break;
				}

				currentWindow++;
			}

			if (currentWindow > maxWindow) {
				maxWindow = currentWindow;
			}

			while (uniqueTree.size() > 2) {
				if (uniqueTree[fruits[index]] > 1) {
					uniqueTree[fruits[index++]]--;
				} else {
					uniqueTree.erase(fruits[index++]);
				}
				
				// but this logic currentWindow by 1 than the actual
				currentWindow--;
			}

			// so
			currentWindow++;
			
			i = lastIndex;
		}

		return maxWindow;
	}
};