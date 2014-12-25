/**
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    void push(int x) {
        elems_.push(x);
        /**
         * 当新 push() 的元素小于等于最小元素时就应该 push() 进最小元素栈，
         * 因为当有多个值相同的最小元素时，每一次元素的 pop() 都会对应最小元素栈的一次 pop()
        */
        if(min_stack_.empty() || min_stack_.top() >= x){
            min_stack_.push(x);
        }
    }

    void pop() {
        if(elems_.empty()) return;
        int x = elems_.top();
        elems_.pop();
        
        if(x == min_stack_.top())
            min_stack_.pop();
    }

    int top() {
        return elems_.top();
    }

    int getMin() {
        return min_stack_.top();
    }
    
private:
    stack<int> elems_;
    stack<int> min_stack_; // 最小元素栈。栈顶总是保存当前元素栈中的最小元素
};
