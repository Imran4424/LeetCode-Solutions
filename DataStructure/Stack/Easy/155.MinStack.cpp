/*
	Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

	Implement the MinStack class:

	    MinStack() initializes the stack object.
	    void push(int val) pushes the element val onto the stack.
	    void pop() removes the element on the top of the stack.
	    int top() gets the top element of the stack.
	    int getMin() retrieves the minimum element in the stack.
*/

class MinStack {
    map<int, int> minElement;
    
    struct Node {
        int val;
        Node* next;
        
        Node() { }
        
        Node (int val) {
            this->val = val;
            next = NULL;
        }
    };
    
    Node* head;
    
public:
    MinStack() {
        minElement = map<int, int>();
        head = NULL;
    }
    
    void push(int val) {
        minElement[val]++;
        
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
    }
    
    void pop() {
        if (NULL == head) {
            return;
        }
        
        minElement[head->val]--;
        if (minElement[head->val]<= 0) {
            minElement.erase(head->val);
        }
        
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return minElement.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */