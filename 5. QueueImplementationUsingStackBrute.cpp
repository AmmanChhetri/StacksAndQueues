
// Problem Link - https://leetcode.com/problems/implement-queue-using-stacks/

#include <bits/stdc++.h>
using namespace std;

// Logic -
// for push(num)..
// 1. Transfer all elements from stack1 to stack2.
// 2. Push num to stack1.
// 3. transfer all elements from stack2 to stack1.

// pop()
// pop from stack1.

class Queue
{
public:
    stack<int> st1;
    stack<int> st2;

    void push(int num)
    {
        // transfer all elements from stack1 to stack2
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }

        // push `num` in stack1.
        st1.push(num);

        // transfer all elements from stack2 to stack1
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop()
    {
        int y = st1.top();
        st1.pop();
        return y;
    }

    int front()
    {

        return st1.top();
    }

    bool empty()
    {
        // if stack1 is empty...my queue is empty...
        return st1.empty();
    }
};

int main()
{

    Queue q;
    q.push(100);
    q.push(122);
    q.push(145);
    q.push(1000);

    cout << q.pop() << endl;
    cout << "Current Front element : " << q.front() << endl;
    cout << "Is Empty : " << q.empty() << endl;
    return 0;
}