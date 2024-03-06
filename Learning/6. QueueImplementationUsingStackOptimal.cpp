
// Problem Link - https://leetcode.com/problems/implement-queue-using-stacks/

#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    stack<int> st1;
    stack<int> st2;
    int top = INT_MAX;

    void push(int num)
    {

        if (st1.empty())
        {
            top = num;
        }
        st1.push(num);
    }

    int pop()
    {

        if (!st2.empty())
        {
            int x = st2.top();
            st2.pop();
            return x;
        }

        // else ur stack2 is empty...therefore we transfer all elements from stack1 to stack2
        while (!st1.empty())
        {
            int x = st1.top();
            st1.pop();
            st2.push(x);
        }

        int y = st2.top();
        st2.pop();

        return y;
    }

    int front()
    {

        if (!st2.empty())
        {
            return st2.top();
        }

        if (top != INT_MAX)
        {
            return top;
        }

        // else we need to transfer all elements to stack2 from stack1
        while (!st1.empty())
        {
            int x = st1.top();
            st1.pop();
            st2.push(x);
        }

        return st2.top();
    }

    bool empty()
    {
        return (st1.empty() && st2.empty());
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