// Time complexity : O(n) for getMin() and O(1) for other operations,
// space complexity : O(n) for getMin() and O(1) for other operations
class MinStack {
public:
    stack<int> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
       return stk.top();
    }
    
    int getMin() {
        stack<int> tmp;
        int mini = stk.top();
        while(stk.size()){
            mini = min(mini,stk.top());
            tmp.push(stk.top());
            stk.pop();
        }
        while(tmp.size()){
            stk.push(tmp.top());
            tmp.pop();
        }
        return mini;
    }
};

//Time Complexity: O(1) for all operations.
//space complexity: O(n) 
class MinStack {

public:
    stack<int> stk;
    stack<int> minStk;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        val = min(val,minStk.empty() ? val: minStk.top());
        minStk.push(val);
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
