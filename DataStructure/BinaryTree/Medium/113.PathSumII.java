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
	int target;
	List <List<Integer>> paths = new ArrayList<List<Integer>>();

	private void findTargetPath(TreeNode root, int currentSum, ArrayList<Integer> path) {
		if (root == null) {
			return;
		}

		currentSum = currentSum + root.val;
		path.add(root.val);

		if (root.left == null && root.right == null) {
			if (currentSum == target) {
				paths.add(new ArrayList<>(path));
			}

			// removing cause java always handles object as reference type
			path.remove(path.size() - 1); // backtracking
			return;
		}

		findTargetPath(root.left, currentSum, path);
		findTargetPath(root.right, currentSum, path);

		// removing cause java always handles object as reference type
		path.remove(path.size() - 1); // backtracking
	}

	public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
		if (null == root) {
			return paths;
		}

		target = targetSum;
		findTargetPath(root, 0, new ArrayList<Integer>());

		return paths;
	}
}