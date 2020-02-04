

char Stack[100001];
int frequency[100001];
int top;

void initStack() {
    top = 0;
}

bool isEmpty() {
    return 0 == top;
}

void push(char ch) {
    Stack[top] = ch;
    frequency[top] = 1;
    top++;
}

char pop() {
    return Stack[--top];
}


char * removeDuplicates(char * str, int target){
    initStack();
    
    for(int i = 0; str[i]; i++) {
        
        if(top > 0 && Stack[top - 1] == str[i]) {
            frequency[top - 1]++;
            
            if(target == frequency[top - 1]) {
                pop();
            }
        } else {
            push(str[i]);
        }
    }

    
    int src, des;

    for(src = des = 0; src < top; src++) {
        while(frequency[src] > 0) {
            str[des++] = Stack[src];
            frequency[src]--;
        }
    }

    str[des] = '\0';

    return str;
}