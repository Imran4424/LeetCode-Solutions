/*
	Given the root of a binary tree, return the average value of the nodes on 
	each level in the form of an array. Answers within 10-5 of the actual answer will be 
	accepted. 

	Input: root = [3,9,20,null,null,15,7]
	Output: [3.00000,14.50000,11.00000]
	
	Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and 
	on level 2 is 11.
	
	Hence return [3, 14.5, 11].	
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
	int treeDepth;
	double[] levelSum;
	int[] levelCount;

	void findDepth(TreeNode root, int currentDepth) {
		if (null == root) {
			return;
		}

		currentDepth++;

		if (null == root.left && null == root.right) {
			if (currentDepth > treeDepth) {
				treeDepth = currentDepth;
			}

			return;
		}

		findDepth(root.left, currentDepth);
		findDepth(root.right, currentDepth);
	}

	void findSum(TreeNode root, int index) {
		if (null == root) {
			return;
		}

		levelSum[index] += root.val;
		levelCount[index]++;
		index++;

		findSum(root.left, index);
		findSum(root.right, index);
	}

	void init() {
		for (int i = 0; i < treeDepth; i++) {
			levelSum[i] = 0.0;
			levelCount[i] = 0;
		}
	}

	public List<Double> averageOfLevels(TreeNode root) {
		treeDepth = 0;
		findDepth(root, 0);
		levelSum = new double[treeDepth];
		levelCount = new int[treeDepth];
		init();

		findSum(root, 0);

		List <Double> treeAverage = new ArrayList<>();

		for (int i = 0; i < treeDepth; i++) {
			treeAverage.add(levelSum[i] / levelCount[i]);
		}

		return treeAverage;
	}
}