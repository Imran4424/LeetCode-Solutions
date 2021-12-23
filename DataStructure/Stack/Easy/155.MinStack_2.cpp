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
    int minElement;
    
    struct Node {
        int val;
        int minVal;
        Node* next;
        
        Node() { }
        
        Node (int val, int minVal) {
            this->val = val;
            this->minVal = minVal;
            next = NULL;
        }
    };
    
    Node* head;
    
public:
    MinStack() {
        minElement = INT_MAX;
        head = NULL;
    }
    
    void push(int val) {
        if (val < minElement) {
            minElement = val;
        }        

        Node *temp = new Node(val, minElement);
        temp->next = head;
        head = temp;
    }
    
    void pop() {
        if (NULL == head) {
            return;
        }
        
        head = head->next;
        if (NULL == head) {
            minElement = INT_MAX;
        } else {
            minElement = head->minVal;
        }
        
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->minVal;
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