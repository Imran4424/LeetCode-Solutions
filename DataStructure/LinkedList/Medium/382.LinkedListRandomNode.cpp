/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
	vector <int> values;
	int vSize;
public:
	Solution(ListNode* head) {
		values = vector<int>();

		while(NULL != head) {
			values.push_back(head->val);
			head = head -> next;
		}

		vSize = values.size();
	}

	int getRandom() {
		int index = rand() % vSize;
		return values[index];
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */