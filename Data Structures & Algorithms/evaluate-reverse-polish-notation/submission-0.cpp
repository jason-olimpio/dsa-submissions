#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        stack<int> myStack;
        
        for (const std::string& c : tokens) {
            if (c == "+") {
                int a = myStack.top(); myStack.pop();
                int b = myStack.top(); myStack.pop();
                myStack.push(b + a);
            } else if (c == "-") {
                int a = myStack.top(); myStack.pop();
                int b = myStack.top(); myStack.pop();
                myStack.push(b - a);
            } else if (c == "*") {
                int a = myStack.top(); myStack.pop();
                int b = myStack.top(); myStack.pop();
                myStack.push(b * a);
            } else if (c == "/") {
                int a = myStack.top(); myStack.pop();
                int b = myStack.top(); myStack.pop();
                myStack.push(b / a);
            } else {
                myStack.push(stoi(c));
            }
        }

        return myStack.top();
    }
};